#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node* ptr;
typedef struct queue* ptrq;
typedef struct queue{
	ptr head;
	ptr tail;
}queue;

typedef struct node{
	datatype data;
	ptr next;
}node;

int isEmpty(ptrq q){
	return q->head==NULL;
}
ptrq create(){
	ptrq a = malloc(sizeof(queue));
	a->head = a->tail = NULL;
	return a;
}

void enqueue(ptrq q, datatype dat){
	ptr a = malloc(sizeof(node));
		a->data = dat;
		a->next = NULL;
	if(isEmpty(q)){
		q->head = q->tail = a;
	}
	else{
		q->tail->next = a;
		q->tail = q->tail->next;
	}
}

void dequeue(ptrq q){
	if(isEmpty(q)){
		printf("Error: Queue is Empty\n");
	}
	else if(q->head == q->tail){
		q->head = q->tail = NULL;
	}
	else{
		ptr tmp = q->head;
		q->head = q->head->next;
		free(tmp);
	}
}

void display(ptrq q){
	ptr tmp = q->head;
	while(tmp != NULL){
		printf("%d ",tmp->data);
		tmp = tmp->next;
		
	}
	printf("\n");

}

void main(){
	ptrq q = create();
	int choice = 1;
	int qry;
	while(choice != 0){
		printf("1. Enqueue 2. Dequeue 3. Display\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				scanf("%d",&qry);
				enqueue(q,qry);
				break;
			case 2:
				dequeue(q);
				break;
			case 3:
				display(q);
				break;
		}
	}
}