#include <stdio.h>
#define N 2

typedef struct{
	int stud_id;
	char stud_name[40];
	float stud_gpa;
	int stud_dob[3];

}student;

void insert(student m[N], student n, int *size){
	int i = *size-1;
	while(n.stud_id>m[i].stud_id && i>=0){
		m[i+1]=m[i];
		i--;
	}
	m[i+1]=n;
	*size += 1;
}

void input(student s[N],int *size){
	student m;
	
	int i;
	printf("Enter Details \n\n");
	
	printf("Enter the ID of the Student: ");
	scanf("%d%*c",&m.stud_id);
	printf("Enter Name of Student: ");
	fgets(m.stud_name,40,stdin);
	printf("Enter GPA of Student: ");
	scanf("%f%*c",&m.stud_gpa);
	printf("Enter Birth Date: ");
	scanf("%d%*c",&m.stud_dob[0]);
	printf("Enter Birth Month: ");
	scanf("%d%*c",&m.stud_dob[1]);
	printf("Enter Birth Date: ");
	scanf("%d%*c",&m.stud_dob[2]);
	insert(s,m,size);
}
void displaym(student s[N], int m, int *size){
	printf("Student ID : %d, Name : %s, GPA : %f, Date of Birth %d/%d/%d \n",s[m].stud_id,s[m].stud_name,s[m].stud_gpa,s[m].stud_dob[0],s[m].stud_dob[1],s[m].stud_dob[2]);
}

void display(student s[N], int*size){
	int i;
	for(i=0;i<*size;i++){
		printf("Student ID : %d, Name : %s, GPA : %f, Date of Birth %d/%d/%d \n",s[i].stud_id,s[i].stud_name,s[i].stud_gpa,s[i].stud_dob[0],s[i].stud_dob[1],s[i].stud_dob[2]);
	}
}




void main(){
	student s[N];
	int n;
	int size = 0;

	FILE *fp;
	fp = fopen("record.bin","w+b");
	if(ftell(fp) == 0){
		input(s,&size);
		fwrite(s,sizeof(student),size,fp);
	}	
	student stored[N];
	int m;	
	printf("Enter 1.Append an Entry, 2. Show all Data, 3. Show the size of the data in the file, 4. To show the Mth entry.\n");	
	int choice = 1;
	scanf("%d",&choice);
	fread(stored,sizeof(student),size,fp);
	switch(choice){
		case 1:
			input(stored,&size);
			
			break;
		case 2:
			display(s,&size);
			break;
		case 3:
			printf("Size of File is %lu\n",sizeof(stored));
			break;
		case 4:
			
			printf("Enter M\n");
			scanf("%d",&m);
			displaym(stored,m,&size);
			break;
	}

	fwrite(stored,sizeof(student),size,fp);
	
	fclose(fp);
}