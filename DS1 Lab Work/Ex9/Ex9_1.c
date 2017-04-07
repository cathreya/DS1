#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Rand(int ll, int ul){
	int diff = ul - ll ;
	return (int) (((double)(diff+1)/RAND_MAX) * rand() + ll);
}
void display(int *a,int ll, int ul){
	int i;
	printf("[");
	for(i=ll;i<=ul;i++){
		printf("%d ",a[i]);
	}
	printf("] ");
	
}

void bubbleS(int *a,int ll, int ul){
	int i,j;
	for(i=ll;i<=ul;i++){
		for(j=ul;j>i;j--){
			if(a[j]<a[j-1]){
				int tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
		}
		display(a,ll,ul);
		printf("\n");
	}
}


void insertS(int *a,int ll, int ul){
	int i,j;
	for(i=ll+1;i<=ul;i++){
		int cur = a[i];
		j = i-1;
		while(cur < a[j] && j>=ll){
			a[j+1] = a[j];
			j --;
		}
		a[j+1] = cur;
		display(a,ll,ul);
		printf("\n");
	}
}

void selectS(int *a, int ll, int ul){
	int i,j;
	for(i=ll;i<=ul;i++){
		int min = i;
		for(j=i+1;j<=ul;j++){
			if(a[j]<a[min]){
				min = j;
			}
		}
		int tmp = a[min];
		a[min] = a[i];
		a[i] = tmp;
		display(a,ll,ul);
		printf("\n");
	}
}
void merge(int *a, int ll, int mid, int ul){
	int *merged = malloc(sizeof(int)*(ul-ll+1));
	int i = ll;
	int j = mid+1;
	int k = ll;
	printf("First Subarray :");
	display(a,ll,mid);
	printf("Second Subarray :");
	display(a,mid+1,ul);
	printf("\n");
	while(i <= mid && j <= ul){
		if(a[i]<a[j]){
			merged[k] = a[i];
			i+=1;
			k+=1;
		}
		else if(a[j]<a[i]){
			merged[k] = a[j];
			j+=1;
			k+=1;
		}
		else{
			merged[k] = merged[k+1] = a[i];
			i+=1;
			j+=1;
			k+=2;
		}
	}
	while(i<=mid){
		merged[k] = a[i];
		i+=1;
		k+=1;
	}
	while(j<=ul){
		merged[k] = a[j];
		j+=1;
		k+=1;
	}
	for(i=ll;i<=ul;i++){
		a[i] = merged[i];
	}
	free(merged);
	printf("Merged Array :");
	display(a,ll,ul);
	printf("\n");


}

void mergeS(int *a, int ll, int ul){

	if(ul>ll){
		int mid = (ul+ll) / 2;
		mergeS(a,ll,mid);
		mergeS(a,mid+1,ul);
		merge(a,ll,mid,ul);
	}
}

int partition(int *a, int piv, int ll, int ul){
	printf("Pivot: %d",a[piv] );
	printf(" Partition :");
	display(a,ll,ul);
	printf("\n");
	int tmp = a[piv];
	a[piv] = a[ll];
	a[ll] = tmp;
	int i,j;
	i = j = ll+1;
	while(j<=ul){
		if(a[ll]>a[j]){
			tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
			i+=1;
		}
		j+=1;
	}
	i-=1;
	tmp = a[ll];
	a[ll] = a[i];
	a[i] = tmp;
	return i;
}

void quickS(int *a, int ll, int ul){
	if(ll<ul){
		int piv = Rand(ll,ul);
		piv = partition(a,piv,ll,ul);
		
		quickS(a,ll,piv-1);
		quickS(a,piv+1,ul);
	}
}

void shellS(int *a,int ll, int ul ){
	int n = (ul-ll);
	int i,j,k,tmp;
	for(i=n/2;i>0;i/=2){
		for(j=i;j<=ul;j++){
			tmp = a[j];
			for(k=j-i;k>=ll;k-=i){
				if(a[k+i] < a[k]){
					tmp = a[k];
					a[k] = a[k+i];
					a[k+i] = tmp;
					display(a,ll,ul);
					printf("\n");
				}
				else{
					break;
				}
			
			}
		}	

	}
}


void main(){
	srand(time(NULL));
	int a[100];
	int n,i;
	
	void (*b[6])(int *a, int ll, int ul)={bubbleS,insertS, selectS,shellS,mergeS,quickS};
	
	int choice = 1;
	while(1){
		printf("Enter the number of elements\n");
		scanf("%d",&n);
		if(n == 0) break;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		printf("1.Bubble Sort, 2.Insertion Sort, 3. Selection Sort, 4.Shell Sort, 5. Merge Sort, 6. Quick Sort\n" );
		scanf("%d",&choice);
		int ll,ul;
		printf("Enter Lower Limit and Upper Limit\n");
		scanf("%d %d",&ll,&ul);
		
		b[choice-1](a,ll,ul);
		printf("Sorted Array:\n");
		display(a,ll,ul);
		printf("\n");
		
	}
}
