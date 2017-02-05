#include <stdio.h>

int fibo(int n, int *a){
	*a+=1;
	if (n<=1){
		return n;
	}
	else{
		
		return fibo(n-2,a)+fibo(n-1,a);
	}
}

void main(){
	int n,i,a;
	int count=0;
	int garbage;
	printf("Enter N\n");
	scanf("%d",&n);
	for(i=0;fibo(i,&garbage)<n;i++){
		printf("%d ",fibo(i,&count));
	}
	printf("\nThe function was called %d times\n",count);
}
