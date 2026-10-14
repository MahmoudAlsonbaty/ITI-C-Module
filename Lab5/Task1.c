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
void printTheAverageMarks(){
    long long int sum = 0;
    for(int i = 0;i<StudentCount;i++){
        sum+=studentPtr[i].totalMarks;
    }
    if(StudentCount ==0){
        printf("No students in the database yet\n");
        return;
    }
    printf("The average marks for the %d students, is : %.2f\n",StudentCount,sum/(float)StudentCount);
}

void getTopStudents(int n){
    if(StudentCount < n) n = StudentCount;
    Student* TopN = (Student*)malloc(sizeof(Student)*n);
    int filled =0;
    for(int i = 0;i<StudentCount;i++){
        int finalPosition = filled;
        for(int j = 0;j<filled;j++){
            if(studentPtr[i].totalMarks > TopN[j].totalMarks){
                finalPosition = j;
                for(int m = n-1;m>j;m--){
                    TopN[m] = TopN[m-1];
                }
                break;
            }
        }
        if(finalPosition < n){
            TopN[finalPosition] = studentPtr[i];
        }
        if (filled < n) filled++;
    }
    printf("******** TOP %d STUDENTS ********\n",n);
    for(int i = 0;i<n;i++){
        printf("No. [%d]:\nName: %s, Age: %d, Total Marks: %d\n",i+1,TopN[i].name,TopN[i].age,TopN[i].totalMarks);
    }
    free(TopN);
}
int main(){
    studentPtr = (Student*)malloc(sizeof(Student)*10);
    //For Testing
    studentPtr[0] = (Student){.name = "student 1 test", .age = 20, .totalMarks = 85 };
    studentPtr[1] = (Student){.name = "student 2 test", .age = 25, .totalMarks = 50 };
    studentPtr[2] = (Student){.name = "student 3 test", .age = 29, .totalMarks = 90 };
    StudentCount = 3;
    int mode = 0;
    while(mode ==0){
        printf("What would you like to do?\n1 -> Add new student\n2 -> Display student info\n3 -> Get average marks\n4 -> Top N studnets\n5 -> Exit\n");
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
            printTheAverageMarks();
            mode = 0;
            break;
        case 4:
            printf("How many top students do you want? \n");
            int n = 3;
            scanf("%d",&n);
            getTopStudents(n);
            mode = 0;
            break;
        case 5:
            return 0;
            break;
        default:
            printf("Please choose from 1 -> 5\n");
            mode=0;
        }
    }

}