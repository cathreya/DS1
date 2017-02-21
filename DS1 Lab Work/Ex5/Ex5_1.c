#include <stdio.h>
#include "singlylinked.h"

void main(){
	int choice =1;	
	nxtptr head = createHead();
	createn(5,head);
	display(head);
	int n;
	while(choice!=0){
		printf("1.Add in Front, 2.Add at End, 3.Add after a given Element, 4.Delete, 5. Count Occurences, 6.Display, 7.Size 0.Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: insertStart(head); break;
			case 2: insertEnd(head); break;
			case 3: printf("Enter Number after which to add: ");
				scanf("%d",&n);
				insert(find(n,head),head); break;
			case 4: printf("Enter Number to Delete: ");
				scanf("%d",&n);
				delete(n,head); break;
			case 5: printf("Enter Number to Count Occurences: ");
				scanf("%d",&n);
				countOccurence(n,head); break;
			case 6: display(head); break;
			case 7: printf("Size of List is %d\n",size(head));

				
				
		}
	}
}
