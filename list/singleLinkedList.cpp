//single linked list
#include <iostream>
using namespace std;

struct student{
    int age;
    student * next;
};
student * start = NULL, * p = new student;

void mainMenu();
void input ();
void insert_beg(student * p);
void insert_end(student * p);
void insert_at(int x, student * p);
void display_inc();
void display_back();
void delete_beg();
void delete_back();
void delete_at(int x);
void search_for(int x);

int main(){
    while(1==1){
        mainMenu();
    }
    return 0;
}

void mainMenu(){
    int choice;
    cout<<"enter:"<<endl;
    cout<<"\t 1 to create a list"<<"\t"<<"2 to insert at the beginig"<<endl;
    cout<<"\t 3 to insert at the end"<<" \t"<<"4 to insert at the middle"<<endl;
    cout<<"\t 5 to display at ascending order"<<"\t"<<"6 to display at descending order"<<endl;
    cout<<"\t 7 to delete at the beginig"<<"\t"<<"8 to delete at the end"<<endl;
    cout<<"\t 9 to delete at the middle"<<"\t"<<"10 to search for a value"<<endl;
    cin>>choice;
    student * x = new student;
    int position;
    switch (choice)
    {
    case 1:
        input();
        break;
    case 2:
        cin>>x->age;
        insert_beg(x);
        break;
    case 3:
        cin>>x->age;
        insert_end(x);
        break;
    case 4:
        cout<<"enter position and value respectively"<<endl;
        cin>>position>>x->age;
        insert_at(position,x);
        break;
    case 5:
        display_inc();
        break;
    case 6:
        display_back();
        break;
    case 7:
        delete_beg();
        break;
    case 8:
        delete_back();
        break;
    case 9:
        cin>>position;
        delete_at(position);
        break;
    case 10:
        int value;
        cin>>value;
        search_for(value);
        break;
    default:
        cout<<"invalid input!"<<endl;
        break;
    }
}

void input (){
    int elementNum;
    cin>>elementNum;
    for(int i = 0; i<elementNum; i++){
        student * x = new student;
        cin>>x->age;
        insert_end (x);
    }
}

void insert_beg(student * p){
    if(start == NULL){
        start = p;
        p->next = NULL;
    }

    else{
        student * temp = start;
        start = p;
        p->next = temp;
    }

}

void insert_end(student * p){
    if(start == NULL){
        cout<<"this was an emplty list"<<endl;
        start = p;
        p->next = NULL;
        return;
    }
    else{
        student * temp = start;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        //cout<<"found the end "<<temp->age<<endl; // maintenance
        temp->next = p;
        p->next = NULL;
    }
}

void insert_at(int x, student * p){
    student * temp1 = start;
    
    for (int i=0; i<x-1;i++){
        temp1 = temp1->next;
        if (temp1 == NULL){
            cout<<"out side the rage"<<endl;
            return;
        }
    }

    p->next = temp1->next;
    temp1->next = p;
}

void display_inc(){
    if(start == NULL){
        cout<<"empty list!"<<endl;
        return;
    }
    else{
        student * temp = start;
        do
        {
            cout<<temp->age<<" ";
            temp = temp->next;
        }
        while (temp != NULL);
        cout<<endl;

    }
}

void display_back(){
    if(start == NULL){
        cout<<"Nothin' here to see"<<endl;
        return;
    }

    else{
        student * temp1 = start, * temp2;
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        do{
            temp2 = start;
            while(temp2->next != temp1){
             temp2 = temp2->next;
            }
            cout<<temp1->age<<" " ;
            temp1 = temp2;
        }
        while(temp1 != start);
        cout<<temp1->age<<endl;
    }
}

void delete_beg(){
    if(start == NULL){
        cout<<"Nothin' to delete";
        return;
    }
    else{
        student * temp = start;
        start = start->next;
        delete temp;
    }
}

void delete_back(){
    student * temp1 = start, * temp2 = start;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    while(temp2->next != temp1){
        temp2 = temp2->next;
    }
    cout<<temp2->age<<endl;
    temp2->next = NULL;
    delete temp1;
}

void delete_at(int x){
    if(x==0){
        delete_beg();
    }
    else{
        student * temp1 = start, * temp2;
        for(int i = 0; i < x-1; i++){
            temp1 = temp1->next;
            if(temp1->next==NULL){
                cout<<"out of range"<<endl;
                return;
            }
        }
        temp2 = temp1->next;
        temp1->next = temp1->next->next;
        delete temp2;
    }
}

void search_for(int x){
    student * temp = start;
    int i=0;
    while(temp != NULL){
        if(temp->age == x){
            cout<<"found at index: "<<i<<endl;
            return;
        }
        temp = temp->next;
        i++;
    } 
    cout<<x<<" not found"<<endl;
}