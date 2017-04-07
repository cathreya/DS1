#include <stdio.h>
#include <string.h>

void main(){
	char a[] = "Hello World";
	char b = 'o';
	if(strchr(a,b)){
		printf("YES\n");
	}
}