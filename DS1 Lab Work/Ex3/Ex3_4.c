#include <stdio.h>
#define N 5
typedef struct phone{
	int landLine;
	int mobile;
	char firstName[40];
	char lastName[40];
}phone;

void add(phone m[N],phone n, int *size){
	int i;
	i=*size-1;
	while(m[i].mobile>n.mobile && i>=0){
		m[i+1]=m[i];
		i--;
	}
	m[i+1]=n;
	*size+=1;
}

void input(phone m[N], int *size){
	phone n;
	printf("Enter First Name: ");
	fgets(n.firstName,40,stdin);	
	printf("Enter Last Name: ");
	fgets(n.lastName,40,stdin);
	printf("Enter Land Line: ");
	scanf("%d%*c",&n.landLine);
	printf("Enter Mobile: ");
	scanf("%d%*c",&n.mobile);

	add(m,n,size);
}

int search(phone m[N],int n, int *size){
	int ll = 0;
	int ul; 
	ul = *size;
	int retVal = -1;
	while(ul>=ll){
		int mid = (ul+ll)/2;
		if(m[mid].mobile == n){
			retVal=mid;
			break;
		}
		else if(m[mid].mobile < n){
			ll=mid+1;
		}
		else{
			ul=mid-1;
		}
	}
	return retVal;
}

void delete(phone m[N],int n, int *size){
	n = search(m,n,size);
	int i;
	if(n!=-1){
		for(i=n;i<*size;i++){
			m[i]=m[i+1];
		}
		*size-=1;
		printf("Deleted\n");
	}
	else{
		printf("Does Not Exist\n");
	}
}


void modify(phone m[N],int n, int *size){
	delete(m,n,size);
	input(m,size);
}

void display(phone m[N], int *size){
	int i;
	for(i=0;i<*size;i++){
		printf("%s %s\t : %d\t %d\t \n",m[i].firstName,m[i].lastName,m[i].landLine,m[i].mobile); 
	}
}

void main(){
	phone phoneBook[N];
	void (*input_ptr)(phone [N],int *) = &input;
	void (*del_ptr)(phone [N],int,int *) = &delete;
	void (*mod_ptr)(phone [N],int,int *) = &modify;
	void (*disp_ptr)(phone [N],int *) = &display;
	int choice=1,i=0,size=0,length=0;
	printf("How many entries: ");
	scanf("%d%*c",&length);
	for(i=0;i<length;i++){
		(*input_ptr)(phoneBook,&size);
	}	
	int q=0;
	while(choice!=0){
		printf("1. Add, 2. Delete, 3. Modify, 4. Display: ");
		scanf("%d%*c",&choice);
		switch (choice){
			case 1:
				(*input_ptr)(phoneBook,&size);
				break;

			case 2:	
				printf("Enter Mobile Number to Delete: ");
				scanf("%d%*c",&q);
				(*del_ptr)(phoneBook,q,&size);
				break;
			case 3:
				printf("Enter Mobile Number to Modify: ");
				scanf("%d%*c",&q);
				(*mod_ptr)(phoneBook,q,&size);
				break;
			case 4:
				(*disp_ptr)(phoneBook,&size);
				break;
		}

	}
	
	
}
