#include <iostream>
#include <strings.h>
using namespace std;

class Exam
{
    private:
    char* Name;
    char* Date;
    int Score;

    public:
    Exam(const char* name, const char* date, int s) 
    {
        Name = new char[strlen(name) + 1];
        strcpy(Name, name);

        Date = new char[strlen(date) + 1];
        strcpy(Date, date);

        Score = s;
    }

    void Set(const char* name, const char* date, int s) 
    {
        Name = new char[strlen(name) + 1];
        strcpy(Name, name);

        Date = new char[strlen(date) + 1];
        strcpy(Date, date);

        Score = s;
    }

    void Display()
    {
        cout<<"Displaying Exam Details."<<endl;
        cout<<"Name: "<<Name<<endl;
        cout<<"Exam Date: "<<Date<<endl;
        cout<<"Student Score: "<<Score<<endl;
    }

    ~Exam()
    {
        delete[] Name;
        delete[] Date;
    }
    //Runtime Error because two destructors try to delete same memory.

};

int main()
{
    Exam e1("Abdullah", "23-08-2025", 88);

    cout << "Original Object(e1) : " << endl;
    e1.Display();

    // Shallow copy (default copy constructor)
    Exam e2 = e1;

    cout<<"\nCopied Object (e2) : "<<endl;
    e2.Display();

    return 0;
}