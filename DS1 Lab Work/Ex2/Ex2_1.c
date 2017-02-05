#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float mean(int *a, int n){
	int sum=0,i;
	for (i=0;i<n;i++){
		sum+=*(a+i);
	}
	return sum/n;
}
void inssort(int *a, int n){
	int i,j,tmp;
	for(i=1;i<n;i++){
		j=i-1;
		tmp=*(a+i);
		while(*(a+j)>tmp && j>=0){
			*(a+j+1)=*(a+j);
			j--;
		}
		*(a+j+1)=tmp;
	}
	for(i=0;i<n;i++){
		printf("%d ",*(a+i));
	}
}

int median(int *a, int n){
	inssort(a,n);
	int mid = (n-1)/2;
	return *(a+mid);

}
void delete(int *a,int *n,int k){
	int i;
	
	for(i=k;i<*n;i++){
		a[i]=a[i+1];	
	}
	*n-=1;
}	

void makeUnique(int *a,int *n){
	int i,j;
	for (i=0;i<*n;i++){
		for (j=i+1;j<*n;j++){
			if(*(a+i)==*(a+j)){
				i--;
				delete(a,n,j);
			}
		}
	}	
	
}

int mode(int *a, int *n){
	int counter,max=0,index=0,i,j;
	for (i=0;i<*n;i++){
		counter = 0;
		for (j=0;j<*n;j++){
			if(*(a+i)==*(a+j)){
				counter ++;
			}
		}
		if (counter>max){
			max = counter ;
			index = i;
		}
	}
	return *(a+index);
}

int range(int *a , int n){
	int max=0,min=0;
	int i;

	for(i=1;i<n;i++){
		if(*(a+max)<*(a+i)){
			max=i;
		}
		if(*(a+min)>*(a+i)){
			min=i;
		}
	}
	return *(a+max)-*(a+min);
}

float variance(int *a, int n){
	float term1=0;
	int i;
	for (i=0;i<n;i++){
		term1+=*(a+i) * *(a+i);

	}
	term1/=n;
	return term1 - (mean(a,n)*mean(a,n));

}

float stdDev(int *a, int n){
	return sqrt(variance(a,n));
}










void main(){
	int n=0,i;
	printf("Enter Number of Elements\n");
	int *a = (int *)malloc(sizeof(int)*n);
	int *u = (int *)malloc(sizeof(int)*n);
	scanf("%d",&n);
	printf("Enter the Elements\n");
	for(i=0;i<n;i++){
		scanf("%d",a+i);
		u[i]=a[i];
	}
	int entry=1;
	makeUnique(a,&n);
	printf("After Removing Repeating Elements:\n");
	for (i=0;i<n;i++){
		printf ("%d ",a[i]);
	}
	while (entry!=0){
		printf("\n1.Mean, 2.Median, 3.Mode, 4.Variance, 5. Standard Deviation, 6,Range 0.Exit\n");
		scanf("%d",&entry);
		switch (entry){
			case 1:
				printf("Mean of the Distribution is: %f\n",mean(a,n) );			
				break;
			case 2:
				printf("Median of the Distribution is: %d\n",median(a,n) );			
				break;
			case 3:
				printf("Mode of the Distribution is: %d\n",mode(u,&n) );			
				break;
			case 4:
				printf("Variance of the Distribution is: %f\n",variance(a,n) );
				break;			
			case 5:
				printf("Standard Deviation of the Distribution is: %f\n",stdDev(a,n) );
				break;	
			case 6:
				printf("Range of the distribution is: %d\n",range(a,n) );
				break;	
		}	
	}
	
}

