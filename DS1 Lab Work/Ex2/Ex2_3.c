#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void caesarcipher(char *str){
	int i=0,b;
	while(*(str+i)!='\0'){
		if (*(str+i)==' ' || *(str+i)=='\n'){
			i++;
			continue;
		}
		b=*(str+i);
		b+=3;
		if (b>122){
			b=97+(b-122-1);
		}
		
		*(str+i)= b;
		i++;
	}
}


void decipher(char *str){
	int i=0,b;
	while(*(str+i)!='\0'){
		if (*(str+i)==' ' || *(str+i)=='\n'){
			i++;
			continue;
		}
		b=*(str+i);
		b-=3;
		if (b<97){
			b=122-(97-b-1);
		}
		
		*(str+i)= b;
		i++;
	}
}

void main(){
	int i=1;
	while (i){
		printf ("1.Cipher, 2. Decipher: ");
		scanf("%d%*c",&i);
		char *s  = (char *)malloc(sizeof(char)*500);
		printf("Enter String\n");
		fgets(s,499,stdin);
		switch(i){
			case 1:
				caesarcipher(s);
				puts(s);
				break;
			case 2:
				decipher(s);
				puts(s);
				break;
		}
		free(s);
	}
}
