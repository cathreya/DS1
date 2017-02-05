#include <stdio.h>

typedef struct structs{
	int i;
	float f;
	char c;
}structs;

typedef union unions{
	int i;
	float f;
	char c;
}unions;

void main(){
	int i;
	float f;
	char c;
	structs s;
	unions u;
	printf ("Enter an integer, float and a character \n");
	scanf("%d %f %c",&i,&f,&c);
	s.i = i;
	s.f = f;
	s.c = c;
	u.i = i;
	u.f = f;
	u.c = c;
	printf("Size of the Struct: %d\n", sizeof(s));
	printf("Size of the Union: %d\n",sizeof(u));
	printf("Values stored in the Struct: %d %f %c \n",s.i,s.f,s.c);
	printf("Values stored in the Union: %d %f %c \n",u.i,u.f,u.c);
}
