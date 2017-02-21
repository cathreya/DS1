typedef struct node* nxtptr;

typedef struct node{
	
	int n;
	nxtptr next;
}node;

nxtptr createHead();
nxtptr createNode(nxtptr);
void createn(int, nxtptr);
nxtptr find(int ,nxtptr);
void insert(nxtptr ,nxtptr);
void insertEnd(nxtptr);
void insertStart(nxtptr);
void delete(int, nxtptr);
void countOccurence(int, nxtptr);
void display(nxtptr);
int size(nxtptr);
