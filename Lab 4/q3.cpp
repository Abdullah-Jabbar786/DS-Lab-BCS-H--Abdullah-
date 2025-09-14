#include <iostream>
using namespace std;

void selection_sort(int arr[], int n)
{
    int temp;
    for (int i = 0; i<n-1; i++){
        int min_i = i;
        for (int j = i+1; j<n; j++){
            if (arr[j]<arr[min_i]){
                min_i = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_i];
        arr[min_i] = temp;
    }

    // Displaying Array after Sorting.
    cout<<"Displaying sorted array."<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<"Element["<<i<<"]: "<<arr[i]<<endl;
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

    selection_sort(arr, n);
    
    delete[] arr;
    return 0;
}