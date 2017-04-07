#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct istack * ptrint;
typedef struct istack{
	int ToS;
	int size;
	int *arr;

}istack;

ptrint icreate(int size){
	ptrint a = malloc(sizeof(stack));
	a->ToS = -1;
	a->size = size;
	a->arr = malloc(sizeof(int)*size);
	return a;
}	

int isiEmpty(ptrint s){
	if(s->ToS == -1){
		return 1;
	}
	else return 0;
}

int ioverflow(ptrint s){
	if(s->ToS == s->size-1){
		return 1;
	}
	else return 0;
}

void ipush(ptrint s, int elem ){
	if(ioverflow(s)){
		printf("Stack is Full\n");
	}
	else{
		s->ToS += 1;
		s->arr[s->ToS] = elem;
	}
}

int ipop(ptrint s){
	if(isiEmpty(s)){
		printf("Stack is Empty\n");
	}
	else{
		int tmp = s->arr[s->ToS];
		
		s-> ToS -= 1;
		return tmp;
	}
}
void idisplay(ptrint s){
	int i;
	for (i = s->ToS;i>0;i--){
		printf("%c\n",s->arr[i] );
	}
	printf("\n");
}
int iretTop(ptrint s){
	if(isiEmpty(s)) printf("No Top, Stack is Empty\n"); 
	else return s->arr[s->ToS];
}


