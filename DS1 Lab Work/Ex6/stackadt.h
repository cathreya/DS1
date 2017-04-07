#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct stack * ptr;
typedef struct stack{
	datatype *stk;
	int size;
	int TOS;
}stack;
	
int isEmpty(ptr s){
	if(s->TOS == -1){
		return 1;
	}	
	else return 0;
}

int isFull(ptr s){
	if(s->TOS + 1 == s->size){
		return 1;
	}
	else return 0;
}	

ptr createStack(int size){
	ptr a = malloc(sizeof(stack));
	a->size = size;
	a->stk = malloc(sizeof(datatype)*size);
	a->TOS = -1;
	return a;
}



void push(datatype n, ptr s){
	if(isFull(s)){
		printf("ERROR: Stack is Full\n");
	}
	else{
		s->TOS += 1;
		s->stk[s->TOS] = n;
	}	
}

void pop(ptr s){
	if(isEmpty(s)){
		printf("ERROR: Stack is Empty\n");
	}
	else{
		s->TOS -= 1;
	}
}

datatype retTop(ptr s){
	if(isEmpty(s)){
		printf("ERROR: Stack is Empty\n");
		return -1;
	}
	else{
		return s->stk[s->TOS];
	}
}

void dispose(ptr s){
	free(s->stk);
	free(s);
}

void display(ptr s){
	int i;
	for(i=s->TOS;i>=0;i--){
		printf("%d ",s->stk[i]);
	}
	printf("\n");
}

