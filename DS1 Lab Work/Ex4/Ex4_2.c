#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void main(int argc, char const *argv[]){
	FILE *f1;

	int n,i;
	f1 = fopen("phonebook.txt","a");
	n = atoi(argv[1]);
	for(i=0;i<n;i++){
		char name[80];
		int no;
		printf("Enter Name\n");
		fgets(name,80,stdin);
		printf("Enter Number\n");
		scanf("%d%*c",&no);
		fprintf(f1, "Name : %s, Phone : %d \n",name,no);
	}
	
}