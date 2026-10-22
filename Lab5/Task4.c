#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef enum EmployeeType { FULL_TIME, PART_TIME, INTERN } EmployeeType;
typedef enum Department { HR, TECH } Department;
typedef enum CompensationType { HOURLY, MONTHLY } CompensationType;

typedef union Compensation
{
    int hourly_rate;
    int monthly_salary;
}Compensation;

typedef struct{
    int id;
    char name[100];
    EmployeeType type;
    CompensationType compensation;
    Department department;
    Compensation pay;

}Employee;

static Employee* EmployeePtr;
static int EmployeeCount = 0;
static int EmployeeAllocatedSize = 10;

int getEmployeeIndex(int id){
    for(int i =0;i<EmployeeCount;i++){
        if(EmployeePtr[i].id == id){
            return i;
        }
    }
    return -1;
}
void AddEmployee(){
    if(EmployeeCount == EmployeeAllocatedSize){
        //TODO: this realloc logic is probably wrong, Double check it!
        EmployeePtr = (Employee*)realloc(EmployeePtr,sizeof(Employee)*(EmployeeAllocatedSize+10));
        EmployeeAllocatedSize+=10;
    }
    int id = -2;
    while (id == -2){
        printf("Enter ID:\n");
        scanf("%d",&id);
        int found = getEmployeeIndex(id);
        if(found != -1){
            printf("Employee ID taken!\n");
            id = -2;
        }else{
            EmployeePtr[EmployeeCount].id = id;
        }
    }

    printf("Enter Name:\n");
    scanf(" %99[^\n]",EmployeePtr[EmployeeCount].name);

    int decision = 0;
    while (decision == 0)
    {
        printf("Enter Department:\n1 -> HR\n2 -> TECH\n");
        scanf("%d",&decision);
        switch (decision)
        {
        case 1:
            EmployeePtr[EmployeeCount].department = HR;
            break;
        case 2:
            EmployeePtr[EmployeeCount].department = TECH;
            break;
        default:
            decision = 0;
            break;
        }
    }
    decision = 0;
    while (decision == 0)
    {
        printf("Enter Type:\n1 -> Full Time\n2 -> Part Time\n3 -> Intern\n");
        scanf("%d",&decision);
        switch (decision)
        {
        case 1:
            EmployeePtr[EmployeeCount].type = FULL_TIME;
            break;
        case 2:
            EmployeePtr[EmployeeCount].type = PART_TIME;
            break;
        case 3:
            EmployeePtr[EmployeeCount].type = INTERN;
            break;
        default:
            decision = 0;
            break;
        }
    }
    decision = 0;
    while (decision == 0)
    {
        printf("Enter Compensation Type:\n1 -> Monthly Salary\n2 -> Hourly\n");
        scanf("%d",&decision);
        switch (decision)
        {
        case 1:
            EmployeePtr[EmployeeCount].compensation = MONTHLY;
            printf("Enter Pay:\n");
            scanf("%d",&EmployeePtr[EmployeeCount].pay.monthly_salary);
            break;
        case 2:
            EmployeePtr[EmployeeCount].compensation = HOURLY;
            printf("Enter Pay:\n");
            scanf("%d",&EmployeePtr[EmployeeCount].pay.hourly_rate);
            break;
        default:
            decision = 0;
            break;
        }
    }

    printf("Employee [%d] Added Successfully\n",EmployeePtr[EmployeeCount].id);
    EmployeeCount++;
}
void RemoveEmployee(){
    int index = -2;
    while (index == -2){
        printf("Enter ID:\n");
        scanf("%d",&index);
        int found = getEmployeeIndex(index);
        if(found == -1){
            printf("Employee Doesn't Exist!\n");
            index = -2;
        }else{
            index = found;
            break;
        }
    }
    
    for(int i = index;i<EmployeeCount-1;i++){
        EmployeePtr[i] = EmployeePtr[i+1];
    }
    printf("Employee Removed Successfully\n");
    EmployeeCount--;

}

