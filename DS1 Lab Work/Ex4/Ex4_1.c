#include <stdio.h>
#include <string.h>

void main(int argc,char *argv[]){
	FILE *fp1,*fp2;
	int i=0;
	char f1[40],f2[40];
	strcpy(f1,argv[1]);
	strcpy(f2,argv[2]);
	fp1=fopen(f1,"r");
	fp2=fopen(f2,"w");
	if(fp1 == NULL){
		printf("File Does not Exist");
	
	}	
	else{
		if(fp2!=NULL){
			int choice;
			printf("This File Exists, 1. Overwrite, 2.Append \n");
			scanf("%d",&choice);
			if(choice == 2){
				fseek(fp2,0,SEEK_END);
			}	
		}
		while (1){
			char a;
			a = fgetc(fp1);
			if (a==EOF){
				break;

			}
			else{
				putc(a,fp2);
			}

		}
	}
	fclose(fp1);
	fclose(fp2);
}
