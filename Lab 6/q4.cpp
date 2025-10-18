#include <iostream>
using namespace std;

class CircularQueue{
    int front, rear, size;
    int* arr;

public:
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return (rear+1)%size == front;
    }

    bool isEmpty(){
        return front == -1;
    }

    void enqueue(int val){
        if(isFull()){
            cout << "Queue Overflow\n";
            return;
        }
        if(isEmpty()){
            front = rear = 0;
        } 
        else{
            rear = (rear+1)%size;
        }
        arr[rear] = val;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow\n";
            return;
        }
        cout << "Removed: " << arr[front] << endl;

        if(front == rear){ // last element removed
            front = rear = -1;
        } 
        else{
            front = (front+1)%size;
        }
    }

    void display(){
        if(isEmpty()){
            cout << "Queue Empty\n";
            return;
        }
        int i=front;
        while(true){
            cout<<arr[i]<<" ";
            if (i==rear) break;
            i = (i + 1)%size;
        }
        cout << endl;
    }
};

int main(){
    CircularQueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();
    cq.dequeue();
    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60);
    cq.display();
    return 0;
}