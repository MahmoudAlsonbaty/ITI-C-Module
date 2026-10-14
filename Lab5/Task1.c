#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    char name[100];
    int age;
    int totalMarks;
}Student;

static Student* studentPtr;
static int StudentCount = 0;
static int StudentAllocatedSize = 10;


void AddNewStudent(){
    if(StudentCount == StudentAllocatedSize){
        //TODO: this realloc logic is probably wrong, Double check it!
        studentPtr = (Student*)realloc(studentPtr,sizeof(Student)*(StudentAllocatedSize+10));
        StudentAllocatedSize+=10;
    }
    printf("Enter Student Name\n");
    scanf(" %99[^\n]",studentPtr[StudentCount].name);

    printf("Enter Student age\n");
    scanf("%d",&studentPtr[StudentCount].age);

    printf("Enter Student marks\n");
    scanf("%d",&studentPtr[StudentCount].totalMarks);

    printf("Student No. [%d] Added Successfully\n",StudentCount+1);
    StudentCount++;
}
void getStudentData(){
    int student;
    printf("Enter Student Number\n");
    scanf("%d",&student);

    if(student > StudentCount || student <= 0){
        printf("This student doesn't exist!\n");
    }else{
        int index = student-1;
        printf("Student No. [%d]:\nName: %s\nAge: %d\nTotal Marks: %d\n",student,studentPtr[index].name,studentPtr[index].age,studentPtr[index].totalMarks);
    }
}

int main(){
    studentPtr = (Student*)malloc(sizeof(Student)*10);
    int mode = 0;
    while(mode ==0){
        printf("What would you like to do?\n1 -> Add new student\n2 -> Display student info\n3 -> Get average marks\n4 -> Top 3 studnets\n5 -> Exit\n");
        scanf("%d",&mode);
        switch (mode)
        {
        case 1:
            AddNewStudent();
            mode = 0;
            break;
        case 2:
            getStudentData();
            mode = 0;
            break;
        case 3:
            printf("3-");
            break;
        case 4:
            printf("4-");
            break;
        case 5:
            printf("5-");
            break;
        default:
            printf("Please choose from 1 -> 5\n");
            mode=0;
        }
    }

}