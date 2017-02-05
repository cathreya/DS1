#include <stdio.h>
#include <math.h>
typedef struct point{
	int coordinates[3];
}point;

float distance(point p, point q){
	float sum = 0;
	int i;

	for (i=0;i<3;i++){
		int a = (p.coordinates[i]-q.coordinates[i]);
		sum+=pow(a,2);
	}
	return sqrt(sum);
	
} 

void main(){
	int i,j;
	point p[3];
	printf("Enter the vertices: \n");
	for (i=0;i<3;i++){
		printf("Enter (x,y,z) for vertex %d : ",i+1);
		for (j=0;j<3;j++){
			scanf("%d",&p[i].coordinates[j]);
		}
	}

	float a = distance(p[0],p[1]);
	float b = distance(p[1],p[2]);
	float c = distance(p[0],p[2]);
	
 	
	if ( a==b && b==c && c==a){
		printf("Equilateral\n");
	}
	else{
		printf("Not Equilateral\n");
	}
}
