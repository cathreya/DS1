#include <stdio.h>
#include <string.h>
void insertS(char a[50][100],int ll, int ul){
	int i,j;
	
	for(i=ll+1;i<=ul;i++){
		char cur[1000];
		strcpy(cur,a[i]);
		j = i-1;
		while(strcmp(cur,a[j])<0 && j>=ll){
			strcpy(a[j+1],a[j]);
			j --;
		}
		strcpy(a[j+1],cur);
	}
}

int lSearch(char a[50][100], int n,char elem[100], int *count){
	int i;
	for(i=0;i<n;i++){
		*count+=1;
		if(strcmp(a[i],elem)==0){
			return i;
		}
	}
	return -1;
}

int binSearch(char a[50][100], int ll, int ul, char elem[100], int *count){
	*count+=1;
	if(ll>ul){
		return -1;
	}
	else{
		int mid = (ll + ul)/2;
		if (strcmp(a[mid],elem)==0){
			return mid;
		}
		else if(strcmp(a[mid],elem)>0){
			return binSearch(a,ll,mid-1,elem,count);
		}
		else{
			return binSearch(a,mid+1,ul,elem,count);
		}
	}
}


void main(){
	char a[50][100];
	int n,i;
	printf("How many Elements?\n");
	scanf("%d%*c",&n);
	for(i=0;i<n;i++){
		fgets(a[i],100,stdin);
	}
	insertS(a,0,n-1);
	printf("List after sorting\n");
	for(i=0;i<n;i++){
		printf("%s",a[i]);

	}
	printf("\nEnter Element to Search\n");
	char elem[100];
	int count = 0;
	fgets(elem,100,stdin);
	
	
	printf("\n");
	printf("Element found at using Linear Search %d\n",lSearch(a,n,elem,&count));
	printf("Number of Comparisons :%d\n",count);
	count=0;
	printf("Element found at using Binary Search %d\n",binSearch(a,0,n-1,elem, &count));
	printf("Number of Comparisons :%d\n",count);
}