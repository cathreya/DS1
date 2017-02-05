#include <stdio.h>
void triangle();
void main(){
	int row,current;
	for(row=1;row<=6;row++){
		for(current=row;current<(2*row);current++){
			printf("%d ",current);
		}
		printf("\n");
	}
	triangle();
}

void triangle(){
	int row,space,current;
	for(row=1;row<=6;row++){
		for(space=0;space<(6-row);space++){
			printf("  ");
		}
		for(current=1;current<(2*row);current++){
			if(current<=row){
				printf("%d ",current);
			}
			else{
				printf("%d ",(2*row)-current);
			}
		}
		printf("\n");
	}	
}