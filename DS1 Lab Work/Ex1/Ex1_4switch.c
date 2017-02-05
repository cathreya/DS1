#include <stdio.h>
#include <string.h>
void main(){
	int entry=1,select,quant=1,choice;
	long int sum=0;
	char grocery[3][3][30]={{"Apple","Orange","Grape"},{"Laptop","Smartphone","Camera"},{"Soap","Lotion","Cream"}};
	int prices[3][3]={{10,20,30},{50000,20000,100000},{200,1200,3000}};
	while (entry==1){
		printf("1. Fruits, 2. Electronics, 3. Cosmetics\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("1. Apple , 2. Orange, 3. Grape: ");	
			    	scanf("%d",&select);
				switch(select){
					case 1:
						printf("How Many: ");	
			    			scanf("%d",&quant);
						sum+=quant*prices[0][0];		
						break;
					case 2:
						printf("How Many: ");	
			    			scanf("%d",&quant);
						sum+=quant*prices[0][1];
						break;
					case 3:
						printf("How Many: ");	
			    			scanf("%d",&quant);
						sum+=quant*prices[0][2];
						break;
				}
				break;
			case 2:
				printf("1. Laptop , 2. Smartphone, 3. Camera: ");	
			    	scanf("%d",&select);
				switch(select){
					case 1:
						printf("How Many: ");	
			    			scanf("%d",&quant);
						sum+=quant*prices[1][0];		
						break;
					case 2:
						printf("How Many: ");
			    			scanf("%d",&quant);
						sum+=quant*prices[1][1];
						break;
					case 3:
						printf("How Many: ");	
			    			scanf("%d",&quant);
						sum+=quant*prices[1][2];
						break;
				}
				break;
			case 3:
				printf("1. Soap , 2. Lotion, 3. Cream");
			    	scanf("%d",&select);
				switch(select){
					case 1:
						printf("How Many: ");	
			    			scanf("%d",&quant);
						sum+=quant*prices[2][0];		
						break;
					case 2:
						printf("How Many: ");	
			    			scanf("%d",&quant);
						sum+=quant*prices[2][1];
						break;
					case 3:
						printf("How Many: ");	
			    			scanf("%d",&quant);
						sum+=quant*prices[2][2];
						break;
				}
				break;
		}
		printf("1. Continue 2.Checkout");
		scanf("%d",&entry);
	}
	printf("Your Total Amount is : %ld\n",sum);

}
