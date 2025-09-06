#include <iostream>
using namespace std;


class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
        
    Node(int v) // constructor
    {
        val = v;
        prev = next = child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL) return head;

        Node* curr = head;
        while(curr!=NULL)
        {
            if(curr->child != NULL)
            {
                //Child node
                Node* next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                while(curr->next!=NULL)
                {
                    curr = curr->next;        
                }

                if(next!=NULL)
                {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

void printList(Node* head) 
{
    while(head!=nullptr){
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}


Node* createTestList() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;

    n2->child = n4;
    n4->next = n5;
    n5->prev = n4;

    return n1; // head
}

int main() {
    Node* head = createTestList();

    cout << "Original multilevel list: "<<endl;
    cout << "1->2->3, with 2 having child = 4->5"<<endl;

    Solution sol;
    Node* flat = sol.flatten(head);

    cout<<endl;
    cout<<"Flattened list: "<<endl;
    printList(flat);

    return 0;
}