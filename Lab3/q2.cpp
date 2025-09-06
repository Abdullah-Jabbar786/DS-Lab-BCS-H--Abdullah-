#include <iostream>
using namespace std;


class ListNode {
    public: 
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }

        if(list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
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
    int arr1[] = {1, 2, 4, 5};
    int arr2[] = {1, 7, 10, 13}; 

    ListNode* head1 = createList(arr1, 4); // 4 nodes
    ListNode* head2 = createList(arr2, 4); // 4 nodes

    cout<<"List 1: ";
    printList(head1);

    cout<<"List 2: ";
    printList(head2);

    ListNode* merged = sol.mergeTwoLists(head1, head2);

    cout<<"Merged List: ";
    printList(merged);

    return 0;
}