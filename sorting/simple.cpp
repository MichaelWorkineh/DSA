#include <iostream>
using namespace std;

void input(int array[],int n);
void sort(int array[],int n);
void display(int array[],int n);
int main(){
    cout<<"Enter the array size."<<endl;
    int n;
    cin>>n;
    int array[n];
    input(array,n);
    sort(array,n);
    display(array,n);
    return 0;
}

void input(int array[],int n){
   for(int i=0; i<n; i++) {
        cin>>array[i];
   }
}

void display(int array[],int n){
    for(int i=0; i<n; i++) {
        cout<<array[i];
        (i<n-1)?cout<<", ":cout<<"";
   }
}

void sort(int array[],int n){
    for(int i=0; i<n;i++){
        for(int l=i+1;l<n;l++){
            if(array[i]>array[l]){
                int temp = array[i];
                array[i]=array[l];
                array[l]=temp;
            }
        }
    }
}