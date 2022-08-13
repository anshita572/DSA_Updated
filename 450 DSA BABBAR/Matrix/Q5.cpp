//https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1

//TC :O(N^2 log(N))
//SC :O(N^2)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
      //Copy elements of 2D matrix into a 1D array
      vector<int>temp;
      for(int i=0;i<N;i++)
      {
          for(int j=0;j<N;j++)
          {
              temp.push_back(Mat[i][j]);
          }
      }
      sort(temp.begin(),temp.end());
      int k=0;
      for(int i=0;i<N;i++)
      {
          for(int j=0;j<N;j++)
          {Mat[i][j]=temp[k++];}
      }
      return Mat;
    }
};