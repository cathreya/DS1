#include <stdio.h>
#include <string.h>

void insert(char d[10][50],int *n, char s[50]){
	int j=*n-1;
	while (strcmp(d[j],s)>0 && j>=0){
		strcpy(d[j+1],d[j]);
		j--;
	}
	strcpy(d[j+1],s);
	*n+=1;
	
}

int binsearch(char d[10][50],int *n, char s[50]){
	int ul=*n-1;
	int ll=0;
	int retVal=-1;
	while(ul>=ll){
		int mid = (ul+ll)/2;
		if(strcmp(d[mid],s)==0){
			retVal= mid;
			//return retVal;
			break;
			
		}
		else if (strcmp(d[mid],s)<0){
			ll=mid+1;

		}
		else if(strcmp(d[mid],s)>0){
			ul=mid-1;
		}

	}
	return retVal;
	
}

void delete(char d[10][50],int *n, char s[50]){
	int i;
	int k=binsearch(d,n,s);
	if(k>=0){
		for(i=k;i<*n-1;i++){
			strcpy(d[i],d[i+1]);
		}
		*n-=1;
		printf("Deleted\n");
	}

	else{
		printf("Not Found\n");
	}
}

void main(){
	char a[10][50]={"apple","ball","dog"};
	int i;
	int length=3;
	
	int entry=1;
	char op[50];
	while(entry!=0){
		printf("1.Insert, 2.Delete, 3.Search, 4.Display 0.Exit\n");
		scanf("%d%*c",&entry);
		switch(entry){
			case 1:
				printf("Enter word to be inserted\n");
				scanf("%s",op);
				insert(a,&length,op);
				break;
			case 2:
				printf("Enter word to be deleted\n");
				scanf("%s",op);
				delete(a,&length,op);
				break;
			case 3:
				printf("Enter word to be searched\n");
				scanf("%s",op);
				printf("Found at Index : %d\n",binsearch(a,&length,op));
				break;
			case 4:
				for(i=0;i<length;i++){
					printf("%s\n",a[i]);
				}
				break;
		}
	}
}	
