#include <iostream>
using namespace std;

class Safe_Pointer
{
    private:
    int *ptr;

    public:
    Safe_Pointer()
    {
        ptr = new int;
    }

    void setValue(int val)
    {
        *ptr = val;
    }
    
    int getValue()
    {
        return *(ptr);
    }

    void release()
    {
        delete ptr;
        ptr = nullptr;
    }

    ~Safe_Pointer() 
    {
        release();
    }

};


int main()
{
    Safe_Pointer students[5];
    int x;

    for(int i=0; i<5; i++)
    {
        cout<<"Enter Student "<<i+1<<" Marks: ";
        cin>>x;
        students[i].setValue(x);
    }

    cout<<"Display Student Marks."<<endl;

    for(int i=0; i<5; i++)
    {
        cout<<"Student "<<i+1<<": "<<students[i].getValue()<<endl;
    }
    return 0;
}