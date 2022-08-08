//https://leetcode.com/problems/search-a-2d-matrix/
//Time complexity : O(log(mn)) ,where m->no. of rows,n->no. of columns
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0;
        int row=matrix.size();
        int col=matrix[0].size();
        int end=(row*col)-1;
        while(start<=end)
        {
            int mid=start +(end-start)/2;
            int element=matrix[mid/col][mid % col];
            if(element==target)
            {return true;}
            else if (element<target)
            {
                start=mid+1;
            }
            else  //if(element>target)
            {end=mid-1;}
        }
        return false;
    }
};
// 4 4
// 10 20 30 40 15 25 35 45 27 29 37 48 32 33 39 50
// 37