//linked list implementation 

#include <iostream>

using namespace std;
int const maxSize = 100;
int pop(), top = 0, stackSize = 0;

bool isEmpty();
bool isFull();
void push(int value), display(), intialize();

int stack [maxSize];
int main(){
    //cout<<isEmpty();
    intialize();
    display();
    return 0;
}

bool isEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(){
    if(stackSize == maxSize){
        return true;
    }

    else{
        return false;
    }
}

int pop(){
    if(isEmpty()==false){
        stackSize--;
        int position = top;
        top--;
        return stack[position];
    }
    else{
        cout<<"stack is empty"<<endl;
        //return -1;
    }
}

void push(int value){
    if(isFull()==false){
        top++;
        stackSize++;
        stack[top] = value;
    }
    else{
        cout<<"stack is full"<<endl;
    }
}

void display(){
    while (isEmpty() != true){
        cout<<pop()<<", ";
    }
    cout<<endl;
}

void intialize(){
    int numInput;
    cout<<"enter how many numbers do you want to insert?"<<endl;
    cin>>numInput;
    int value;
    for(int i = 0;i<numInput&&isFull()==false;i++){
        cout<<"Enter what value you can enter"<<endl;
        cin>>value;
        push(value);
    }
}