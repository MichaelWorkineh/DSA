#include <iostream>

using namespace std;

struct student{
    int name;
    student *n;
    student *p;
};

void push_forward(int x , student * start );
void push_back(int x , student * start );
void display_forward (student * start );
void delete_beg (student * start);
void delete_back(student * start);

int main(){

    student list;
    student * start = &list;
    //display_forward(start);
    push_forward(2,start);
    push_back(2,start);
    //display_forward(start);
    return 0;
}

void push_forward(int x , student * start ){
    student node;
    node.name = x;
    if(start == NULL){
        start = &node;
        node.p = NULL;
        node.n = NULL;
        return;
    }
    else{
        student *temp;
        temp = start;
        start = &node;
        node.n = temp;
        cout<<temp->name<<endl;
    }
}

void push_back(int x, student * start ){
    student * temp1= start;
    student node;
    node.name = x;
    if(start == NULL){
        start = &node;
        node.p = NULL;
        node.n = NULL;
        return;
    }
    else{
        while(temp1->n!=NULL){
            temp1 = temp1->n;
        }
        temp1->n = &node;
        node.p = temp1;
        node.n = NULL;
        cout<<temp1->n<<endl;
    }
}

void display_forward (student * start ){
    if(start == NULL){
        cout<<"It is empty"<<endl;
        return;
    }

    else{
        student * temp = start;
        while(temp != NULL){
            cout<<(*temp).name<<" ";
            temp = temp ->n;
        }
        cout<<endl;
    }
}

void delete_beg (student * start){
    student * temp = start;
    start = start->n;
    delete temp;
}

void delete_back(student * start){
    student * temp = start;
    while (temp->n->n!=NULL)
    {
        temp = temp->n;
    }
    student * temp2 = temp->n;
    temp -> n = NULL;
    delete temp2;
    delete temp;
}