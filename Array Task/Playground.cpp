#include <iostream>



using namespace std;
class myArray{

    public:
    int* ptr;
    int size = 0;
    int capacity = 10;

    void grow(){
        
        int* NewPtr = (int*)malloc(sizeof(int)*capacity*2);
        if(NewPtr == NULL){
            cout<<"Grow Failed!"<<endl;
        }
        capacity = capacity*2;
        for(int i =0;i<size;i++){
            NewPtr[i]=ptr[i];
        }
        free(ptr);
        ptr = NewPtr;
    }

    myArray(){
        ptr = (int*)malloc(sizeof(int)*10);
        
    }
    void display(){
        cout << "Array : ";
        for(int i =0;i<size;i++){
            cout << "[" << i<< "]"<<ptr[i] << " ";
        }
        cout <<endl;
    }
    void append(int val){
        if(size == capacity){
            grow();
        }
        ptr[size]=val;
        size++;
    }
    void insert(int index,int val){
        if(size+1 > capacity){
            grow();
        }
        // 0 1 2 3 4
        // 4 6 8 20 
        // 4   6 8 20
        for(int i = size+1;i>index;i--){
            ptr[i] = ptr[i-1];
        }
        ptr[index] = val;
        size++;
    }

    void deleteElement(int index){
        for(int i = index;i<size-1;i++){
            ptr[i] = ptr[i+1];
        }
        size--;
    }
    int search(int val){
        for(int i = 0; i< size;i++){
            if(ptr[i] == val){
                return i;
            }
        }
        return -1; //Not found
    }
    int get(int index){
        return ptr[index];
    }
    void set(int index,int val){
        ptr[index] = val;
    }
    int min(){
        int globalMin = INT32_MAX;
        for(int i =0;i<size;i++){
            if(ptr[i] < globalMin){
                globalMin = ptr[i];
            }
        }
        return globalMin;
    }
    int max(){
        int globalMax = INT32_MIN;
        for(int i =0;i<size;i++){
            if(ptr[i] > globalMax){
                globalMax = ptr[i];
            }
        }
        return globalMax;
    }
    void reverse(){
        for(int i =0; i<size/2;i++){
            int temp= ptr[i];
            ptr[i] = ptr[size-i-1];
            ptr[size-i-1] = temp;
        }
    }

    //Come back here to check size and capacity issues
    void shift(int dir,int val){
        //dir = 0 , shift left
        //dir = 1 , shift right
        if(dir == 0){
            for(int i = 0;i<size-val;i++){
                ptr[i] = ptr[i+val];
            }
            for(int i = size-val-1;i > size;i--){
                ptr[i] =0;
            }
            size -= val;
            if(size <0) size =0; 
        }else{
            for(int i = size+val;i>val-1;i--){
                if(i > capacity){
                    continue;
                }
                ptr[i] = ptr[i-val];
            }
            for(int i = 0;i < val;i++){
                ptr[i] =0;
            }
            
        }
    }
    void rotate(int dir, int val){
        //dir = 0 , shift left
        //dir = 1 , shift right
        if(dir == 0){
            int* temp = (int*)malloc(sizeof(int)*val);
            for(int i =0 ;i < val;i++){
                temp[i] = ptr[i];
            }
            for(int i = 0;i<size-val;i++){
                ptr[i] = ptr[i+val];
            } 
            int counter = 0;
            for(int i = size-val;i<size;i++){
                ptr[i] = temp[counter++];
            }
            free(temp);   
        }else{
            int* temp = (int*)malloc(sizeof(int)*val);
            int counter = 0;
            for(int i =size-1 ;i > size-val-1;i--){
                temp[counter++] = ptr[i];
            }
            for(int i = size;i>val-1;i--){
                ptr[i] = ptr[i-val];
            } 
            int counter2 = val-1;
            for(int i = 0;i<val;i++){
                ptr[i] = temp[counter2--];
            }
        }
    }
    void merge(int* arrA,int lenA,int* arrB,int lenB){
        while(capacity < lenA+lenB){
            grow();
        }
        for(int i = 0;i<lenA;i++){
            ptr[i] = arrA[i];
        }
        for(int i = lenA;i<lenA+lenB;i++){
            ptr[i] = arrB[i-lenA];
        }
        size = lenA+lenB;
    }
    long int sum(){
        long int sumvalues =0;
        for(int i = 0;i<size;i++){
            sumvalues+= ptr[i];
        }
        return sumvalues;
    }
    int average(){
        return (sum()/size);
    }
    void replace(int a,int b){
        int temp = ptr[a];
        ptr[a] = ptr[b];
        ptr[b] = temp; 
    }


};

