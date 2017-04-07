#include <stdio.h>
#define N 5
typedef struct phone{
	long int landLine;
	long int mobile;
	char firstName[40];
	char lastName[40];
}phone;

void add(phone m[N],phone n, long int *size){
	long int i;
	i=*size-1;
	while(m[i].mobile>n.mobile && i>=0){
		m[i+1]=m[i];
		i--;
	}
	m[i+1]=n;
	*size+=1;
}

void input(phone m[N], long int *size){
	phone n;
	printf("Enter Name in the Format FN LN: ");
	scanf("%s %s",n.firstName,n.lastName);
	printf("Enter Land Line: ");
	scanf("%8ld%*c",&n.landLine);
	printf("Enter Mobile: ");
	scanf("%10ld%*c",&n.mobile);

	add(m,n,size);
}

long int search(phone m[N],long int n, long int *size){
	long int ll = 0;
	long int ul; 
	ul = *size;
	long int retVal = -1;
	while(ul>=ll){
		long int mid = (ul+ll)/2;
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

void delete(phone m[N],long int n, long int *size){
	n = search(m,n,size);
	long int i;
	if(n!=-1){
		for(i=n;i<*size;i++){
			m[i]=m[i+1];
		}
		*size-=1;
		
	}
	else{
		printf("Does Not Exist\n");
	}
}


void modify(phone m[N],long int n, long int *size){
	delete(m,n,size);
	input(m,size);
}

void display(phone m[N], long int *size){
	long int i;
	printf("\n");
	for(i=0;i<*size;i++){
		printf("%ld. Name: %s %s   Land Line: %ld   Mobile: %ld\n",i+1,m[i].firstName,m[i].lastName,m[i].landLine,m[i].mobile); 
	}
	printf("\n");
}

void main(){
	phone phoneBook[N];
	void (*input_ptr)(phone [N],long int *) = &input;
	void (*del_ptr)(phone [N],long int,long int *) = &delete;
	void (*mod_ptr)(phone [N],long int,long int *) = &modify;
	void (*disp_ptr)(phone [N],long int *) = &display;
	long int choice=1,i=0,size=0,length=0;
	printf("How many entries: ");
	scanf("%ld%*c",&length);
	for(i=0;i<length;i++){
		(*input_ptr)(phoneBook,&size);
	}	
	long int q=0;
	while(choice!=0){
		printf("1. Add, 2. Delete, 3. Modify, 4. Display: ");
		scanf("%ld%*c",&choice);
		switch (choice){
			case 1:
				(*input_ptr)(phoneBook,&size);
				break;

			case 2:	
				printf("Enter Mobile Number to Delete: ");
				scanf("%ld%*c",&q);
				(*del_ptr)(phoneBook,q,&size);
				break;
			case 3:
				printf("Enter Mobile Number to Modify: ");
				scanf("%ld%*c",&q);
				(*mod_ptr)(phoneBook,q,&size);
				break;
			case 4:
				(*disp_ptr)(phoneBook,&size);
				break;
		}

	}
	
	
}
