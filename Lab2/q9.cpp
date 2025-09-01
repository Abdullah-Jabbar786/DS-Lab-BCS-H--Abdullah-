#include<iostream>
using namespace std;

int main(){
    int rows,cols;
    cout<<"Enter number of rows:";
    cin>>rows;
    cout<<"Enter number of columns:";
    cin>>cols;

    int **mat=new int*[rows];
    for(int i=0; i<rows; i++){
        mat[i]=new int[cols];
    }

    cout<<"Enter matrix elements:"<<endl;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){     
            cout<<"Element["<<i<<"]["<<j<<"]: ";
            cin>>mat[i][j];
        }
    }

    cout<<"\nMatrix in Normal Form:"<<endl;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"\nMatrix in Compressed Form(row,col,value): "<<endl;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(mat[i][j]!=0){
                cout<<"("<<i<<","<<j<<","<<mat[i][j]<<")"<<endl;
            }
        }
    }
    return 0;
}