int main(){
    myArray arr =myArray();
    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.append(4);
    arr.append(5);

    arr.display();
    arr.reverse();
    arr.display();
    arr.reverse();
    arr.display();
    arr.rotate(1,2);
    arr.display();
    arr.replace(0,1);
    arr.display();
    cout << "MAX : "<<arr.max()<<endl;
    cout << "MIN : "<<arr.min()<<endl;
    cout << "Index of 5 : "<<arr.search(5)<<endl;
    cout << "val in index 3 : "<<arr.get(3)<<endl;
    arr.display();
    arr.set(3,99);
    cout << "set index 3 to 90 : " << endl;
    arr.display();
    arr.insert(1,90);
    arr.display();
    arr.deleteElement(1);
    arr.display();
    int secondArr[] ={100,101,102};
    arr.merge(arr.ptr,arr.size,secondArr,3);
    arr.display();

    int mode = 0;
    while(mode ==0){
        cout << "What Operation do you want to do?" << endl;
        cout << "0 -> Display" << endl;
        cout << "1 -> Append" << endl;
        cout << "2 -> Insert" << endl;
        cout << "3 -> Delete" << endl;
        cout << "4 -> Search" << endl;
        cout << "5 -> Get" << endl;
        cout << "6 -> Set" << endl;
        cout << "7 -> Max" << endl;
        cout << "8 -> Min" << endl;
        cout << "9 -> Reverse" << endl;
        cout << "10 -> Shift" << endl;
        cout << "11 -> Rotate" << endl;
        cout << "12 -> Merge" << endl;
        cout << "13 -> Average" << endl;
        cout << "14 -> Sum" << endl;
        cout << "15 -> Replace" << endl;

        cin >> mode;
        switch (mode)
        {
        case 0:{
            arr.display();
            mode = 0;
            break;
        }case 1:{
            cout << "Value to append :" <<endl;
            int val;
            cin >> val;
            arr.append(val);
            arr.display();
            mode = 0;
            break;
        }
        case 2:{
            cout << "Index to insert : ";
            int indx;
            cin >> indx;
            if (indx > arr.size || indx < 0){
                cout << "Wrong Index" <<endl;
                mode = 0;
                break;
            }
            cout << "Value : ";
            int val;
            cin >> val;
            arr.insert(indx,val);
            arr.display();
            mode = 0;
            break;
        }
        case 3:{
            cout << "Index to Delete : ";
            int indx;
            cin >> indx;
            if (indx > arr.size || indx < 0){
                cout << "Wrong Index" <<endl;
                mode = 0;
                break;
            }
            arr.deleteElement(indx);
            arr.display();
            mode = 0;
            break;
        }case 4:{
            cout << "Value to Search : ";
            int indx;
            cin >> indx;
            arr.display();
            int v = arr.search(indx);
            if (v == -1){
                cout << "Not Found!" <<endl;
                mode = 0;
                break;
            }
            cout << "Found at index : " << v<<endl;
            mode = 0;
            break;
        }
        case 5:{
            arr.display();
            cout << "index to get : ";
            int indx;
            cin >> indx;
            if (indx > arr.size || indx < 0){
                cout << "Wrong Index" <<endl;
                mode = 0;
                break;
            }
            cout << "Value : " << arr.get(indx)<<endl;
            mode = 0;
            break;
        }
        case 6:{
            arr.display();
            cout << "index to set : ";
            int indx;
            cin >> indx;
            if (indx > arr.size || indx < 0){
                cout << "Wrong Index" <<endl;
                mode = 0;
                break;
            }
            cout << "Value : ";
            int val;
            cin >> val;
            arr.set(indx,val);
            arr.display();
            mode = 0;
            break;
        }case 7:{
            arr.display();
            cout << "Max : " << arr.max() <<endl;
            mode = 0;
            break;
        }
        case 8:{
            arr.display();
            cout << "Min : " << arr.min() <<endl;
            mode = 0;
            break;}
        case 9:{
            arr.display();
            arr.reverse();
            arr.display();
            mode = 0;
            break;}
        case 10:{
            arr.display();
            int dir = 0;
            int value = 0;
            cout << "Enter the shift dir (0 -> left, 1 -> right) : " ;
            cin >> dir;
            if(dir > 1 || dir < 0){
                cout << "Wrong Dir" << endl;
                mode = 0;
                break;
            }
            cout << "Enter the shift Value : " ;
            cin >> value;
            arr.shift(dir,value);
            arr.display();
            mode = 0;
            break;}
        case 11:{
            arr.display();
            int dir = 0;
            int value = 0;
            cout << "Enter the rotate dir (0 -> left, 1 -> right) : " ;
            cin >> dir;
            if(dir > 1 || dir < 0){
                cout << "Wrong Dir" << endl;
                mode = 0;
                break;
            }
            cout << "Enter the rotate Value : " ;
            cin >> value;
            arr.rotate(dir,value);
            arr.display();
            mode = 0;
            break;}
        case 12:{
            cout << "Enter the number of elements you want to merge : ";
            int elements = 0;
            cin >> elements;
            if(elements < 0){
                cout << "Wrong number of elements" <<endl;
                mode = 0;
                break;
            }
            int* ptrElements = (int*)malloc(sizeof(int)*elements);

            for(int i = 0;i < elements;i++){
                cout << "Element [" << i <<"] : ";
                cin >> ptrElements[i];
            }
            arr.merge(arr.ptr,arr.size,ptrElements,elements);
            arr.display();
            free(ptrElements);
            mode = 0;
            break;}
        case 13:{
            cout << "Average : " << arr.average() <<endl;
            mode = 0;
            break;}
        case 14:{
            cout << "Sum : " << arr.sum() <<endl;
            mode = 0;
            break;}
        case 15:{
            arr.display();
            cout << "Index of element 1 :" ;
            int a,b;
            cin >> a;
            if(a > arr.size || a < 0){
                cout << "Wrong Index!" <<endl;
                mode = 0;
                break;
            }
            cout << "Index of element 2 :" ;
            cin >> b;
            if(b > arr.size || b < 0){
                cout << "Wrong Index!" <<endl;
                mode = 0;
                break;
            }
            arr.replace(a,b);
            arr.display();
            mode = 0;
            break;}
        default:
            cout << "Wrong Operation!";
            mode =0;
            break;
        }
    }

    return 0;
}