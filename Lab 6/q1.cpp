#include <iostream>
using namespace std;

#define MAX 100

class Stack{
    int top;

    public:
        Stack(){
            top = -1;
        }
       
        int arr[MAX];

        bool push(int x){
            if(top>=MAX-1){
                cout<<"Stack overflow"<<endl;
                return false;
            }
            else{
                arr[++top] = x;
                cout<<x<<" pushed into Stack."<<endl;
                return true;
            }
        }
       
        int pop(){
            if(top<0){
                cout<<"Stack Underflow"<<endl;
                return 0;
            }
            else{
                int x = arr[top--];
                return x;
            }
        }
       
        int peek(){
            if(top<0){
                cout<<"Stack is Empty"<<endl;
                return 0;
            }
            else{
                int x = arr[top];
                return x;
            }
        }
       
        bool isEmpty(){
            return (top<0);
        }
       
        void Display(){
            cout<<"Displaying Stack Contents."<<endl;
            if(isEmpty()){
                cout<<"Stack is Empty."<<endl;
                return;
            }
           
            for(int i=top; i>=0; i--){
                cout<<arr[i]<<endl;
            }
        } 
};

int main(){

    Stack S;
   
    S.push(5);
    S.push(4);
    S.push(3);
    S.push(2);
    S.push(1);
   
    S.Display();
   
    S.pop();
    S.pop();
   
    cout<<"Top element after popping: "<<S.peek()<<endl;
   
    S.Display();
   
    return 0;
}
