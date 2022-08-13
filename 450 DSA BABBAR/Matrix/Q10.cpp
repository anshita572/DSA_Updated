//https://www.codingninjas.com/codestudio/problems/common-elements-present-in-all-rows-of-a-matrix_1118111?leftPanelTab=0

//TC : O(n*m) , SC :O(m)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> findCommonElements(vector<vector<int>> &mat)
{   vector<int> ans;
    int row=mat.size();
    int col=mat[0].size();
    unordered_map<int,int>mp;
  //push 1st row elements in map 
    for(int j=0;j<col;j++)
    {mp[mat[0][j]]=1;} //Set frequency of all elements of 1st row=1
   for(int i=1;i<row;i++)//start checking from next row (i=1)
   {
       for(int j=0;j<col;j++)
       {
           if(mp[mat[i][j]]==i) // i represents frequency
           {mp[mat[i][j]]=i+1;}
       }
   }
  for(auto it: mp)
    {
        if(it.second == row) //if frequency == last row
            ans.push_back(it.first); //push that number
    }
 return ans;
}