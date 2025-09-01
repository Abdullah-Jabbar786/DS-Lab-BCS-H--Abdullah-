#include <iostream>
using namespace std;

int main()
{
    int rows1, cols1;
    int i;
    cout<<"Enter Matrix Rows: ";
    cin>>rows1;
    cout<<"Enter Matrix Cols: ";
    cin>>cols1;
    int **arr1 = new int*[rows1];
    for(i=0; i<rows1; i++)
    {
        arr1[i] = new int[cols1];
    }
    
    int rows2, cols2;
    cout<<"Enter Matrix 2 Rows: ";
    cin>>rows2;
    cout<<"Enter Matrix 2 Cols: ";
    cin>>cols2;
    int **arr2 = new int*[rows2];
    for(i=0; i<rows2; i++)
    {
        arr2[i] = new int[cols2];
    }
    
    cout<<"Enter Matrix 1 values..."<<endl;
    for(i=0; i<rows1; i++)
    {
        for(int j=0; j<cols1; j++)
        {
            cout<<"Element ["<<i<<"]["<<j<<"]: ";
            cin>>arr1[i][j];
        }
    }
    cout<<"Enter Matrix 2 values..."<<endl;
    for(i=0; i<rows2; i++)
    {
        for(int j=0; j<cols2; j++)
        {
            cout<<"Element ["<<i<<"]["<<j<<"]: ";
            cin>>arr2[i][j];
        }
    }
    
    
    
    if(rows1==rows2 && cols1==cols2)
    {
        //Allocation of Sum and Subtraction of array.
        int **sum = new int*[rows2];
        int **sub = new int*[rows2];
        for(i=0; i<rows2; i++)
        {
            sum[i] = new int[cols2]();
            sub[i] = new int[cols2]();
        }

        for(i=0; i<rows2; i++)
        {
            for(int j=0; j<cols2; j++)
            {
                sum[i][j] += arr1[i][j] + arr2[i][j]; // Addition of arr1 and arr2.
                sub[i][j] = arr1[i][j] - arr2[i][j]; // Subtractiom of arr1 - arr2.
            }
        }
        cout<<"Displaying Sum of arr1 and arr2: "<<endl;
        for(i=0; i<rows2; i++)
        {
            for(int j=0; j<cols2; j++)
            {
                cout<<sum[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"Displaying difference of arr1 and arr2: "<<endl;
        for(i=0; i<rows2; i++)
        {
            for(int j=0; j<cols2; j++)
            {
                cout<<sub[i][j]<<" ";
            }
            cout<<endl;
        }

        for(i=0; i<rows1; i++)
        {
            delete[] sum[i];
            delete[] sub[i];
        }
        delete[] sum;
        delete[] sub;        
    }
    else{
        cout<<"Addition and Substraction is not possible!"<<endl;
    }

    for(i=0; i<rows1; i++)
    {
        delete[] arr1[i];
    }
    delete[] arr1;

    for(i=0; i<rows2; i++)
    {
        delete[] arr2[i];
    }
    delete[] arr2;

    return 0;
}