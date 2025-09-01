#include "iostream"
#include <string>
using namespace std;

int main(){
    int categories;
    cout<<"Enter number of categories: ";
    cin>>categories;

    string* category=new string[categories];
    int** books=new int*[categories];
    int* book_count=new int[categories]; 

    for(int i=0; i<categories; i++){
        cout<<"\nEnter name for category "<<i+1<<": ";
        cin>>category[i];

        cout<<"Enter number of books in "<<category[i]<<": ";
        cin>>book_count[i];

        books[i]=new int[book_count[i]];

        cout<<"Enter book IDs for "<<category[i]<<":\n";
        for(int j=0; j<book_count[i]; j++){
            cout<<"Book ID "<<j+1<<" : ";
            cin>>books[i][j];
        }
    }

    int searchID;
    cout<<"\nEnter book ID to search: ";
    cin>>searchID;

    bool found=false;
    for(int i=0; i<categories; i++){
        for(int j=0;j<book_count[i];j++){
            if(books[i][j]==searchID){
                cout<<"Book ID "<<searchID<<" is available in category: "<<category[i]<<endl;
                found=true;
                break;
            }
        }
    }

    if(!found){
        cout<<"Book ID "<<searchID<<" is not available in the library.\n";
    }

    for(int i=0; i<categories; i++){
        delete[] books[i];
    }
    delete[] books;
    delete[] book_count;
    delete[] category;

    return 0;
}