#include <stdio.h>

int sum(int n){
	int sum=0;
	while (n!=0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}

int sumrec(int n){
	if (n==0){
		return 0;
	}
	else{
		return ((n%10) + sumrec(n/10));
	}
}


void main(){
	int n;
	printf("Enter Number\n");
	scanf("%5d",&n);
	printf("Sum of Digits Calculated without Recursion: %d \nSum of Digits Calculated with Recursion: %d\n",sum(n),sumrec(n));
}
