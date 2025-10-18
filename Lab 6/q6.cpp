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

string reverseStr(string s){
    int n = s.length();
    for(int i=0; i<n/2; i++){
        char temp=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=temp;
    }
    return s; // reversed.
}

string infixToPostfix(string s){
    StackChar st;
    string result = "";
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        if(c>='0' && c<='9') result+=c;
        else if(c=='(') st.push(c);
        else if(c==')'){
            while(!st.empty() && st.peek()!='('){
                result+=st.pop();
            }
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

string infixToPrefix(string infix){
    infix = reverseStr(infix);
    for(int i=0; i<infix.length(); i++){
        if(infix[i]=='(') infix[i]=')';
        else if(infix[i]==')') infix[i]='(';
    }
    string postfix = infixToPostfix(infix);
    string prefix = reverseStr(postfix);
    return prefix;
}

int evaluatePrefix(string prefix){
    StackInt st;
    for(int i=prefix.length()-1; i>=0; i--){
        char c = prefix[i];
        if(c>='0' && c<='9') st.push(c-'0');
        else{
            int a=st.pop();
            int b=st.pop();
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

    string prefix=infixToPrefix(infix);
    cout<<"Prefix: "<<prefix<<endl;

    int result=evaluatePrefix(prefix);
    
    cout<<"Result: "<<result<<endl;

    return 0;
}