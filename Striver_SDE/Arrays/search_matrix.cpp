// https://leetcode.com/problems/search-a-2d-matrix/description/
// Brute force : TC : O(n) , SC : O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool binarySearch(vector<int>&arr,int s, int e,int target){
        
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(arr[mid] == target){
                return true;
            }
            else if(arr[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            int s = 0;
            int e = m-1;
            bool ans = binarySearch(matrix[i],s,e,target);
            if(ans == true){
                return true;
            }
        }
        return false;
    }
};
// Optimal : TC : O(log(n*m)) , SC : O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int s = 0;
        int e = (n*m) - 1;
        while(s <= e){
            int mid = s + (e - s)/2;
            int row = mid / m;
            int col = mid % m;
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return false;
    }
};