#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    // Displaying Array after Sorting.
    cout<<"Displaying sorted array."<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<"Element["<<i<<"]: "<<arr[i]<<endl;
    }    
    cout<<endl;
}

int binary_search(int arr[], int n, int target)
{
    int low = 0, high = n-1;
    while(low<=high) 
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == target)
        {
        return mid;
        }
        else if(arr[mid]<target) 
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n,target;
    cout<<"Enter the number of elements you want: ";
    cin>>n;
    int* arr = new int[n];
    
    for(int i=0; i<n; i++)
    {
        cout<<"Enter arr["<<i<<"]: ";
        cin>>arr[i];
    }

    cout<<"Enter the element you want to find: ";
    cin>>target;

    insertion_sort(arr, n);
    int result = binary_search(arr, n, target);
    if(result==-1)
    {
        cout<<"Element not found."<<endl;
    }
    else
    {
        cout<<"Element found at index: "<<result<<" with index starting from 0."<<endl;
    }
    
    delete[] arr;
    return 0;
}