#include <iostream>
using namespace std;

// 1.
int sumTail(int n, int total)
{
    if(n==0) return total;
   
    total += n;
   
    return sumTail(n-1, total);
}

//2.
int sumNonTail(int n)
{
    if(n==0) return n;
   
    return n + sumNonTail(n-1);
}

// Comparison

// Tail recursion has the recursive call as the very last operation, so the compiler can optimize it to reuse the same stack frame (called tail call optimization), reducing memory usage.

// Non-tail recursion performs operations after the recursive call returns, which means every call must wait for deeper calls to finish and thus builds up a stack frame for each call, using more memory.

// Difference in their call stacks.

// Tail recursion:
// The recursive call is the last operation, allowing the compiler to reuse the same stack frame. This results in constant memory usage (O(1)).

// Non-tail recursion:
// The function performs operations after the recursive call returns, so each call must keep its stack frame until all deeper calls finish. This leads to linear memory usage (O(n)).

int main()
{
    int result;
    result = sumTail(3,0);
    cout<<result<<endl;
   
    result = sumNonTail(3);
    cout<<result<<endl;
   
    return 0;
}