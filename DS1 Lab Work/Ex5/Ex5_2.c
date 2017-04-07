#include <stdio.h>
#include "doublylinked.h"

void main(){
	int choice =1;	
	nxtptr head = createHead();
	createn(5,head);
	display(head);
	char n[200];
	
	while(choice!=0){
		printf("1.Insert, 2.Search, 3.Delete, 4. Display, 5.Display Previous and Next \n");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter Name to insert after: ");
				scanf("%s",&n);
				insert(find(n,head),head); break;
			case 2: printf("Enter Name to search for: ");
				scanf("%s",&n);
				if(find(n,head)){
					printf("It is found at address %p\n",find(n,head));
				}
				else{
					printf("Not Found\n");
				}
				break;
			case 3: printf("Enter Name to Delete: ");
				scanf("%s",&n);
				delete(n,head); break;
			case 4: display(head); break;
			case 5: printf("Enter Name to display neighbouring elements: ");
				scanf("%s",&n);
				displayPN(n,head);break;

				
				
		}
	}
}
