#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter Months: ";
    cin>>n;
    int *arr=new int[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cout<<"Enter Expense "<<i+1<<": ";
        cin>>arr[i];
        sum+=arr[i];
    }
    char choice;
    do{
        cout<<"Do you want to track more months?(y/n): ";
        cin>>choice;
        if(choice=='y'||choice=='Y'){
            int extra;
            cout<<"Enter how many more months: ";
            cin>>extra;
            int new_n=n+extra;
            int *newArr=new int[new_n];
            for(int i=0;i<n;i++){
                newArr[i]=arr[i];
            }
            for(int i=n;i<new_n;i++){
                cout<<"Enter Expense "<<i+1<<": ";
                cin>>newArr[i];
                sum+=newArr[i];
            }
            delete[] arr;
            arr=newArr;
            n=new_n;
        }
    }while(choice=='y'||choice=='Y');

    cout<<"\nTotal Expenses: "<<sum<<endl;
    cout<<"Average Expenses: "<<(double)sum/n<<endl;

    delete[] arr;
    return 0;
}