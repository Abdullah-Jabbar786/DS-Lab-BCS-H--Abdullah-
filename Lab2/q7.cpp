#include <iostream>
using namespace std;


int main()
{
    int rows;
    cout<<"Enter number of Departments: ";
    cin>>rows;

    int *deptSize = new int[rows];
    int **arr = new int*[rows];

    for (int i=0; i<rows; i++)
    {
        cout<<"Enter number of employees in Department "<<i + 1<<": ";
        cin>>deptSize[i];
        arr[i] = new int[deptSize[i]];
    }

    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<deptSize[i]; j++)
        {
            cout<<"Department "<<i + 1<<", Employee "<<j + 1<<": ";
            cin>>arr[i][j];
        }
    }

    for (int i=0; i<rows; i++)
    {
        int Max = arr[i][0];
        for (int j=1; j<deptSize[i]; j++)
        {
            if (arr[i][j]>Max)
                Max = arr[i][j];
        }
        cout<<"Highest Salary in Dept "<<i+1<<": "<<Max<<endl;
    }

    double maxAvg = 0;
    int deptIndex = -1;

    for (int i=0; i<rows; i++)
    {
        int sum = 0;
        for (int j=0; j<deptSize[i]; j++)
        {
            sum += arr[i][j];
        }
        double avg = (double)sum / deptSize[i];

        if(avg>maxAvg)
        {
            maxAvg = avg;
            deptIndex = i;
        }
    }

    cout<<"Department with Maximum Average Salary: Dept "<<deptIndex + 1<<" (Average = "<<maxAvg<<")"<<endl;


    for (int i = 0; i<rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] deptSize;

    return 0;
}