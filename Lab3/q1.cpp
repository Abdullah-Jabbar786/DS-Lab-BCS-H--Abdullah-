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
    bool isPalindrome(ListNode* head) {
        
        ListNode* temp = head;
        ListNode* slow=head;
        ListNode* fast=head;
        if(temp->next==nullptr) return true;
        if(temp->next->next==nullptr)
        {
            if(temp->val==temp->next->val) return true;
            else return false;
        }

        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = slow->next; // Node after Mid.
        ListNode* next = NULL;

        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
      
        while(prev!=nullptr)
        {
            if(temp->val!=prev->val) return false;
            temp=temp->next;
            prev=prev->next;
        }
        return true;
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


int main()
{
    Solution sol;
    int arr1[] = {1, 2, 2, 1}; // sample 1

    ListNode* head1 = createList(arr1, 4); // 4 nodes
    cout<<"List 1: ";
    printList(head1);
    if(sol.isPalindrome(head1))
    {
        cout<<"Palindrome"<<endl;
    }
    else
    {
        cout<<"Not Palindrome"<<endl;
    }

    int arr2[] = {1, 2, 3}; // sample 2
    ListNode* head2 = createList(arr2, 3);
    cout<<"List 2: ";
    printList(head2);
    if(sol.isPalindrome(head2))
    {
        cout<<"Palindrome"<<endl;
    }
    else
    {
        cout<<"Not Palindrome"<<endl;
    }
    return 0;
}
