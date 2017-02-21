#include <stdio.h>
#include<stdlib.h>

typedef struct node* nxtptr;

typedef struct node{
	
	int n;
	nxtptr next;
}node;



nxtptr createHead(){
	nxtptr head;
	head = (nxtptr)malloc(sizeof(node));
	
	head->next = NULL;
	return head;
}

		
nxtptr createNode(nxtptr previous){
	nxtptr a;
	a = (nxtptr)malloc(sizeof(node));
	printf("Enter the number: ");
	scanf("%d",&a->n);
	a->next = NULL;
	
	previous->next = a;
	return a;
}

void createn(int k,nxtptr head){
	nxtptr previous = head;	
	int i;
	for(i=0;i<k;i++){
		previous = createNode(previous);
		
	}
}

nxtptr find(int n,nxtptr head){
	nxtptr previous = head->next;
	nxtptr retVal = NULL;
	while (previous->next != NULL){
		if(previous->next->n== n){
			retVal = previous;
			break;
		}
		previous=previous->next;
	}
	return retVal;
}

void insert(nxtptr previous,nxtptr head){
	previous = previous->next;
	nxtptr tmp = previous->next;
	previous = createNode(previous);
	previous->next = tmp;
	printf("Inserted\n");	
}

void insertEnd(nxtptr head){
	nxtptr previous = head->next;
	while (previous->next != NULL){
		previous=previous->next;
	}
	createNode(previous);
}

void insertStart(nxtptr head){
	nxtptr tmp = head->next;
	createNode(head);
	head->next->next = tmp;
	
}
void delete(int n,nxtptr head){
	nxtptr previous;	
	if (head->next->n == n){
		previous = head;	
	}
	else {
		previous = find(n,head);
	}
	nxtptr delel = previous->next;
	previous->next = delel->next;
	free(delel);
	printf("Deleted\n");
}
void countOccurence(int n, nxtptr head){
	nxtptr previous = head->next;
	int count = 0;
	while (previous != NULL){
		if(previous->n== n){
			count++;
			
		}
		previous=previous->next;
	}
	printf("Element Appears %d times\n",count);
}

void display(nxtptr head){
	nxtptr previous = head->next;
	while(previous != NULL){
		printf("%d ",previous->n);
		previous=previous->next;
	}
	printf("\n");
}

int size(nxtptr head){
	nxtptr previous = head->next;
	int count = 0;
	while(previous != NULL){
		count++;
		previous = previous->next;
	}
	return count;
}

