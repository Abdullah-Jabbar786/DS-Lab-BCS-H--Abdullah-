#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n)
{
    int temp;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n-1; j++){
            if (arr[j]>arr[j + 1]){
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;}
        }
    }

    // Displaying Array after Sorting.
    cout<<"Displaying sorted array."<<endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; i<n; i++)
        {
            cout<<"Element["<<i<<"]: "<<arr[i]<<endl;
        } 
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
        cout<<"Enter arr["<<i<<"]: ";
        cin>>arr[i];
    }
    
    // Displaying Array.
    cout<<"Displaying unsorted array."<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<"Element["<<i<<"]: "<<arr[i]<<endl;
    }

    bubble_sort(arr, n);
    
    delete[] arr;
    return 0;
}