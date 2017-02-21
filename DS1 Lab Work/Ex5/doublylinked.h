#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* nxtptr;

typedef struct node{
	
	char n[200];
	nxtptr next;
	nxtptr prev;
}node;



nxtptr createHead(){
	nxtptr head;
	head = (nxtptr)malloc(sizeof(node));
	
	head->next = NULL;
	head->prev = NULL;
	return head;
}

		
nxtptr createNode(nxtptr previous){
	nxtptr a;
	a = (nxtptr)malloc(sizeof(node));
	printf("Enter the name: ");
	scanf("%s",&a->n);
	a->next = NULL;
	a->prev = previous;
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

nxtptr find(char n[200],nxtptr head){
	nxtptr previous = head->next;
	nxtptr retVal = NULL;
	while (previous != NULL){
		if(strcmp(previous->n,n)== 0){
			retVal = previous;
			break;
		}
		previous=previous->next;
	}
	return retVal;
}

void insert(nxtptr previous,nxtptr head){
	
	nxtptr tmp = previous->next;
	previous = createNode(previous);
	previous->next = tmp;
	previous->next->prev = previous;
	
	printf("Inserted\n");	
}


void delete(char n[200],nxtptr head){
	nxtptr previous = find(n,head);
	previous->prev->next = previous->next;
	previous->next->prev = previous->prev;
	free(previous);
	printf("Deleted\n");
}


void display(nxtptr head){
	nxtptr previous = head->next;
	while(previous != NULL){
		printf("%s ",previous->n);
		previous=previous->next;
	}
	printf("\n");
}

void displayPN(char a[200],nxtptr head){
	nxtptr elem = find(a,head);
	printf("Previous Name: %s, Following Name: %s \n",elem->prev,elem->next);
}
