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
void delete_beg();
void delete_end();
void delete_at(int x);
void search_for(int x);

int main(){
    int choice;
    while(1==1){
        cout<<endl<<"Menu: "<<endl;
        cout<<"1. intialize"<<endl;
        cout<<"2. insert at the begining"<<endl;
        cout<<"3. display in increase order"<<endl;
        cout<<"4. display in decrease oreder"<<endl;
        cout<<"5. insert at the end of list"<<endl;
        cout<<"6. random insert in the middle (random insertion)"<<endl;
        cout<<"7. delete at the begining"<<endl;
        cout<<"8. delete at the end"<<endl;
        cout<<"9. delete at the middle (random insertion)"<<endl;
        cout<<"10. search for a value"<<endl;
        cout<<"11. Exit"<<endl;
        cin>>choice;
        student* y;
        int position, value;
        switch(choice){
            case 1:
                initialize();
                break;
            case 2:
                cout<<"enter a value"<<endl;
                cin>>y->age;
                insert_beg(y);
                break;
            case 3:
                display_inc();
                break;
            case 4:
                display_dec();
                break;
            case 5:
                cout<<"enter a value"<<endl;
                cin>>y->age;
                insert_end(y);
                break;
            case 6:
                cout<<"enter position"<<endl;
                cin>>position;
                cout<<"enter the value"<<endl;
                cin>>y->age;
                insert_at(position, y);
                break;
            case 7:
                delete_beg();
                break;
            case 8:
                delete_end();
                break;
            case 9:
                cout<<"Enter the position"<<endl;
                cin>>position;
                delete_at(position);
                break;
            case 10:
                cout<<"Enter value you are looking for"<<endl;
                cin>>value;
                search_for(value);
                break;
            case 11:
                return 0;
            default:
                cout<<"Wrong input!"<<endl;
        }
    }
    return 0;
}

void initialize(){
    int elementNum;
    cout<<"enter the  number of elements"<<endl;
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

void delete_beg(){
    if(start == NULL){
        cout << "nothin' to see"<<endl;
    }
    else{
        student * temp = start;
        start = start->next;
        start->prev = NULL;
        temp->next = temp->prev = NULL;
        delete temp;
    }
}

void delete_end(){
    if(start == NULL){
        cout<<"Nothin' to see"<<endl;
    }

    else{
        student * temp1 = start;
        while(temp1->next->next != NULL){
            temp1 =temp1->next;
        }
        student * temp2 = temp1->next;
        temp1->next = NULL;
        temp2->next = temp2->prev = NULL;
        delete temp2;
    }
}

void delete_at(int x){
    if(start == NULL){
        cout<<"already empty!"<<endl;
    }
    else if(x<1){
        cout<<"invalid input"<<endl;
    }
    else{
        student * temp1  = start;
        for(int i = 1; i<x-1; i++){
            temp1 = temp1->next;
            if(temp1 == NULL){
                cout<<"out of bounds"<<endl;
            }
        }
        student * temp2 = temp1->next;
        temp1->next->next->prev = temp1;
        temp1->next= temp1->next->next;
        temp2->next = temp2->prev = NULL;
        delete temp2;
    }
}

void search_for(int x){
    if(start == NULL){
        cout<<"nothin' to search"<<endl;
    }
    else{
        student * temp = start;
        int i = 1;
        while(temp != NULL){
            if(temp->age == x){
                cout<<"found! index = "<<i<<endl;
                return;
            }
            temp = temp->next;
            i++;
        }
        cout << x << " Not found"<<endl; 
    }

}