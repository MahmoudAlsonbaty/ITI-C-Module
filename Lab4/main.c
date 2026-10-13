#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef unsigned char UC;

void *my_memchr(const void *s, int c, size_t n){
    UC chr = (UC)c;
    UC* ptr = s;
    for(size_t i =0;i<n;i++){
        if(*ptr == chr){
            return ptr;
        }
        ptr++;
    }
    return NULL;
}
int my_memcmp(const void *s1, const void *s2, size_t n){
    UC* first = s1;
    UC* second = s2;
    for(size_t i = 0; i<n;i++){
        if(*first == *second){
            first++;
            second++;
            continue;
        }else{
            return (*first - *second);
        }
    }
    return 0;
}
void *my_memcpy(void *restrict dest, const void *restrict src, size_t n){
    UC* src_c = src;
    UC* dest_c = dest;

    for(size_t i = 0;i<n;i++){
        *dest_c = *src_c;
        src_c++;
        dest_c++;
    }
    return dest;
}

void *my_memmove(void *dest, const void *src, size_t n){
    UC* dest_c = dest;
    
    UC* cpySrc = malloc(n);
    UC* cpyToOriginalPtr = cpySrc;
    my_memcpy(cpySrc,src,n);

    for(size_t i = 0;i<n;i++){
        *dest_c = *cpySrc;
        dest_c++;
        cpySrc++;
    }
    free(cpyToOriginalPtr);
    return dest;
}
void *my_memset(void *s, int c, size_t n){
    UC* ptr = s;

    for(size_t i = 0;i<n;i++){
        *ptr = (UC)c;
        ptr++;
    }
    return s;
}
size_t my_strlen(const char *s){
    size_t counter = 0;
    while(*s != '\0'){
        counter++;
        s++;
    }
    return counter;
}
char *my_strcpy(char *restrict dest, const char *restrict src){
    char *restrict returnPtr = dest; 
    size_t size = my_strlen(src);
    size++;// for the \0
    for(size_t i = 0; i<size;i++){
        *dest = *src;
        src++;
        dest++;
    }
    return returnPtr;
}

char *my_strncpy(char *restrict dest, const char *restrict src, size_t n){
    char *restrict returnPtr = dest;
    size_t size = my_strlen(src);
    for(size_t i = 0;i<n;i++){
        if(i>size){
            *dest = '\0';
            dest++;
            continue;
        }else{
            *dest = *src;
            dest++;
            src++;
        }
    }
    return returnPtr;
}

