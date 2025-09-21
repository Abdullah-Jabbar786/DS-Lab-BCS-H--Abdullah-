#include <iostream>
using namespace std;

class Solution {
public:

    bool if_Safe(char board[10][10], int row, int col, int n)
    {  // O(n)
        //Horizontal check
        for(int j=0; j<n; j++)
        {
            if(board[row][j]=='Q') return false;
        }

        //Vertical check
        for(int i=0; i<n; i++)
        {
            if(board[i][col]=='Q') return false;
        }

        // Left Diagonal
        for(int i=row, j=col; i>=0 && j>=0; i--, j--)
        {
            if(board[i][j] == 'Q') return false;
        }

        // Right Diagonal
        for(int i=row, j=col; i>=0 && j<n; i--, j++)
        {
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void N_Queens(char board[10][10], int row, int n, char ans[100][10][10], int &count)
    {
            if(row==n) 
            {
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<n; j++)
                    {
                        ans[count][i][j] = board[i][j];
                    }
                }
                count++;
                return;
            }    

            for (int j=0; j<n; j++)
            {
                if(if_Safe(board, row, j, n))
                {
                    board[row][j] = 'Q';  
                    N_Queens(board, row+1, n, ans, count);   
                    board[row][j] = '.';  
                }
            }
            
        }

        int solveNQueens(int n, char ans[100][10][10]){
            char board[10][10];
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    board[i][j] = '.';
                }
            }
            int count = 0;
            
            N_Queens(board, 0, n, ans, count);
            return count;
        }
};


int main() {
    int n;
    cout<<"Enter No. of Queens: ";
    cin>>n;

    Solution s;
    char solutions[100][10][10];
    int total = s.solveNQueens(n, solutions);

    for (int i=0; i<total; i++)
    {
        for (int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                cout<<solutions[i][j][k];
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
