#include "postfixstack.h"
#include "intstack.h"
int evaluate(ptr out){
	int tmp,a,b;
	ptrint intstack = icreate(500);

	while(1){
		if(isEmpty(out)){
			break;
		}
		tmp = pop(out);
		if(tmp == '+'){
			a = ipop(intstack);
			b = ipop(intstack);
			ipush(intstack,a+b);	
		}			
		else if(tmp == '-'){
			a = ipop(intstack);
			b = ipop(intstack);
			ipush(intstack,b-a);	
		}	
		else if(tmp == '*'){
			a = ipop(intstack);
			b = ipop(intstack);
			ipush(intstack,a*b);	
		}			
		else if(tmp == '/'){
			a = ipop(intstack);
			b = ipop(intstack);
			ipush(intstack,b/a);	
		}			
		else if(tmp == '%'){
			a = ipop(intstack);
			b = ipop(intstack);
			ipush(intstack,a%b);	
		}
		else{
			printf("Enter the value for %c\n",tmp);
			scanf("%d",&a);
			ipush(intstack,a);	
		}			
	}
	return(ipop(intstack));
}

void main(){
	int i;
	ptr s = create(500);
	ptr out = create(500);
	char p1[] = {'/','*','%'};
	char p2[] = {'+','-'};

	char input[500];
	scanf("%s",input);
	char tmp;

	for(i=0;i<strlen(input);i++){
		//display(s);
		if(input[i]==')'){
			while(1){
				tmp = pop(s);
				if(tmp == '(') break;
								
				printf("%c",tmp);
				push(out,tmp);
			}
		}
		else if(input[i] == '('){
			push(s,input[i]);
		}
		
		else if(strchr(p1,input[i])){
			if(isEmpty(s)){
				push(s,input[i]);
			}
			else{ 
				while(strchr(p1,retTop(s))){
					tmp = pop(s);
					printf("%c",tmp);
					push(out,tmp);
					if(isEmpty(s)) break;
				}
				push(s,input[i]);

			}
		}
		else if(strchr(p2,input[i])){
			if(isEmpty(s)){
				push(s,input[i]);
			}
			else{
				while(!isEmpty(s) && retTop(s) != '('){
					tmp = pop(s);
					printf("%c",tmp);
					push(out,tmp);
					if(isEmpty(s)){
						break;
					}
				}
				push(s,input[i]);				
			}
		}
		else{
			tmp = input[i];
			printf("%c",tmp);
			push(out,tmp);
		}
	}
	while(!isEmpty(s)){
		tmp = pop(s);
		printf("%c",tmp);
		push(out,tmp);
	}
	printf("\n");
	ptr o = create(500);
	while(!isEmpty(out)){
		tmp = pop(out);
		push(o,tmp);
	}
	
	
	printf("The Evaluated Expression Yields: %d\n", evaluate(o));
}

