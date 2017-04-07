#include <stdio.h>
#include <stdlib.h>
#include "linkedstackadt.h"

void main(){
	ptr stack1 = createHead();
	int choice=1;
	int a;
	while(choice!=0){
		printf("1. Push, 2.Pop, 3.Return Top, 4.Display, 5.Dispose: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				
				scanf("%d",&a);
				push(a,stack1);
				break;
			case 2:
				pop(stack1);
				break;
			case 3:
				printf("%d\n",retTop(stack1));
				break;

			case 4:
				display(stack1);
				break;
			case 5:
				dispose(stack1);
				choice=0;
				break;
		}
	}
}
