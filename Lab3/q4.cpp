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

int josephus(int n, int k)
{
    ListNode* head = new ListNode(1);
    ListNode* prev = head;

    for(int i=2; i<=n; i++)
    {
        prev->next = new ListNode(i);
        prev = prev->next;
    }
    prev->next = head; // circular

    ListNode* temp = head;
    ListNode* last = prev;

    while(temp->next != temp)
    {
        //reaching node before k
        for (int i=1; i<k; i++)
        {
            last = temp;
            temp = temp->next;
        }
        
        last->next = temp->next;
        delete temp;
        temp = last->next;
    }

    int survivor = temp->val;
    delete temp;
    return survivor;
}

int main()
{
    int n = 7, k = 3;
    cout<<"Survivor Position: "<<josephus(n, k)<<endl;

    return 0;
}