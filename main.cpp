#include <iostream>
using namespace std;

class node{
    friend class linklist;
private:
    int info;
    node *next;
};
class linklist{
private:
    node *first;
public:
    linklist() {
        first = NULL;
    }
    int empty(){
        if (first==NULL){
            return 1;
        } else{
            return 0;
        }
    }
    node* createNode(int x){
        node *newNode=new node;
        if(newNode == NULL){
            cout<<"there is a problem in creating new node";
            return 0;
        }
        newNode->info=x;
        newNode->next=NULL;
        return newNode;
    }
    void insert(int x) {
        node *newNode = createNode(x);
        if (first == NULL) {
            first = newNode;
            cout<<"the first is set"<<endl;
        } else {
            node *temp = first;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void addToBeginning(int x){
        node *temp = createNode(x);
        temp->next=first;
        first=temp;
    }
    node* search(int x){
        //If you need to access a specific node, you can use this function
        if (empty()){
            cout<<"link list is empty"<<endl;
        } else {
        node *temp=first;
            while (temp != NULL && temp->info!=x){
                temp=temp->next;
            }
            if (temp==NULL){
                cout<<"The desired node was not found"<<endl;
            } else{
            return temp;
            }
        }
    }
    void deleteNode(){
        if (empty()){
            cout<<"link list is empty"<<endl;
        } else {
                node *temp = first;
                node *previous;
                while (temp->next != NULL) {
                    previous = temp;
                    temp = temp->next;
                }
                previous->next = NULL;
                delete temp;
            }
    }
    void merging(linklist subLi) {
        node *temp1=first;
        node *temp2=subLi.first;
        while (temp1->next!=NULL){
            temp1=temp1->next;
        }
            temp1->next=temp2;
    }
    int counter(){
        node *temp=first;
        int count=0;
        while (temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    void reverse(){
        node *previous;
        node *middle=first;
        node *next;
        while (middle!=NULL){
            next=middle->next;
            middle->next=previous;
            previous=middle;
            middle=next;
        }
        first=previous;
    }
    void print() {
        node *temp = first;
        int i=1;
        while (temp != NULL) {
            cout<<i<<" th node is : "<<temp->info<<endl;
            temp = temp->next;
            i++;
        }
    }
    ~linklist(){};

};


int main() {
    linklist li1,li2;
    for(int i=1;i<=5;i++)
        li1.insert(i);
    cout<<"the first link list is :"<<endl;
    li1.print();
    cout<<"=================="<<endl;
    cout<<"the first link list after delete :"<<endl;
    li1.deleteNode();
    li1.print();
    cout<<"=================="<<endl;
    cout<<"add two node to the beginning"<<endl;
    li1.addToBeginning(700);
    li1.print();
    cout<<"=================="<<endl;
    cout<<"the second link list is :"<<endl;
    for (int j=10;j<=50;j=j+10)
        li2.insert(j);
    li2.print();
    cout<<"=================="<<endl;
    cout<<"merging two link list "<<endl;
    li1.merging(li2);
    li1.print();
    cout<<"=================="<<endl;
    cout<<"counting the second list"<<endl;
    cout<<"The number of the second link list : "<<li2.counter()<<endl;
    cout<<"=================="<<endl;
    cout<<"the reverse :"<<endl;
    li2.reverse();
    li2.print();
    return 0;
}
