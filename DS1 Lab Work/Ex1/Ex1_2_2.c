#include <stdio.h>
void main(){
	int choice, balance = 500, change;
	while(balance>=0 && choice!=0){
		printf("Current Balance is %d\n",balance);
		printf("Enter 1. To Deposit, 2. To Withdraw, 0. To Exit\n");
		scanf("%d",&choice);
		switch (choice){
			case 1:
				printf("Enter Amount to Deposit\n");
				scanf("%d",&change);
				balance+=change;
				break;
			case 2:
				printf("Enter Amount to Withdraw\n");
				scanf("%d",&change);
				if (balance-change<0){
					printf("Insufficient Balance in Account\n");
					printf("This Transaction Cannot be Performed. \n");
					choice=0;	
					break;
				}
				else{
					balance-=change;
				}
				break;

		}				
	}
}
