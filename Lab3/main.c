#include <stdio.h>
#include <math.h>
#include <string.h>


void reverseArray(char* arr,int len){
    char* lastElement = arr + (len-1);
    for (int i =0;i < len;i++){
        printf("%c ", *lastElement);
        lastElement--;
    }
}
void copyArray(char* src,char* dst,int len){
    for (int i =0;i < len;i++){
        dst[i] = src[i]; 
    }
}
int countDuplicate(int* arr,int len){
    int foundElements[999];
    memset(foundElements, -1, sizeof(foundElements));
    int numDuplicates = 0;
    for (int i = 0;i<len;i++){
        for(int j = 0;j<len;j++){
            if(i==j){
                continue;
            }
            if(arr[i] == arr[j]){
                int previouslyFound = 0;
                for(int m = 0;m<999;m++){
                    if(foundElements[m] == -1){
                        foundElements[m] = arr[i];
                        break;
                    }
                    if(foundElements[m] == arr[i]){
                        previouslyFound = 1;
                        break;
                    }
                }
                if(previouslyFound == 0){
                    numDuplicates++;
                }
                foundElements[numDuplicates] = arr[i];
            }
        }
    }
    return numDuplicates;
}
void uniqueElements(int* arr,int len){
    int foundElements[999];
    memset(foundElements, -1, sizeof(foundElements));
    
    for (int i = 0;i<len;i++){
        int previouslyFound = 0;
        for(int j =0;j<len;j++){
            if(foundElements[j] == -1){
                foundElements[j] = arr[i];
                break;
            }
            if(arr[i]==foundElements[j]){
                previouslyFound = 1;
                break;
            }
        }
        if(previouslyFound == 0){
            printf(" %d",arr[i]);
        }
    }
}
void printFrequency(int* arr, int len){
    int foundElements[999];
    memset(foundElements, -1, sizeof(foundElements));
    int frequency[999];
    memset(frequency, 0, sizeof(frequency));\

    for(int i = 0; i< len;i++){
        int localFrequency = 1;
        int previouslyFound = 0;
        int elementIndex = -1;
        for(int m =0;m<len;m++){
                if(foundElements[m] == -1){
                    foundElements[m] = arr[i];
                    elementIndex = m;
                    break;
                }
                if(arr[i]==foundElements[m]){
                    previouslyFound = 1;
                    break;
                }
        }
        if(previouslyFound == 1){
            continue;
        }
        for(int j = 0;j<len;j++){
            if (i == j){
                continue;
            }
            if(arr[i]==arr[j]){
                localFrequency++;
            }
        }
        frequency[elementIndex] = localFrequency;
    }
    for(int i = 0;i<len;i++){
        if(foundElements[i] == -1){
            break;
        }
        printf("\n Element %d was mentioned %d times",foundElements[i],frequency[i]);
    }
}
void printMaxMin(int* arr,int len){
    int max = -1;
    int min = __INT32_MAX__;
    for(int i = 0;i<len;i++){
        if (arr[i] > max){
            max = arr[i];
        }
        if (arr[i] < min){
            min = arr[i];
        }
    }
    printf("\nSmallest Number : %d , Biggest Number : %d",min,max);    
}

