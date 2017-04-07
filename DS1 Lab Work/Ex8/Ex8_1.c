#include <stdio.h>
#include <stdlib.h>

typedef struct queue * ptr;
typedef struct queue{
	int front;
	int rear;
	int size;
	int capacity;
	int *arr;
}queue;

ptr create(int size){
	ptr a = malloc(sizeof(queue));
	a->size = 0;
	a->capacity = size;
	a->front = a->rear = -1;
	a->arr = malloc(sizeof(int)*size);
	return a;
}

int isEmpty(ptr s){
	if(s->size == 0){
		return 1;
	}
	else return 0;
}

int isFull(ptr s){
	if(s->size == s->capacity){
		return 1;
	}
	else return 0;
}

void enqueue(ptr s, int elem){
	if(isEmpty(s)){
		s->arr[0]=elem;
		s->size+=1;
		s->front = s->rear = 0;
	}
	else if(isFull(s)){
		printf("Error, Queue is Full\n");
	}
	else{
		s->rear = (s->rear+1)%s->capacity;
		s->arr[s->rear]=elem;
		s->size+=1;
	}

}

void dequeue(ptr s){
	if(isEmpty(s)){
		printf("Error, Queue is Empty\n");
	}
	else{
		s->front = (s->front + 1)%s->capacity;
		s->size-=1;

	}
}

void display(ptr s){
	int i;
	for(i=s->front;i!=s->rear;){
		printf("%d ",s->arr[i] );
		i = (i + 1) % s->capacity;
	}
	printf("%d\n",s->arr[i]);
}

void dispose(ptr s){
	free(s->arr);
	free(s);
}

void main(){
	ptr q = create(5);
	int choice =1;
	int tmp;
	while(choice != 0){
		printf("1. Enqueue, 2.Dequeue, 3.Display\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				scanf("%d",&tmp);
				enqueue(q,tmp);
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