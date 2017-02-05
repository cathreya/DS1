#include <stdio.h>
#define N 5
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
	int ul=*size;
	int retVal = -1;
	while(ul>=ll){
		int mid = (ul+ll)/2;
		if (m[mid].medID == a){
			retVal = mid;
		}
		else if(m[mid].medID > a){
			ul=mid-1;
		}
		else if(m[mid].medID < a){
			ll=mid+1;
		}
	}
	return retVal;
}

void insert(med m[N], med n, int *size){
	int i = *size;
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
	fgets(m.name,49,stdin);
	printf("Enter Vendor of Medicine: ");
	fgets(m.vendor,49,stdin);	
	printf("Enter Price of Medicine: ");
	scanf("%d",&m.price);
	printf("Enter Stock of Medicine: ");
	scanf("%d",&m.stock);
	printf("Enter Month of Manufacure of Medicine: ");
	scanf("%d",&m.manDate[0]);
	printf("Enter Year of Manufacure of Medicine: ");
	scanf("%d",&m.manDate[1]);
	m.expDate[1] = m.manDate[1] + 1;
	m.expDate[0] = m.manDate[0]; 
	insert(n,m,size);
	
}


void buy(med m[N], int a, int *size){
	int index = check(m,a,size);	
	if(index!=-1){
		int n;	
		printf("How many to buy: ");
		scanf("%d",&n);
		m[index].stock+=n;
	}
	else{
		printf("This medicine is not in the database: \n");
		input(m, size);
	}
	
}

void sell(med m[N], int a, int *size){
	int index = check(m,a,size);
	if(index!=-1 && m[index].stock > 0){
		m[index].stock-=1;
		if(m[index].stock < 5){
			printf("WARNING : Only %d stock left.",m[index].stock);
		}
	}
	else{
		printf("That medicine is not available ");
	}
}




void display(med m[N],int *size){
	int i;
	printf("Medicine ID\tName\tVendor\tPrice\tManufacture Date\tExpiry Date\tStock\n");
	for(i=0;i<*size;i++){
		printf("%d\t %s\t %s\t %d\t %d/%d\t %d/%d\t %d\t\n",m[i].medID,m[i].name,m[i].vendor,m[i].price,m[i].manDate[0],m[i].manDate[1],m[i].expDate[0],m[i].expDate[1],m[i].stock);
	}
}


void main(){
	med m[N];
	int size,i,entry;
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
				printf("%d",check(m,query,&size));
				break;
			case 4:
				display(m,&size);
				break;
		}

	}
}

