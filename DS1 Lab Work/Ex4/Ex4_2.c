#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>


void main(int argc, char const *argv[]){
	FILE *f1;

	int n,i;
	f1 = fopen("phonebook.txt","a+");
	if(argc>1){
		n = atoi(argv[1]);

		for(i=0;i<n;i++){
			char name[80];
			int no;
			printf("Enter Name\n");
			scanf("%s",name);
			printf("Enter Number\n");
			scanf("%d%*c",&no);
			fprintf(f1, "%d %s\n",no,name);
		}
	}
	char query[80];
	char line[400];
	int flag = 0;
	printf("Enter Name to Search for\n");
	scanf("%s",query);
	rewind(f1);
	while(!feof(f1)){
		fgets(line,400,f1);
		//printf("%s\n",line );
		if(strstr(line,query)){
			printf("Phone Number Found : %s\n",line );
			flag = 1;
			break;
		}

	}
	if(flag == 0){	
		printf("Not Found\n");
	}
	fclose(f1);
}