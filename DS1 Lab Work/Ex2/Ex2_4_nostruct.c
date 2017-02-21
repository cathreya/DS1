#include <stdio.h>
#define N 5 



int find(int year[N], int n){
	int i;
	for (i=0;i<N;i++){
		if(n== year[i]) return i;
	}
}



void fn1(char city[N][50], int year[N], int lit[N][N],int m, int n){
	n=find(year,n);
	printf("Literacy Rate of %s in the year %d is : %d", city[m], year[n], lit[m][n]);

}

void fn2(char city[N][50], int year[N], int lit[N][N],int n){
	n=find(year,n);
	int max=0;
	int i;
	for (i=0;i<N;i++){
		if ( lit[i][n]> lit[max][n]){
			max=i;
		}
	}				

	printf("In the Year %d, %s had the highest literacy rate of %d out of all other cities", year[n], city[max], lit[max][n]);

}

void fn3(char city[N][50], int year[N], int lit[N][N],int n){
	n=find(year,n);
	int min=0;
	int i;
	for (i=0;i<N;i++){
		if ( lit[i][n]< lit[min][n]){
			min=i;
		}
	}				

	printf("In the Year %d, %s had the lowest literacy rate of %d out of all other cities", year[n], city[min], lit[min][n]);

}
void fn4(char city[N][50], int year[N], int lit[N][N], int m){

	int i;
	float sum=0;
	for (i=0;i<N;i++){
		sum+= lit[m][i];
	}
	sum/=N;
	printf("The average literacy rate in %s over the last 10 years is: %.2f", city[m],sum);
}

void fn5(char city[N][50], int year[N], int lit[N][N]){
	int i,j;
	for (i=0;i<N;i++){
		printf("\t\t%5d", year[i]);
	}
	printf("\n");
	for (i=0;i<N;i++){
		printf("%s", city[i]);
		for(j=0;j<N;j++){
			printf("\t\t%5d", lit[i][j]);
		}
		printf("\n");
	}				
}







void main(){
	char city[N][50];
	int year[N];
	int lit[N][N];
	int i,j,entry=1;
	int m,n;
	for (i=0;i<N;i++){
		printf("Enter City %d: ",i+1);
		scanf("%s",&city[i]);
	}
	for (i=0;i<N;i++){
		printf("Enter Year %d: ",i+1);
		scanf("%d",&year[i]);
	}
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
		printf("Enter Literacy Rate of %s in the year %d: ",city[i],year[j]);
		scanf("%d",&lit[i][j]);
		}
	}
	while(entry!=0){
		printf("\n1.Find the literacy percentage in m city in n year\n2. Find which city has the highest number of literate people in any year\n3. Find which city has the lowest number of literate people in any year\n4. Find the average of literate people in any city for N years\n5. Display the entire data\n");
		scanf("%d",&entry);
		switch (entry){
			case 1:
				printf("Enter City Number and Year: ");
				scanf("%d %d",&m,&n);
				fn1(city,  year, lit,m-1,n);
				break;
			case 2:
				printf("Enter Year: ");
				scanf("%d",&n);
				fn2(city,  year, lit,n);
				break;
			case 3:
				printf("Enter Year: ");
				scanf("%d",&n);
				fn3(city,  year, lit,n);
				break;
			case 4:
				printf("Enter City Number: ");	
				scanf("%d",&m);
				fn4(city,  year, lit,m-1);	
				break;
			case 5:
				fn5(city,  year, lit);
				break;

		} 
	}
}
