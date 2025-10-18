#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class StackChar{
    char arr[100];
    int top;
public:
    StackChar(){ top=-1; }
    void push(char x){ arr[++top]=x; }
    char pop(){ return arr[top--]; }
    char peek(){ return arr[top]; }
    bool empty(){ return top==-1; }
};

class StackInt{
    int arr[100];
    int top;
public:
    StackInt(){ top=-1; }
    void push(int x){ arr[++top]=x; }
    int pop(){ return arr[top--]; }
    bool empty(){ return top==-1; }
};

int precedence(char c){
    if(c=='^') return 3;
    else if(c=='*'||c=='/') return 2;
    else if(c=='+'||c=='-') return 1;
    else return -1;
}

string infixToPostfix(string s){
    StackChar st;
    string result = "";
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        if(c>='0' && c<='9') result+=c;
        else if(c=='(') st.push(c);
        else if(c==')'){
            while(!st.empty() && st.peek()!='(') result+=st.pop();
            st.pop();
        }
        else{
            while(!st.empty() && precedence(c)<=precedence(st.peek())) result+=st.pop();
            st.push(c);
        }
    }
    while(!st.empty()) result+=st.pop();
    return result;
}

int evaluatePostfix(string postfix){
    StackInt st;
    for(int i=0; i<postfix.length(); i++){
        char c = postfix[i];
        if(c>='0' && c<='9') st.push(c-'0');
        else{
            int b=st.pop();
            int a=st.pop();
            if(c=='+') st.push(a+b);
            else if(c=='-') st.push(a-b);
            else if(c=='*') st.push(a*b);
            else if(c=='/') st.push(a/b);
            else if(c=='^') st.push(pow(a,b));
        }
    }
    return st.pop();
}

int main(){
    string infix;

    cout<<"Enter infix expression: ";
    cin>>infix;

    string postfix=infixToPostfix(infix);
    cout<<"Postfix: "<<postfix<<endl;

    int result=evaluatePostfix(postfix);
    
    cout<<"Result: "<<result<<endl;

    return 0;
}