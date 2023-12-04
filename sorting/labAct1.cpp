#include <iostream>

using namespace std;

void input(int array[],int n){
   for(int i=0; i<n; i++) {
        cin>>array[i];
   }
}

void bubble(int array[],int n){
    for(int i=0; i<n;i++){
        for(int l=0;l<n-i;l++){
            if(l<=n-2 && array[l]>array[l+1]){
                int temp = array[l];
                array[l]=array[l+1];
                array[l+1]=temp;
            }
        }
        cout<<endl;
    }
}

void selection(int array[],int n){
    for(int i=0; i<n;i++){
        int maxLoc=i;
        for(int l=i+1;l<n;l++){
            if(array[maxLoc]<array[l]){
                maxLoc=l;
            }
        }
        if(maxLoc!=i){
            int temp = array[i];
            array[i]=array[maxLoc];
            array[maxLoc]=temp;
        }
    }
}

void insertionSort(int array[], int size){
    for(int i = 1; i<= size-1; i++){
        for(int j = i; j >= 1; j--){
            if(array[j-1]>array[j]){
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
            else{
                break;
            }
        }
    }
}

int binarrSearch(int array[], int left, int right, int key){
    while(left <= right){
        int mid = (left + right)/2;
        if(array[mid] == key){
            return mid;
        }
        else{
            if(key<array[mid]){
                right = mid - 1;
            }
            else{
                left = mid+1;
            }
        }
    }
    return right+1;
}
void linearSearch(int array[], int size, int value){
    for(int i = 0; i<size; i++){
        if(value == array[i]){
            cout<<value<<"found at index "<<i<<endl;
            return;
        }
    }
    cout<<value<<" not found"<<endl;
}
void insertionBinary(int array[], int size){
    for(int i=1; i<size; ++i){
        int key = array[i];
        int j = binarrSearch(array, 0, i-1, key);
        for(int k = i; k>j; --k){
            array[k] = array[k-1];
        }
        array[j] = key;
    }
}

void display(int array[],int n){
    for(int i=0; i<n; i++) {
        cout<<array[i];
        (i<n-1)?cout<<", ":cout<<"";
   }
}

int main(){
    int size;
    cout<<"Please enter how many elements you want to enter"<<endl;
    cin>>size;
    int array[size], choice;
    input(array, size);
    cout<<"1 to bubble sort\n2 to use selection sort\n3 to use Linear insertion sort\n4 to use binary insertion sort\n5 to do linear search\n6 to do binary search"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        bubble(array,size);
        break;
    case 2:
        selection(array,size);
        break;
    case 3:
        insertionSort(array,size);
        break;
    case 4:
        insertionBinary(array,size);
        break;
    case 5:
        cout<<"enter the value you want to search"<<endl;
        int value;
        cin>>value;
        linearSearch(array,size,value);
        break;
    case 6:
        cout<<"enter the value you want to search"<<endl;
        int value;
        cin>>value;
        binarrSearch(array,0,size-1, value);
        break;
    default:
        break;
    }
    cout<<endl;
    display(array,size);
}