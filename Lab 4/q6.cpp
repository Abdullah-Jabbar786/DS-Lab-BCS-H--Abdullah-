#include <iostream>
using namespace std;

void comb_sort(int arr[], int n) 
{
    int gap=n;
    bool swapped=true;
    int comparisons = 0, swaps = 0;

    while(gap!=1 || swapped) 
    {
        // Shrink factor ~1.3
        gap = (gap*10)/13;
        if(gap<1) gap = 1;
        swapped = false;

        for (int i=0; i+gap<n; i++) 
        {
            comparisons++;
            if (arr[i]>arr[i+gap]) 
            {
                swap(arr[i], arr[i + gap]);
                swaps++;
                swapped = true;
            }
        }
    }

    // Display sorted array
    cout<<"Sorted array:"<<endl;
    for(int i=0; i<n; i++) 
    {
        cout<<"Element["<<i<<"]: "<<arr[i]<<endl;
    }
    cout<<endl;

    // Display complexity 
    cout<<"Total comparisons: "<<comparisons<<endl;
    cout<<"Total swaps: "<<swaps<<endl;
}

int main() {
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int* arr = new int[n];
    cout<<"Enter "<<n<<" elements:"<<endl;
    for(int i=0; i<n; i++) 
    {
        cout<<"arr["<<i<<"]: ";
        cin>>arr[i];
    }

    comb_sort(arr, n);

    delete[] arr;
    return 0;
}
