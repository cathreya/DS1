typedef struct node* nxtptr;

typedef struct node{
	
	char n[200];
	nxtptr next;
	nxtptr prev;
}node;


nxtptr createHead();
nxtptr createNode(nxtptr);
void createn(int, nxtptr);
nxtptr find(char[200],nxtptr);
void insert(nxtptr, nxtptr);
void delete(char[200],nxtptr);
void display(nxtptr);
void displayPN(char[200],nxtptr);
