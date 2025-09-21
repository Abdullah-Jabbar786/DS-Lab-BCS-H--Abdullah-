#include <iostream>
using namespace std;

int ackerman(int m, int n)
{
    if(m==0) return n+1;
    if(m>0 && n==0) return ackerman(m-1, 1);
    if(m>0 && n>0) return ackerman(m-1, ackerman(m, n-1)); 

    return 0;
}

int main()
{
    cout<<ackerman(2,2);

    // ackerman(1,2) traced below with answer being 4.
    
    return 0;
}

// Tracing The Execution.
/*
    ackerman(1,2);

    A(1,2) = A(0, A(1,1))
    A(1,1) = A(0, A(1,0))
    A(1,0) = A(0,1)  // rule m>0, n=0
        = 2
    A(1,1) = A(0, 2)
       = 3
    A(1,2) = A(0, 3)
       = 4  (Ans).
*/