#include <iostream>
using namespace std;
#define N 5

bool is_Valid(int grid[N][N], int row, int col, int path[N][N]) 
{
    return (row>=0 && row<N && col>=0 && col<N && grid[row][col]==1 && path[row][col]==0);
}

bool solveMaze(int grid[N][N], int row, int col, int path[N][N])
 {
    if (row==N-1 && col==N-1) 
    {
        path[row][col]=1;
        return true;
    }

    if (is_Valid(grid,row,col,path)) 
    {
        path[row][col]=1;
        if(solveMaze(grid,row+1,col,path)) return true;
        if(solveMaze(grid,row,col+1,path)) return true;
        if(solveMaze(grid,row-1,col,path)) return true;
        if(solveMaze(grid,row,col-1,path)) return true;
        path[row][col]=0;
        return false;
    }
    return false;
}

void print(int path[N][N]) 
{
    for (int i=0;i<N;i++) 
    {
        for(int j=0;j<N;j++) cout<<path[i][j]<<" ";
        cout<<endl;
    }
}

int main() 
{
    int maze[N][N]=
    {
        {1,0,0,0,0},
        {1,1,0,1,0},
        {0,1,0,1,0},
        {1,1,1,1,0},
        {0,0,0,1,1}
    };

    int solution[N][N]={0};

    if(solveMaze(maze,0,0,solution)) print(solution);
    
    else cout<<"No path found"<<endl;

    return 0;
}
