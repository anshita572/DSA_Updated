#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool isSafe(int x,int y,int board[4][4],bool visited[4][4])
{   int rowSize=4;
    int colSize=4;
    if((x>=0 && x<4)&& (y>=0 && y<4)&& (visited[x][y]==false) && (board[x][y]==1))
    {return true;}
    return false;
}
bool solve(int src_x,int src_y,int dest_x,int dest_y,int board[4][4],bool visited[4][4])
{//base case
if(src_x==dest_x && src_y==dest_y)
{return true;}
//DOWN
bool downAns=false;
int newx=src_x+1;
int newy=src_y;
if(isSafe(newx,newy,board,visited))
{ visited[newx][newy]=true;
    downAns=solve(newx,newy,dest_x,dest_y,board,visited);
    visited[newx][newy]=false; //backtrack
}
//RIGHT
bool rightAns=false;
 newx=src_x;
 newy=src_y+1;
if(isSafe(newx,newy,board,visited))
{ visited[newx][newy]=true;
    rightAns=solve(newx,newy,dest_x,dest_y,board,visited);
    visited[newx][newy]=false; //backtrack
}
//LEFT
bool leftAns=false;
 newx=src_x;
 newy=src_y-1;
if(isSafe(newx,newy,board,visited))
{ visited[newx][newy]=true;
    leftAns=solve(newx,newy,dest_x,dest_y,board,visited);
    visited[newx][newy]=false; //backtrack
}
//UP
bool upAns=false;
 newx=src_x-1;
 newy=src_y;
if(isSafe(newx,newy,board,visited))
{ visited[newx][newy]=true;
    upAns=solve(newx,newy,dest_x,dest_y,board,visited);
    visited[newx][newy]=false; //backtrack
}
if(downAns || rightAns || leftAns || upAns)
{return true;}
else
{return false;}
}
int main(){
int board[4][4]={{1,1,1,0},
                 {1,1,1,0},
                 {1,1,1,0},
                 {1,1,1,0}   };
bool visited[4][4];
for(int i=0;i<4;i++)
{
    for(int j=0;j<4;j++)
    {visited[i][j]=false;}
}
visited[0][0]=true;
int src_x=0;
int src_y=0;
int dest_x=3;
int dest_y=3;
bool ans=solve(src_x,src_y,dest_x,dest_y,board,visited);
return 0;
}