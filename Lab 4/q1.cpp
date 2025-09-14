#include <iostream>
using namespace std;

void linear_search(int arr[], int n, int target)
{
    bool found = false;
    for (int i=0; i<n; i++)
    {
        if(arr[i]==target)
        {
            cout<<"Element found at "<<i<<" with index starting from 0."<<endl;
            found = true;
            break;
        }
    }
    if(!found)
    {
        cout<<"Element is not in the array."<<endl;
    } 
}

int main()
{
    int n,target;
    cout<<"Enter the number of elements you want: ";
    cin>>n;
    int* arr = new int[n];

    for (int i=0; i<n; i++)
    {
        cout<<"Enter arr["<<i+1<<"]: ";
        cin>>arr[i];
    }
    cout<<"Enter the element you want to find: ";
    cin>>target;

    linear_search(arr,n, target);
    
    delete[] arr;
    return 0;
}
