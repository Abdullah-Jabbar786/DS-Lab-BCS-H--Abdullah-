#include <iostream>
using namespace std;

class Node{
public:
    string name;
    int level;
    int arrivalTime;
    Node *next;

    Node(string n, int l, int at){
        name = n;
        level = l;
        arrivalTime = at;
        next = NULL;
    }
};

class MaxQueue{
private:
    Node *front;
    int timeCounter;

public:
    MaxQueue(){
        front = NULL;
        timeCounter = 0;
    }

    void addPatient(string name, int lvl){
        timeCounter++;
        Node *newNode = new Node(name, lvl, timeCounter);

        if(!front || lvl > front->level ||
            (lvl == front->level && newNode->arrivalTime < front->arrivalTime)){
            newNode->next = front;
            front = newNode;
        }
        else{
            Node *current = front;
            while(current->next &&
                   (current->next->level > lvl ||
                    (current->next->level == lvl &&
                     current->next->arrivalTime < newNode->arrivalTime))){
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    Node *getNextPatient()
    {
        if(!front){
            cout << "Queue is empty." << endl;
            return nullptr;
        }
        else{
            Node *nextPatient = front;
            front = front->next;
            return nextPatient;
        }
    }

    void updateSeverity(string name, int newLvl){
        if (!front) return;

        Node *current = front;
        Node *previous = NULL;

        while (current && current->name != name){
            previous = current;
            current = current->next;
        }

        if(!current) return;

        int originalArrival = current->arrivalTime;

        if(previous) previous->next = current->next;
        else front = current->next;

        delete current;

        int savedCounter = timeCounter;
        addPatient(name, newLvl);
        front->arrivalTime = originalArrival;
        timeCounter = savedCounter;
    }

    void printQueue(){
        if(!front) cout << "Queue is empty." << endl;
        else{
            Node *current = front;
            while(current){
                cout << "(" << current->name << ", Severity: " << current->level << ", Arrival: " << current->arrivalTime << ")" << endl;
                current = current->next;
            }
        }
    }
};

int main(){
    MaxQueue queue;

    queue.addPatient("Junaid", 5);
    queue.addPatient("Fatima", 3);
    queue.addPatient("Hashim", 10);
    queue.addPatient("Zahrah", 7);
    queue.addPatient("Zaid", 6);

    cout << "Queue before treatment:\n";
    queue.printQueue();

    Node *nextPatient = queue.getNextPatient();
    if(nextPatient != NULL){
        cout << "\nNext patient to treat: "<< nextPatient->name << " (Severity: " << nextPatient->level << ")\n";
    }

    cout << "\nUpdating severity for Junaid to 8...\n";
    queue.updateSeverity("Junaid", 8);

    cout << "\nQueue after updating severity:\n";
    queue.printQueue();

    return 0;
}
