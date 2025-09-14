#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n, long long &comp, long long &swaps){
    comp=0; swaps=0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            comp++;
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swaps++;
            }
        }
    }
}

void insertion_sort(int arr[], int n, long long &comp, long long &swaps){
    comp=0; swaps=0;
    for(int i=1; i<n; i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0)
        {
            comp++;
            if(arr[j]>key)
            {
                arr[j+1]=arr[j];
                swaps++;
                j--;
            }
            else break;
        }
        arr[j+1]=key;
    }
}

void shell_sort(int arr[], int n, long long &comp, long long &swaps){
    comp=0; swaps=0;
    for(int gap=n/2; gap>0; gap/=2)
    {
        for(int i=gap;i<n;i++)
        {
            int temp=arr[i];
            int j=i;
            while(j>=gap)
            {
                comp++;
                if(arr[j-gap]>temp)
                {
                    arr[j]=arr[j-gap];
                    swaps++;
                    j-=gap;
                }
                else break;
            }
            arr[j]=temp;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int* arr = new int[n];
    cout<<"----Enter "<<n<<" elements----"<<endl;
    
    for(int i=0; i<n; i++)
    {
        cout<<"Element["<<i<<"]: ";
        cin>>arr[i];
    }

    int* arr1 = new int[n];
    int* arr2 = new int[n];
    int* arr3 = new int[n];

    for(int i=0;i<n;i++)
    {
        arr1[i]=arr2[i]=arr3[i]=arr[i];
    }

    long long c1,s1,c2,s2,c3,s3;

    bubble_sort(arr1,n,c1,s1);
    insertion_sort(arr2,n,c2,s2);
    shell_sort(arr3,n,c3,s3);

    cout<<"\nBubble Sort -> Comparisons: "<<c1<<", Swaps: "<<s1<<endl;
    cout<<"Insertion Sort -> Comparisons: "<<c2<<", Swaps: "<<s2<<endl;
    cout<<"Shell Sort -> Comparisons: "<<c3<<", Swaps: "<<s3<<endl;

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}
