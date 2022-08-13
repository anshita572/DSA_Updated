//https://www.codingninjas.com/codestudio/problems/find-a-specific-pair-in-the-matrix_1115467?leftPanelTab=0

//TC :O(n^2) , SC :O(n^2)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int findMaxValue(vector<vector<int>>& mat, int n) {
	int ans=INT_MIN;
    int maxArr[n][n];
    maxArr[n-1][n-1]=mat[n-1][n-1];
    int maxi=mat[n-1][n-1];
    //preprocess last row
    for(int j=n-2;j>=0;j--)
    {
        if(mat[n-1][j]>maxi)
        {maxi=mat[n-1][j];}
        maxArr[n-1][j]=maxi;
    }
    //preprocess last column
    maxi=mat[n-1][n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(mat[i][n-1]>maxi)
        {maxi=mat[i][n-1];}
        maxArr[i][n-1]=maxi;
    }
    //preprocess remaining rows and columns
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            if((maxArr[i+1][j+1]-mat[i][j]) > ans)
            {ans=maxArr[i+1][j+1]-mat[i][j];}
            maxArr[i][j]=max((mat[i][j]),max(maxArr[i+1][j],maxArr[i][j+1]));
        }
    }
    return ans;
}