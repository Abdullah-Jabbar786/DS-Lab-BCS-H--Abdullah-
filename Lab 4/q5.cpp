#include <iostream>
using namespace std;

int interpolation_search(int arr[], int n, int target) {
    int low = 0, high = n-1;
    while(low <= high && target >= arr[low] && target <= arr[high]) 
    {
        int pos = low + ((double)(target - arr[low])*(high - low))/(arr[high] - arr[low]);
        if(arr[pos]==target) return pos;
        if(arr[pos]<target) low=pos + 1;
        else high=pos - 1;
    }
    return -1;
}

int main()
{
    int n, target;
    cout<<"Enter the number of elements (sorted, uniformly distributed): ";
    cin>>n;
    int* arr = new int[n];
    cout<<"Enter "<<n<<" sorted elements:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"arr["<<i<<"]: ";
        cin>>arr[i];
    }
    cout<<"Enter the element you want to search: ";
    cin>>target;
    int result = interpolation_search(arr, n, target);
    if(result != -1)
    {
        cout<<"Element found at index: "<<result<<" with index staring from 0."<<endl;
    }
    else
    {
        cout<<"Element not found in the array."<<endl;
    }

    delete[] arr;
    return 0;
}