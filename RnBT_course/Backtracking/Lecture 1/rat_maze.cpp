#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool isSafe(int src_x,int src_y,vector<vector<char>>&board,vector<vector<bool>>&visited)
{
    int rowSize=board.size();
    int colSize=board[0].size();
    if(visited[src_x][src_y]==false && (src_x>=0 && src_x<colSize) && (src_y>=0 && src_y < rowSize) && board[src_x][src_y]=='.')
    {return true;}
    return false;
}
bool solve(int src_x,int src_y,int dest_x,int dest_y,vector<vector<char>>&board,vector<vector<bool>>&visited)
{
    //base case
    if(src_x==dest_x && src_y==dest_y)
    {return true;}
    //Down
    bool downAns=false;
    int new_x=src_x+1;
    if(isSafe(new_x,src_y,board,visited))
    {      visited[new_x][src_y]=true;
        downAns=solve(new_x,src_y,dest_x,dest_y,board,visited);
           visited[new_x][src_y]=false;
 }
 //Right
  bool rightAns=false;
  int new_y=src_y+1;;
    if(isSafe(src_x,new_y,board,visited))
    {      visited[src_x][new_y]=true;
        rightAns=solve(src_x,new_y,dest_x,dest_y,board,visited);
           visited[src_x][new_y]=false;
 }
 //Left
  bool leftAns=false;
   new_y=src_y-1;
    if(isSafe(src_x,new_y,board,visited))
    {      visited[src_x][new_y]=true;
        leftAns=solve(src_x,new_y,dest_x,dest_y,board,visited);
           visited[src_x][new_y]=false;
 }
 //Up
  bool upAns=false;
   new_x=src_x-1;
    if(isSafe(new_x,src_y,board,visited))
    {      visited[new_x][src_y]=true;
        upAns=solve(new_x,src_y,dest_x,dest_y,board,visited);
           visited[new_x][src_y]=false;
 }
 if(downAns || rightAns || leftAns || upAns)
 {return true;}
 return false;
}
int main(){
int srcx = 0;
    int srcy = 0;

    int destx = 3;
    int desty = 3;

    vector<vector<char> > board(4, vector<char>(4,'.'));
    board[0][3] = '*';
    board[1][1] = '*';
    //board[2][1] = '*';
    board[1][2] = '*';
    board[3][1] = '*';

    vector<vector<bool> > visited(4, vector<bool>(4,false));
    visited[0][0] = true;


    cout << "Printing the board" << endl;
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            cout << board[i][j] << " ";
        }cout << endl;
    }


    cout << "Printing the Visited array" << endl;
    for(int i=0; i<visited.size(); i++) {
        for(int j=0; j<visited[i].size(); j++) {
            cout << visited[i][j] << " ";
        }cout << endl;
    }

    //string output = "";

    bool ans = solve(srcx, srcy, destx, desty, board, visited);
    cout << "Src to Dest is possible or not " << ans << endl;

return 0;
}
