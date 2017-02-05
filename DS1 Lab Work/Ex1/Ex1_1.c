#include<stdio.h>
void main(){
	float amt=0,final;
	int disc=0;
	do{
	printf("Enter Total Amount(Non Negative): ");
	scanf("%f",&amt);
	}
	while(amt<0);
	if(amt>15000){
		disc=5;
		if(amt>=20000){
			disc=10;
			if(amt>=30000){
				disc=15;
				if(amt>=40000){
					disc=20;
		
				}		
			}
		}
	}	
	final=amt-(amt*disc/100);
	printf("Congrats you recieved a Discount of %d \%\n",disc);
	printf("Final Amount after Discount is : %0.2f\n",final);
}
