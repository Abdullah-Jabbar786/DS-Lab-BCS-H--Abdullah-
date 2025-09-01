#include <iostream>
using namespace std;

int main()
{
    int rows = 3, cols;
    cout<<"Enter Number of Students: "<<rows<<endl;

    int **arr = new int*[rows];
    int Size[3];
    
    double Avg[3] = {0};

    for(int i=0; i<rows; i++)
    {
        cout<<"Student "<<i+1<<": "<<"Enter Number of courses enrolled: ";
        cin>>Size[i];
        arr[i] = new int[Size[i]];
    }
    for(int i=0; i<rows; i++)
    {
        int sum = 0;
        cout<<"Student "<<i+1<<": "<<endl;
        for (int j=1; j<=Size[i];j++)
        {
            cout<<"Enter Course "<<j<<" Marks: ";
            cin>>arr[i][j];
            sum += arr[i][j];
        }
        Avg[i] = sum / Size[i];
        cout<<endl;
    }

    for(int i=0; i<rows; i++)
    {
        cout<<"Student "<<i+1<<" Average: "<<Avg[i]<<endl;
    }

    for (int i = 0; i < rows; i++)
    {
        delete arr[i];
    }
    delete[] arr;

    return 0;
}