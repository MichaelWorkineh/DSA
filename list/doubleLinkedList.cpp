#include <iostream>
using namespace std;

struct student
{
    int age;
    student * next;
    student * prev;
};

student * start = NULL;

void initialize();
void insert_beg(student * x);
void display_inc();
void display_dec();
void insert_end(student * x);
void insert_at(int position, student * x);

int main(){
    initialize();
    display_inc();
    student * x;
    cin>>x->age;
    insert_at(3,x);
    display_dec();
    return 0;
}

void initialize(){
    int elementNum;
    cin>>elementNum;
    for(int i =0; i<elementNum; i++){
        student * x = new student;
        cin>>x->age;
        insert_end(x);
    }
}

void insert_beg(student * x){
    if(start == NULL){
        start = x;
        x->prev = NULL;
        x->next = NULL;
    }
    else{
        student * temp = start;
        start = x;
        x->prev = NULL;
        x->next = temp;
        temp->prev = x;
    }
}

void insert_end(student * x){
    if(start == NULL){
        start = x;
        x->next = NULL;
        x->prev = NULL;
    }
    else{
        student * temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = x;
        x->prev = temp;
        x->next = NULL;
        
    }
}

void insert_at(int position, student * x){
    if(start == NULL){
        insert_end(x);
    }
    else if (position == 1)
        insert_beg(x);
    else{
        student * temp1 = start;
        for(int i=1; i<position-1; i++){
            temp1 = temp1->next;
        }
        student * temp2 = temp1->next;
        temp1->next = x;
        x->prev = temp1;
        x->next = temp2;
        temp2->prev = x;
    }
}

void display_inc(){
    student * temp = start;
    while(temp != NULL){
        cout<<temp->age<<" ";
        temp = temp->next;
    }
}

void display_dec(){
    student * temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    while (temp != NULL)
    {
        cout<<temp->age<<" ";
        temp = temp->prev;
    }
    
}