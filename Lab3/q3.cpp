#include <iostream>
using namespace std;


class ListNode 
{
    public:
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        int count=0;

        while(count<k)
        {
            if(temp==NULL) return head;
            count++;
            temp = temp->next;
        }


        prev = reverseKGroup(temp, k);

        temp = head;
        ListNode* next = NULL;
        count = 0;

        //Reversing k nodes.
        while(count<k)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
        }
        return prev;
    }
};

// linked list from array
ListNode* createList(int arr[], int n)
{
    if(n==0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i=1; i<n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printList(ListNode* head) 
{
    while(head!=nullptr){
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}


int main() {
    Solution sol;
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = 8;
    int k = 3;

    ListNode* head = createList(arr, n);

    cout<<"Original list: ";
    printList(head);

    head = sol.reverseKGroup(head, k);

    cout<<"Reversed in groups of "<<k<<": ";
    printList(head);

    return 0;
}