char *my_strcat(char *restrict dest, const char *restrict src){
    char *restrict returnPtr = dest;
    size_t end = my_strlen(dest);
    size_t size = my_strlen(src);
    dest+=end;
    for(size_t i = 0;i<size;i++){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return returnPtr;
}
char *my_strncat(char *restrict dest, const char *restrict src, size_t n){
    char *restrict returnPtr = dest;
    size_t end = my_strlen(dest);
    dest+=end;
    for(size_t i = 0;i<n;i++){
        if(*src =='\0'){
            break;
        }
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return returnPtr;
}
int my_strcmp(const char *s1, const char *s2){
    while(*s1 != '\0' && *s2 != '\0'){
        if(*s1 == *s2){
            s1++;
            s2++;
            continue;
        }else{
            return (UC)*s1 - (UC)*s2;
        }
    }
    return (UC)*s1 - (UC)*s2;
}
int my_strncmp(const char *s1, const char *s2, size_t n){
    for(size_t i =0;i<n;i++){
        if(*s1 == '\0' || *s2 == '\0'){
            return (UC)*s1-(UC)*s2;
        }
        if(*s1 == *s2){
            s1++;
            s2++;
            continue;
        }else{
            return (UC)*s1-(UC)*s2;
        }
    }
    return 0;
}
int my_strcoll(const char *s1, const char *s2){
    return my_strcmp(s1,s2);
}
char *my_strchr(const char *s, int c){
    char chr= (UC)c;
    size_t size = my_strlen(s);

    for(size_t i = 0; i<=size;i++){
        if(*s == chr){
            return s;
        }
        s++;
    }
    return NULL;
}
char *my_strrchr(const char *s, int c){
    char chr= c;
    size_t size = my_strlen(s);
    s+=size;
    for(size_t i = size+1; i>0;i--){
        if(*s == chr){
            return s;
        }
        s--;
    }
    return NULL;

}
char *my_strstr(const char *haystack, const char *needle){
    size_t size_hay = my_strlen(haystack);
    size_t size_needle = my_strlen(needle);
    for(size_t i =0;i<=size_hay;i++){
        int found = 1;
        for(size_t j = 0;j<size_needle;j++){
            if(haystack[i+j] == needle[j]){

            }else{
                found = 0;
                break;
            }
        }
        if(found == 1){
            return haystack+i;
        }
    }
    return NULL;
}
size_t my_strspn(const char *s, const char *accept){
    size_t accepted = 0;
    size_t size = my_strlen(s)+1;
    size_t size_accept = my_strlen(accept);

    for(size_t i = 0;i<size;i++){
        int found = 0;
        for(size_t j =0;j<size_accept;j++){
            if(s[i] == accept[j]){
                found = 1;
                break;
            }
        }
        if(found == 1){
            accepted++;
        }else{
            break;
        }
    }
    return accepted;
}
size_t my_strcspn(const char *s, const char *reject){
    size_t accepted = 0;
    size_t size = my_strlen(s);
    size_t size_reject = my_strlen(reject);

    for(size_t i = 0;i<size;i++){
        int found = 1;
        for(size_t j =0;j<size_reject;j++){
            if(s[i] == reject[j]){
                found = 0;
                break;
            }
        }
        if(found == 1){
            accepted++;
        }else{
            break;
        }
    }
    return accepted;
}
char *my_strpbrk(const char *s, const char *accept){
    size_t size = my_strlen(s)+1;
    size_t size_accept = my_strlen(accept);

    for(size_t i = 0;i<size;i++){
        int found = 0;
        for(size_t j =0;j<size_accept;j++){
            if(s[i] == accept[j]){
                found = 1;
                break;
            }
        }
        if(found == 1){
            return s+i;
        }
    }
    return NULL;
}
char *my_strtok(char *restrict str, const char *restrict delim){
    static char *restrict myPtr;
    if(str != NULL){
        myPtr = str;
        
    }
    size_t starting_index = my_strspn(myPtr,delim);
    myPtr += starting_index;
    size_t nextDelimIndex = my_strcspn(myPtr,delim);
    if(nextDelimIndex ==0){
        return NULL;
    }
    char* token = myPtr;
    if(myPtr[nextDelimIndex] == '\0'){
        myPtr+=nextDelimIndex;
    }else{
        *(myPtr+nextDelimIndex) = '\0';
        myPtr+=nextDelimIndex+1;
    }
    return token;

}
char *my_strerror(int errnum){
    switch (errnum)
    {
        case 0:
            return "My text for error 1";
        case 1:
            return "My text for error 2";
        default:
            return "Some error happened";
    }
}

int main(){
    //! Test cases were written by Ai, Just to validate the results

    char *p;
    /* ---- Memory ---- */
    unsigned char bytes[] = {0x10, 0x20, 0x30, 0x20};
    unsigned char *found = my_memchr(bytes, 0x20, 4);
    printf("memchr:   index %d (expected 1)\n", found ? (int)(found - bytes) : -1);

    printf("memcmp:   %d (expected negative)\n", my_memcmp("abcd", "abce", 4));
    printf("memcmp:   %d (expected 0)\n", my_memcmp("abcd", "abce", 3));

    char cpy[6];
    my_memcpy(cpy, "hello", 6);
    printf("memcpy:   \"%s\" (expected \"hello\")\n", cpy);

    char set[] = "hello";
    my_memset(set, '*', 3);
    printf("memset:   \"%s\" (expected \"***lo\")\n", set);

    /* ---- Copy and concatenate ---- */
    printf("strlen:   %zu (expected 5)\n", my_strlen("hello"));

    char d1[10];
    p = my_strcpy(d1, "cat");
    printf("strcpy:   \"%s\", returns dest: %s (expected \"cat\", yes)\n", d1, p == d1 ? "yes" : "no");

    char d2[6];
    my_strncpy(d2, "hello!", 6);
    printf("strncpy:  \"%.6s\" (expected \"hello!\")\n", d2);

    char d3[32] = "hello";
    my_strcat(d3, "ab");
    printf("strcat:   \"%s\" (expected \"helloab\")\n", d3);

    char d4[32] = "hello";
    my_strncat(d4, "barbaz", 3);
    printf("strncat:  \"%s\" (expected \"hellobar\")\n", d4);

    /* ---- Compare ---- */
    printf("strcmp:   %d (expected positive)\n", my_strcmp("abc", "ab"));
    printf("strcmp:   %d (expected positive)\n", my_strcmp("\xFF", "\x01"));
    printf("strncmp:  %d (expected 0)\n", my_strncmp("hello", "help", 3));
    printf("strcoll:  %d (expected negative)\n", my_strcoll("abc", "abd"));

    /* ---- Search ---- */
    p = my_strchr("hello world", 'o');
    printf("strchr:   \"%s\" (expected \"o world\")\n", p ? p : "NULL");

    p = my_strstr("the cat sat", "cat");
    printf("strstr:   \"%s\" (expected \"cat sat\")\n", p ? p : "NULL");

    printf("strspn:   %zu (expected 3)\n", my_strspn("123abc", "0123456789"));
    printf("strcspn:  %zu (expected 5)\n", my_strcspn("hello, world", ", "));

    p = my_strpbrk("hello, world", "wo");
    printf("strpbrk:  \"%s\" (expected \"o, world\")\n", p ? p : "NULL");

    /* ---- Tokenize ---- */
    char t[] = "  one,two;;three ";
    int count = 0;  /* stops after 10 in case strtok never returns NULL */
    p = my_strtok(t, ",; ");
    while (p != NULL && count++ < 10) {
        printf("strtok:   \"%s\"\n", p);
        p = my_strtok(NULL, ",; ");
    }
    printf("          (expected \"one\", \"two\", \"three\")\n");

    /* ---- Errors ---- */
    printf("strerror: %s\n", my_strerror(0));

    p = my_strrchr("hello world", 'o');
    printf("strrchr:  \"%s\" (expected \"orld\")\n", p ? p : "NULL");

    char mv[] = "abcdef";
    my_memmove(mv + 2, mv, 3);
    printf("memmove:  \"%s\" (expected \"ababcf\")\n", mv);

    return 0;
}