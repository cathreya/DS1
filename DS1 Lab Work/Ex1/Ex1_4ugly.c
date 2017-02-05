#include <stdio.h>
#include <string.h>
void main(){
	char grocery[3][3][30]={{"Apple","Orange","Grape"},{"Laptop","Smartphone","Camera"},{"Soap","Lotion","Cream"}};
	int prices[3][3]={{10,20,30},{50000,20000,100000},{2000,1200,3000}};
	char cart[10][30];
	int cartprice[10];
	int quantity[10];
	int i,choice, counter=0,entry=1,select,sum=0;
	while (entry==1){
		printf("1. Fruits, 2. Electronics, 3. Cosmetics\n");
		scanf("%d",&choice);
    	for(i=0;i<3;i++){
    		printf("%d to add %s to Cart\n",i+1,grocery[choice-1][i]);
    	}
    	scanf("%d",&select);
    	strcpy(cart[counter],grocery[choice-1][select-1]);
    	cartprice[counter]=prices[choice-1][select-1];
    	printf("How Many?: ");
    	scanf("%d",&quantity[counter]);
    	counter++;
    	printf("Press 1. Continue 2. Checkout \n");
    	scanf("%d",&entry);

	}
	for(i=0;i<counter;i++){
		printf("Item : %s\n",cart[i]);
		printf("  Price: %d\n",cartprice[i]);
		printf("  Quantity: %d\n",quantity[i]);
		sum+=cartprice[i]*quantity[i];

	}
	printf("Total Amount : %d\n",sum);
	
}