void AddOrRemoveEmployee(){
    int addOrRemove = 0;
    while(addOrRemove ==0){
        printf("What do you want to do?\n1 -> Add\n2 -> Remove\n");
        scanf("%d",&addOrRemove);
        switch(addOrRemove){
            case 1:
                AddEmployee();
                break;
            case 2:
                RemoveEmployee();
                break;
            default:
                addOrRemove = 0;
                break;
        }
    }

}
void printEmployeeInfo(int index){
    if(index == -1){
        printf("Employee not found!\n");
        return;
    }
    printf("ID: %d, Name : %s, ",EmployeePtr[index].id,EmployeePtr[index].name);
    if(EmployeePtr[index].department == HR){
        printf("Department : HR, ");
    }else if(EmployeePtr[index].department == TECH){
        printf("Department : TECH, ");
    }
    if(EmployeePtr[index].type == FULL_TIME){
        printf("Type : Full Time, ");
    }else if(EmployeePtr[index].type == PART_TIME){
        printf("Type : Part Time, ");
    }else{
        printf("Type : Intern, ");
    }
    if(EmployeePtr[index].compensation == HOURLY){
        printf("Hourly Rate : %d\n",EmployeePtr[index].pay.hourly_rate);
    }else{
        printf("Monthly Salary : %d\n",EmployeePtr[index].pay.monthly_salary);
    }
}

void filter(){
    int decision =0;
    while (decision ==0){
        printf("Do you want to filter by:\n1 -> Department\n2 -> Type\n");
        scanf("%d",&decision);
        switch (decision)
        {
        case 1:
            //Department
            int decisionDep =0;
            while (decisionDep ==0){
                printf("Do you want to filter by:\n1 -> HR\n2 -> TECH\n");
                scanf("%d",&decisionDep);
                switch (decisionDep)
                {
                case 1:
                    for(int i = 0; i< EmployeeCount;i++){
                        if(EmployeePtr[i].department == HR){
                            printEmployeeInfo(i);
                        }
                    }
                    break;
                case 2:
                    for(int i = 0; i< EmployeeCount;i++){
                        if(EmployeePtr[i].department == TECH){
                            printEmployeeInfo(i);
                        }
                    }
                    break;
                default:
                    decisionDep = 0;
                    break;
                }
            }
        break;
        case 2:
            //Type
            int decisionType =0;
            while (decisionType ==0){
                printf("Do you want to filter by:\n1 -> Full Time\n2 -> Part Time\n3 -> Intern\n");
                scanf("%d",&decisionType);
                switch (decisionType)
                {
                case 1:
                    for(int i = 0; i< EmployeeCount;i++){
                        if(EmployeePtr[i].type == FULL_TIME){
                            printEmployeeInfo(i);
                        }
                    }
                    break;
                case 2:
                    for(int i = 0; i< EmployeeCount;i++){
                        if(EmployeePtr[i].type == PART_TIME){
                            printEmployeeInfo(i);
                        }
                    }
                    break;
                case 3:
                    for(int i = 0; i< EmployeeCount;i++){
                        if(EmployeePtr[i].type == INTERN){
                            printEmployeeInfo(i);
                        }
                    }
                    break;
                default:
                    decisionType = 0;
                    break;
                }
            }
            break;
        default:
            decision = 0;
            break;
        }

    }
}

void getTotalPayroll(){
    int totalMonthly = 0;
    int totalHourly = 0;
    for(int i =0;i<EmployeeCount;i++){
        if(EmployeePtr[i].compensation == MONTHLY){
            totalMonthly += EmployeePtr[i].pay.monthly_salary;
        }else{
            totalHourly += EmployeePtr[i].pay.hourly_rate;
        }
    }
    printf("Total Monthly : %d, Total Hourly : %d\n",totalMonthly,totalHourly);
}


int main(){
    EmployeePtr = (Employee*)malloc(sizeof(Employee)*10);
    //For Testing
    EmployeePtr[0] = (Employee){.name = "Mahmoud",.id=100,.compensation=MONTHLY,.pay.monthly_salary=90000,.department = HR,.type=FULL_TIME};
    EmployeePtr[1] = (Employee){.name = "Ali",.id=101,.compensation=HOURLY,.pay.hourly_rate=90,.department = TECH,.type=PART_TIME};
    EmployeePtr[2] = (Employee){.name = "Mousa",.id=102,.compensation=MONTHLY,.pay.monthly_salary=90000,.department = HR,.type=INTERN};
    EmployeeCount = 3;
    int mode = 0;
    while(mode ==0){
        printf("What would you like to do?\n1 -> Add/Remove Emplyees\n2 -> Filter by department or type\n3 -> getTotalPayRoll\n4 -> Search by ID\n5 -> Exit\n");
        scanf("%d",&mode);
        switch (mode)
        {
        case 1:
            AddOrRemoveEmployee();
            mode = 0;
            break;
        case 2:
            filter();
            mode = 0;
            break;
        case 3:
            getTotalPayroll();
            mode = 0;
            break;
        case 4:      
            int id =0;
            printf("Enter Employee ID:\n");
            scanf("%d",&id);
            int INDEX = getEmployeeIndex(id);
            if(INDEX == -1){
                printf("Employee not found!\n");
                mode = 0;
                break;
            }
            printEmployeeInfo(INDEX);
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