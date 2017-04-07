#include<stdio.h>
typedef struct
{
    long     stud_id;
    char     name[40];
    int     stud_dob[3];
    float     stud_cpga;
   
}student;
void append()
{   
    FILE     *f1;
        f1=fopen("STUDENT.txt","a");
    student a[1];
        printf("Enter the ID_no: ");
        scanf("%ld",&a[0].stud_id);
        printf("Enter the name: ");
        scanf("%s",a[0].name);
        printf("Enter the DOB in the format dd/mm/yyyy: ");
        scanf("%d/%d/%d",&a[0].stud_dob[0],&a[0].stud_dob[1],&a[0].stud_dob[2]);
        printf("Enter the student CGPA: ");
        scanf("%f",&a[0].stud_cpga);
        fwrite(a,sizeof(a),1,f1);
        fclose(f1);
}
   
void display()
{
    FILE     *f1;
        f1=fopen("STUDENT.txt","r");
    student a[1];
        while(fread(a,sizeof(a),1,f1))
        {   
            printf("The Stud_Id: %ld\n",a[0].stud_id);
            printf("Student Name: %s\n",a[0].name);
            printf("Student DOB: %d/%d/%d\n",a[0].stud_dob[0],a[0].stud_dob[1],a[0].stud_dob[2]);
            printf("Student CGPA: %.2f\n",a[0].stud_cpga);
        }
        fclose(f1);
}
void display_size()
{
    FILE     *f1;
        f1=fopen("STUDENT.txt","r");
        fseek(f1,0,2);   
        int     size = ftell(f1);
            printf("%d\n",size);
            fclose(f1);
}
void display_m()
{
    FILE *    f1;
        f1=fopen("STUDENT.txt","r");
    student a[1];
    int    m;
        printf("Enter the record no:");
        scanf("%d",&m);
        fseek(f1,m*sizeof(a),0);
        fread(a,sizeof(a),1,f1);
        if(feof(f1))
        {
            printf("NOT FOUND\n");
            return ;
        }
        printf("The Stud_Id: %ld\n",a[0].stud_id);
        printf("Student Name: %s\n",a[0].name);
        printf("Student DOB: %d/%d/%d\n",a[0].stud_dob[0],a[0].stud_dob[1],a[0].stud_dob[2]);
        printf("Student CGPA: %f\n",a[0].stud_cpga);
        fclose(f1);
}
int main()
{   
    void     (*ptr[4])()={append,display,display_size,display_m};
    int     choice;
        printf("1.Append \n2.Display \n3.Display size \n4.Display mth\nEnter your choice:");
        scanf("%d",&choice);
        while(choice>0&&choice<5)
        {
            (*ptr[choice-1])();
            printf("1.Append \n2.Display \n3.Display size \n4.Display mth\nEnter your choice:");
            scanf("%d",&choice);
        }
}