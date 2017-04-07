#include <stdio.h>
#define N 10
typedef struct med{
	int medID;
	char name[50];
	char vendor[50];
	int manDate[2];
	int expDate[2];
	int price;
	int stock;
}med;

int check(med m[N], int a, int *size){
	int ll=0;
	int ul=*size-1;
	int retVal = -1;
	while(ul>=ll){
		int mid = (ul+ll)/2;
		if (m[mid].medID == a){
			retVal = mid;
			break;
		}
		else if(m[mid].medID > a){
			ll=mid+1;
		}
		else if(m[mid].medID < a){
			ul=mid-1;
		}
	}
	return retVal;
}

void insert(med m[N], med n, int *size){
	int i = *size-1;
	while(n.medID>m[i].medID && i>=0){
		m[i+1]=m[i];
		i--;
	}
	m[i+1]=n;
	*size += 1;
}

void input(med n[N], int *size){
	med m;
	int i;
	printf("Enter Details \n");
	
    printf("Enter the ID of the Medicine: ");
	scanf("%d%*c",&m.medID);
	printf("Enter Name of Medicine: ");
	scanf("%s%*c",m.name);
	printf("Enter Vendor of Medicine: ");
	scanf("%s%*c",m.vendor);	
	printf("Enter Price of Medicine: ");
	scanf("%d%*c",&m.price);
	printf("Enter Stock of Medicine: ");
	scanf("%d%*c",&m.stock);
	printf("Enter Date of Manufacure of Medicine as MM/YY: ");
	scanf("%d/%d%*c",&m.manDate[0],&m.manDate[1]);
	m.expDate[1] = m.manDate[1] + 1;
	m.expDate[0] = m.manDate[0]; 
	insert(n,m,size);
	
}


void buy(med m[N], int a, int *size){
	int index = check(m,a,size);	
	if(index!=-1){
		int n;	
		printf("How many to buy: \n");
		scanf("%d",&n);
		m[index].stock+=n;
		printf("%d medicines purchased\n",n);
	}
	else{
		printf("This medicine is not in the database: \n");
		input(m, size);
	}
	
}

void sell(med m[N], int a, int *size){
	int index = check(m,a,size);
	if(index!=-1 && m[index].stock > 0){
		int n;
		printf("How many to sell: \n");
		scanf("%d",&n);		
		if(n<=m[index].stock){
			m[index].stock-=n;
			printf("%d units sold\n",n);
		}
		else{
			printf("Insufficient Stock\n");
		}
		if(m[index].stock < 5){
			printf("WARNING : Only %d stock left.\n",m[index].stock);
		}
	}
	else{
		printf("That medicine is not available \n");
	}
}




void display(med m[N],int *size){
	int i;
	printf("Medicine ID\t Name\t\t Vendor\t\t Price\t Manufacture Date\t Expiry Date\tStock\n");
	for(i=0;i<*size;i++){
		printf("%11d  %8s  %16s %14d %15d/%d %13d/%d %8d\n",m[i].medID,m[i].name,m[i].vendor,m[i].price,m[i].manDate[0],m[i].manDate[1],m[i].expDate[0],m[i].expDate[1],m[i].stock);
	}
}


void main(){
	med m[N];
	int size=0,i,entry;
	printf("Enter how many Medicines\n");			
	scanf("%d",&entry);
	for(i=0;i<entry;i++){
		input(m,&size);

	}
	int choice = 1;
	int query=0;
	while(choice!=0){	
		printf("1.Buy\n2.Sell\n3.Check Availability\n4.Display\n0.Exit\n");
		scanf("%d",&choice);
		switch (choice){
			case 1:
				printf("Enter ID of Medicine to Purchase\n");
				scanf("%d",&query);
				buy(m,query,&size);
				break;
			case 2:
				printf("Enter ID of Medicine to Sell\n");
				scanf("%d",&query);
				printf("%d",query);
				sell(m,query,&size);
				break;
			case 3:
				printf("Enter ID of Medicine to Check\n");
				scanf("%d",&query);
				printf("There is %d stock left\n",m[check(m,query,&size)].stock);
				break;
			case 4:
				display(m,&size);
				break;
		}

	}
}

