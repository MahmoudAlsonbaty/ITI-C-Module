#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef enum BookStatus{Available, Returned} BookStatus;
typedef enum BookCategory{Drama, Fiction} BookCategory;

typedef struct{
    char title[100];
    char author[100];
    int price;
    BookCategory category;
    BookStatus status;

}Book;
static Book* BooksPtr;
static int BookCount = 0;
static int BookAllocatedSize = 10;

void AddNewBook(){
    if(BookCount == BookAllocatedSize){
        //TODO: this realloc logic is probably wrong, Double check it!
        BooksPtr = (Book*)realloc(BooksPtr,sizeof(Book)*(BookAllocatedSize+10));
        BookAllocatedSize+=10;
    }
    printf("Enter Book Title:\n");
    scanf(" %99[^\n]",BooksPtr[BookCount].title);

    printf("Enter Book Author:\n");
    scanf(" %99[^\n]",BooksPtr[BookCount].author);

    printf("Enter Book Price:\n");
    scanf("%d",&BooksPtr[BookCount].price);

    
    int decision = 0;
    while (decision == 0)
    {
        printf("Enter Book Status:\n1 -> Available\n2 -> Returned\n");
        scanf("%d",&decision);
        switch (decision)
        {
        case 1:
            BooksPtr[BookCount].status = Available;
            break;
        case 2:
            BooksPtr[BookCount].status = Returned;
            break;
        default:
            decision = 0;
            break;
        }
    }
    int CategoryDecision = 0;
    while (CategoryDecision == 0)
    {
        printf("Enter Book Category:\n1 -> Drama\n2 -> Fiction\n");
        scanf("%d",&CategoryDecision);
        switch (CategoryDecision)
        {
        case 1:
            BooksPtr[BookCount].category = Drama;
            break;
        case 2:
            BooksPtr[BookCount].status = Fiction;
            break;
        default:
            decision = 0;
            break;
        }
    }

    printf("Book No. [%d] Added Successfully\n",BookCount+1);
    BookCount++;
}

void getBookData(){
    char name[100];
    printf("Enter Book Title or Author:\n");
    scanf(" %99[^\n]",name);

    for(int i = 0; i<BookCount;i++){
        if(strcmp(name, BooksPtr[i].title) == 0 || strcmp(name, BooksPtr[i].author) == 0){
            printf("Book Found!\n");
            printf("Title : %s\n",BooksPtr[i].title);
            printf("Author : %s\n",BooksPtr[i].author);
            printf("Price : %d\n",BooksPtr[i].price);
            if(BooksPtr[i].status == Available){
                printf("Status : %s\n","Available");
            }else{
                printf("Status : %s\n","Returned");
            }
            if(BooksPtr[i].category == Drama){
                printf("Category : %s\n","Drama");
            }else{
                printf("Category : %s\n","Fiction");
            }
            return;
        }
    }
    printf("Book Not Found!\n");
}

void changeBookStatus(){
    char name[100];
    printf("Enter Book Title or Author to change the status:\n");
    scanf(" %99[^\n]",name);

    for(int i = 0; i<BookCount;i++){
        if(strcmp(name, BooksPtr[i].title) == 0 || strcmp(name, BooksPtr[i].author) == 0){
            int decision = 0;
            while (decision = 0)
            {
                printf("Enter Book Status:\n1 -> Available\n2 -> Returned\n");
                scanf("%d",&decision);
                switch (decision)
                {
                case 1:
                    BooksPtr[i].status = Available;
                    printf("Changed to Available!\n");
                    return;
                    break;
                case 2:
                    BooksPtr[i].status = Returned;
                    printf("Changed to Returned!\n");
                    return;
                    break;
                default:
                    decision = 0;
                    break;
                }
            }
        }
    }
    printf("Book not found");
}

void getCategoryCount(){
    int CatA = 0;
    int CatB = 0;

    for(int i = 0; i<BookCount;i++){
        if(BooksPtr[i].category == 0){
            CatA++;
        }else{
            CatB++;
        }
    }
    printf("Drama Books : %d\nFiction Books : %d\n",CatA,CatB);
}

int main(){
    BooksPtr = (Book*)malloc(sizeof(Book)*10);
    //For Testing
    BooksPtr[0] = (Book){.title = "myBook",.author="mahmoud",.price=100,.status=Available,.category=Fiction};
    BooksPtr[1] = (Book){.title = "hisBook",.author="mohammed",.price=100,.status=Returned,.category=Drama};
    BooksPtr[2] = (Book){.title = "ourBook",.author="mahmoud",.price=100,.status=Available,.category=Fiction};
    BookCount = 3;
    int mode = 0;
    while(mode ==0){
        printf("What would you like to do?\n1 -> Add new Book\n2 -> Search for a book\n3 -> Change book status\n4 -> Book count in each category\n5 -> Exit\n");
        scanf("%d",&mode);
        switch (mode)
        {
        case 1:
            AddNewBook();
            mode = 0;
            break;
        case 2:
            getBookData();
            mode = 0;
            break;
        case 3:
            changeBookStatus();
            mode = 0;
            break;
        case 4:      
            getCategoryCount();
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