void sortArrayAscending(int* arr,int len){
    for(int i = 0;i<len-1;i++){
        int swapped = 0;
        for(int j = 0;j < len - i -1;j++){
            if(arr[j] > arr[j+1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0){
            break;
        }
        
    }
    printf("\n Array After Sorting (Ascending) :");
    for(int i = 0;i<len;i++){
        printf(" %d",arr[i]);
    }
}
void sortArrayDescending(int* arr,int len){
    for(int i = 0;i<len-1;i++){
        int swapped = 0;
        for(int j = 0;j < len - i -1;j++){
            if(arr[j] < arr[j+1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0){
            break;
        }
        
    }
    printf("\n Array After Sorting (Descending) :");
    for(int i = 0;i<len;i++){
        printf(" %d",arr[i]);
    }
}
void decimalToBinary(int num){
    int Binary[32];
    memset(Binary, 0, sizeof(Binary));
    int copy = num;
    for(int i = 0;i<32;i++){
        if(copy <= 0){
            break;
        }
        Binary[32-i-1] = copy %2;
        copy /= 2;
    }
    printf("\n Binary of %d is : ",num);
    for(int i = 0;i<32;i++){
        printf("%d",Binary[i]);
    }

}
void wordInString(char *arr,int len){
    int words =1;
    if(len == 0){
        words =0;
    }
    for(int i = 0;i<len;i++){
        if(arr[i] == ' '){
            words++;
        }
    }
    printf("\n Number of words is : %d",words);
}
void printStringLength(char *arr){
    int i = 0;
    while(arr[i] != '\0'){
        i++;
    }
    printf("\nString len : %d",i);
}
void stringCompare(char *arr1,char *arr2){
    int len1 = 0;
    while(arr1[len1] != '\0'){
        len1++;
    }
    int len2 = 0;
    while(arr2[len2] != '\0'){
        len2++;
    }
    if(len1 != len2){
        printf("\n The 2 strings aren't identical");
        return;
    }

    int identical = 1;
    for(int i =0;i<len1;i++){
        if(arr1[i] != arr2[i]){
            identical = 0;
            break; 
        }
    }
    if(identical !=0){
        printf("\n The 2 strings are identical");
    }else{
        printf("\n The 2 strings aren't identical");

    }
}
void stringCopy(char *src,char *dst){
    int srcLen = 0;
    while(src[srcLen] != '\0'){
        srcLen++;
    }
    int dstLen = 0;
    while(dst[dstLen] != '\0'){
        dstLen++;
    }
    if(dstLen < srcLen){
        printf("\nCan't copy as destination is shorter than source");
        return;
    }

    for(int i =0 ;i<srcLen;i++){
        dst[i] = src[i];
    }
    printf("\nNew Destination : ");
    for(int i =0 ;i<=dstLen;i++){
        printf("%c",dst[i]);
    }
}
void stringCaseSwap(char *arr){
    int len = 0;
    while(arr[len] != '\0'){
        len++;
    }
    for(int i = 0;i<len;i++){
        if(arr[i] >=65 && arr[i] <= 90){
            //upper to lower
            arr[i] +=32;
        }else if(arr[i] >=97 && arr[i] <= 122){
            // lower to upper
            arr[i] -= 32;
        }
    }
    printf("\nAfter Case Swap : ");
    for(int i = 0;i<=len;i++){
        printf("%c",arr[i]);
    }
}

int main(){
    char arr[] = {'a','b','c','d'};
    reverseArray(arr,4);
    char arr2[] = {'h','o','l','a'};
    printf("\nOLD ARR2 : ");
    for (int i = 0; i < 4; i++) {
        printf("%c ", arr2[i]);
    }
    copyArray(arr,arr2,4);
    printf("\nNEW ARR2 : ");
    for (int i = 0; i < 4; i++) {
        printf("%c ", arr2[i]);
    }
    int randomArr[] = {1,1,1,2,3,4,5,5};
    printf("\nChecking for duplicates in (1,1,1,2,3,4,5,5) = %d",countDuplicate(randomArr,8));
    printf("\nUnique elements in (1,1,1,2,3,4,5,5) =");
    uniqueElements(randomArr,8);
    printFrequency(randomArr,8);
    printMaxMin(randomArr,8);
    int unsortedArr[] = {9,5,7,1,8,6,2,3,4};
    sortArrayAscending(unsortedArr,9);
    sortArrayDescending(unsortedArr,9);
    decimalToBinary(7);
    char strin[] = "Hello Amigos test"; 
    char strin2[] = "Hello Amigos teso"; 
    wordInString(strin,17);
    printStringLength(strin);
    stringCompare(strin,strin2);
    char source[] = "oops!";
    char destination[] = "Hello This is me!";
    stringCopy(source,destination);
    stringCaseSwap(destination);

    return 0;
}
