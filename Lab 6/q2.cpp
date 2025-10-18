#include <iostream>
using namespace std;

class Node{
    public:
    int Data;
    Node* next;

    Node(int val=0){
        Data = val;
        next = nullptr;
    }
};

class Stack{
    private:
    Node* top;
   
    public:
    Stack(){
        top = nullptr;
    }
   
    void push(int val){
        Node* temp = new Node(val);
        temp->next = top;
        top = temp;
        cout<<"Pushed: "<<temp->Data<<endl;
    }
    void pop(){
        if(top==nullptr){
            cout<<"Stack is Empty."<<endl;
            return;
        }
        cout<<"Popped Top Data: "<<top->Data<<endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
   
    void Display(){
        if(!top){
            cout<<"Stack is Empty."<<endl;
            return;
        }
       
        Node* temp = top;
       
        while(temp != nullptr){
            cout<<temp->Data<<endl;
            temp = temp->next;
        }
    }
   
    void peek()
    {
        if(!top){
            cout<<"Stack is Empty."<<endl;
            return;
        }
        cout<<top->Data<<endl;
    }
};


int main()
{
    Stack S;

    S.push(1);
    S.push(2);
    S.push(3);

    cout<<"Current Stack:"<<endl;
    S.Display();

    cout<<"Peek top element: ";
    S.peek();

    S.pop();
    S.pop();

    cout<<"Stack after popping two elements:"<<endl;
    S.Display();

    S.pop();
    S.pop();

    return 0;
}