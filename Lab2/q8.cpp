#include <iostream>
using namespace std;


int main()
{
    int n,m;

    cout<<"Enter number of days: ";
    cin>>n;
    cout<<"Enter number of times to store temperature readings: ";
    cin>>m;

    double **arr = new double*[n];

    for(int i=0; i<n; i++)
    {
        arr[i] = new double[m];
    }

    double *daily_avg = new double[n]();

    for(int i=0; i<n; i++)
    {
        double sum = 0;
        for(int j=0; j<m; j++)
        {
            cout<<"Enter temp "<<j+1<<" Day "<<i+1<<": ";
            cin>>arr[i][j];
            sum += arr[i][j];
        }
        cout<<endl;
        double avg = sum/m;
        daily_avg[i] = avg;
    }

    double min = daily_avg[0], maxi=0;
    double max = daily_avg[0], mini=0;
    for(int i=0; i<n; i++)
    {
        if(daily_avg[i] > max)
        {
            max = daily_avg[i];
            maxi = i;
        }
        if(daily_avg[i] < max)
        {
            min = daily_avg[i];
            mini = i;
        }
    }

    cout<<"Hottest Day "<<maxi+1<<" temperature: "<<max<<endl;
    cout<<"Coldest Day "<<mini+1<<" temperature: "<<min<<endl;

    return 0;
}