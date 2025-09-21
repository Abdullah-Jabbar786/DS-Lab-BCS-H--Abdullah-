#include <iostream>
using namespace std;

int CalculateFactorial(int n)
{
    if(n==0 || n==1) return 1;
    return n* CalculateFactorial(n-1);
}

int main()
{
    int x = CalculateFactorial(4);
    cout<<x;
   
    return 0;
}
