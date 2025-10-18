#include <iostream>
using namespace std;

class LinearQueue{
    int front, rear, size;
    int* arr;

public:
    LinearQueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return rear == size - 1;
    }

    bool isEmpty(){
        return front == -1 || front>rear;
    }

    void enqueue(int val){
        if (isFull()){
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = val;
    }

    void dequeue(){
        if (isEmpty()){
            cout<<"Queue Underflow\n";
            return;
        }
        cout<<"Removed: "<<arr[front++]<<endl;
    }

    void display(){
        if (isEmpty()){
            cout << "Queue Empty\n";
            return;
        }
        for(int i=front; i<=rear; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main(){
    LinearQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}