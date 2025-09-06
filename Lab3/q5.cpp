#include <iostream>
using namespace std;

class ListNode
{
    public:
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr){}     
        ListNode(int x, ListNode* next) : val(x), next(next){}     
};

class Doubly
{
    public:
        int val;
        Doubly* next;
        Doubly* prev;
        Doubly(int x) : val(x), next(nullptr), prev(nullptr) {}     
        Doubly(int x, Doubly* next, Doubly* prev) : val(x), next(next), prev(prev) {}     
};

Doubly* convert_doubly(ListNode* head)
{
    if(!head) return nullptr;

    //Copying and making a Doubly LL
    Doubly* newHead = new Doubly(head->val);
    Doubly* temp = newHead;
    ListNode* curr = head->next; //Second Node

    while(curr)
    {
        Doubly* newNode = new Doubly(curr->val);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
        curr = curr->next;
    }
    return newHead;
}

ListNode* convert_circular(ListNode* head)
{
    if(!head) return nullptr;

    ListNode* curr = head;

    while(curr->next)
    {
        curr=curr->next;
    }
    curr->next=head;
    return head;
}

void Display(ListNode* head)
{
    ListNode* curr = head;
    while(curr)
    {
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

void printDoubly(Doubly* head)
{
    Doubly* curr = head;
    while(curr)
    {
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

void printCircular(ListNode* head, int n)
{
    ListNode* curr = head;
    for(int i=0; i<n; i++) // N nodes to show circular connection between last and first node.
    {
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    cout<<endl;
}


int main()
{
    // Sample
    ListNode* x = new ListNode(3);
    ListNode* y = new ListNode(2, x);
    ListNode* z = new ListNode(1, y);
    ListNode* head = z;

    cout<<"Initial Singly List: ";
    Display(head);


    Doubly* doubly_head = convert_doubly(head);
    cout<<"Converted Doubly List: ";
    printDoubly(doubly_head);

    ListNode* circular_head = convert_circular(head);
    cout<<"Converted Circular List: ";
    printCircular(circular_head, 6);
    return 0;
}