#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct stack * ptr;
typedef struct stack{
	datatype n;
	ptr next;
	
}stack;
	
int isEmpty(ptr head){
	if(head->n == 0){
		return 1;
	}	
	else return 0;
}


ptr createHead(){
	ptr head = malloc(sizeof(stack));
	head->n = 0;
	head->next = NULL;
	return head;
}


void push(datatype n, ptr head){
	ptr a = malloc(sizeof(stack));
	a->next = head->next;
	head->next = a;
	a->n = n;
	head->n += 1;
}

void pop(ptr head){
	if(isEmpty(head)){
		printf("ERROR: Stack is Empty\n");
	}
	else{
		ptr tmp = head->next;
		head->next = tmp->next;
		head->n -= 1;
		free(tmp);
	}
}

datatype retTop(ptr s){
	if(isEmpty(s)){
		printf("ERROR: Stack is Empty\n");
	}
	else{
		return s->next->n;
	}
}

void dispose(ptr s){
	ptr i = s;
	while(i!=NULL){
		ptr tmp = i;
		i=tmp->next;
		free(tmp);
	}
}

void display(ptr s){
	ptr cur = s->next;
	while(cur!=NULL){
		printf("%d ",cur->n);
		cur=cur->next;
	}	
	printf("\n");
}

