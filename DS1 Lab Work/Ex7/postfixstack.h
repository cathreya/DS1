#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack * ptr;
typedef struct stack{
	int ToS;
	int size;
	char *arr;

}stack;

ptr create(int size){
	ptr a = malloc(sizeof(stack));
	a->ToS = -1;
	a->size = size;
	a->arr = malloc(sizeof(char)*size);
	return a;
}	

int isEmpty(ptr s){
	if(s->ToS == -1){
		return 1;
	}
	else return 0;
}

int overflow(ptr s){
	if(s->ToS == s->size-1){
		return 1;
	}
	else return 0;
}

void push(ptr s, char elem ){
	if(overflow(s)){
		printf("Stack is Full\n");
	}
	else{
		s->ToS += 1;
		s->arr[s->ToS] = elem;
	}
}

char pop(ptr s){
	if(isEmpty(s)){
		printf("Stack is Empty\n");
	}
	else{
		char tmp = s->arr[s->ToS];
		
		s-> ToS -= 1;
		return tmp;
	}
}
void display(ptr s){
	int i;
	for (i = s->ToS;i>0;i--){
		printf("%c\n",s->arr[i] );
	}
	printf("\n");
}
char retTop(ptr s){
	if(isEmpty(s)) printf("No Top, Stack is Empty\n"); 
	else return s->arr[s->ToS];
}


