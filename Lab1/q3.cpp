#include <iostream>
using namespace std;

class Box
{
    private:
    int* val;

    public:
    Box()
    {
        val = new int;
    }

    void Set(int v)
    {
        *val = v;
    }


    ~Box()
    {
        delete val;
    }
    
    Box(const Box &B) //Deep Copy
    {
        val = new int;
        *val = *(B.val);
    }
    
    Box& operator=(const Box &B)
	{
        if(this!=&B){
            delete val;
            val = new int;
            *val = *(B.val);
		}
		return *this;
	}

    void Display()
    {
        cout<<"Value = "<<*val<<endl;
    }
};

int main()
{
    Box b1;
    b1.Set(10);
    cout<<"Original object (b1) : "; 
    b1.Display();

    // Copy constructor
    Box b2 = b1;
    cout<<"Copy constructor (b2 from b1) : "; 
    b2.Display();

    // Copy assignment
    Box b3;
    b3 = b1;
    cout<<"Copy assignment (b3 = b1) : "; 
    b3.Display();

    // Modifying b1
    b1.Set(20);
    cout<<"\nAfter modifying b1 :"<<endl;
    cout<<"b1 : "; b1.Display();
    cout<<"b2 : "; b2.Display();
    cout<<"b3 : "; b3.Display();

    return 0;
}