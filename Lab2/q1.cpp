#include <iostream>
using namespace std;

int main()
{
    int size, i=0;
    char choice;

    cout<<"Enter Array size: ";
    cin>>size;

    int *arr = new int[size]();

    do
    {
        int pos, val;
        cout<<"Enter position (0 to "<<size-1<<"): ";
        cin>>pos;

        if(pos>=0 && pos<size)
        {
            cout<<"Enter value: ";
            cin>>val;
            arr[pos]=val;
        }
        else
        {
            cout<<"Invalid position!"<<endl;
        }

        cout<<"Do you want to update any other position? (y/n):";
        cin>>choice;

    } while(choice=='y' || choice=='Y');

    for(i=0; i<size; i++)
    {
        cout<<"Array["<<i+1<<"]: "<<arr[i]<<endl;
    }

    delete []arr;
    return 0;
}
