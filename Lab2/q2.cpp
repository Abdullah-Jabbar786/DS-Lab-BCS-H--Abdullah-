#include <iostream>
using namespace std;

int main()
{
    int rows, cols, i=0, j=0;
    char choice;

    cout<<"Enter Rows(benches): ";
    cin>>rows;
    cout<<"Enter Cols(seats): ";
    cin>>cols;

    int **arr = new int*[rows];
    for(i=0; i<rows; i++)
    {
        arr[i] = new int[cols]();
    }

    do
    {
        int pos1,pos2,val;
        cout<<"Enter bench index (0-"<<rows-1<<"): ";
        cin>>pos1;
        cout<<"Enter seat index (0-"<<cols-1<<"): ";
        cin>>pos2;

        if(pos1>=0 && pos1<rows && pos2>=0 && pos2<cols)
        {
            cout<<"Enter (1 for occupied): ";
            cin>>val;
            arr[pos1][pos2]=val;
        }
        else
        {
            cout<<"Invalid position!"<<endl;
        }

        cout<<"Do you want to update any other position? (y/n):";
        cin>>choice;

    } while(choice=='y' || choice=='Y');

    cout<<"\nFinal Seating Chart (0 = Empty, 1 = Occupied):"<<endl;
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            cout<<"Array["<<i+1<<"]["<<j+1<<"]:"<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for(int i=0; i<rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}