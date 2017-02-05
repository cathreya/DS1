#include <stdio.h>
#define N 2 

typedef struct table{
	char city[N][50];
	int year[N];
	int lit[N][N];
}table;

int find(table a,int n){
	int i;
	for (i=0;i<N;i++){
		if(n==a.year[i]) return i;
	}
}



void fn1(table a,int m, int n){
	n=find(a,n);
	printf("Literacy Rate of %s in the year %d is : %d",a.city[m],a.year[n],a.lit[m][n]);

}

void fn2(table a,int n){
	n=find(a,n);
	int max=0;
	int i;
	for (i=0;i<N;i++){
		if (a.lit[i][n]>a.lit[max][n]){
			max=i;
		}
	}				

	printf("In the Year %d, %s had the highest literacy rate of %d out of all other cities",a.year[n],a.city[max],a.lit[max][n]);

}

void fn3(table a,int n){
	n=find(a,n);
	int min=0;
	int i;
	for (i=0;i<N;i++){
		if (a.lit[i][n]<a.lit[min][n]){
			min=i;
		}
	}				

	printf("In the Year %d, %s had the lowest literacy rate of %d out of all other cities",a.year[n],a.city[min],a.lit[min][n]);

}
void fn4(table a, int m){

	int i;
	float sum=0;
	for (i=0;i<N;i++){
		sum+=a.lit[m][i];
	}
	sum/=N;
	printf("The average literacy rate in %s over the last 10 years is: %.2f",a.city[m],sum);
}

void fn5(table a){
	int i,j;
	for (i=0;i<N;i++){
		printf("\t%5d",a.year[i]);
	}
	printf("\n");
	for (i=0;i<N;i++){
		printf("%s",a.city[i]);
		for(j=0;j<N;j++){
			printf("\t%5d",a.lit[i][j]);
		}
		printf("\n");
	}				
}







void main(){
	table litTable;
	int i,j,entry=1;
	int m,n;
	for (i=0;i<N;i++){
		printf("Enter City %d: ",i+1);
		scanf("%s",&litTable.city[i]);
	}
	for (i=0;i<N;i++){
		printf("Enter Year %d: ",i+1);
		scanf("%d",&litTable.year[i]);
	}
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
		printf("Enter Literacy Rate of %s in the year %d: ",litTable.city[i],litTable.year[j]);
		scanf("%d",&litTable.lit[i][j]);
		}
	}
	while(entry!=0){
		printf("\n1.Find the literacy percentage in m city in n year\n2. Find which city has the highest number of literate people in any year\n3. Find which city has the lowest number of literate people in any year\n4. Find the average of literate people in any city for N years\n5. Display the entire data\n");
		scanf("%d",&entry);
		switch (entry){
			case 1:
				printf("Enter City Number and Year: ");
				scanf("%d %d",&m,&n);
				fn1(litTable,m-1,n);
				break;
			case 2:
				printf("Enter Year: ");
				scanf("%d",&n);
				fn2(litTable,n);
				break;
			case 3:
				printf("Enter Year: ");
				scanf("%d",&n);
				fn3(litTable,n);
				break;
			case 4:
				printf("Enter City Number: ");	
				scanf("%d",&m);
				fn4(litTable,m-1);	
				break;
			case 5:
				fn5(litTable);
				break;

		} 
	}
}
