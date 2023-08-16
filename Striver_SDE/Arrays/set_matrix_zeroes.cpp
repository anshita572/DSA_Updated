// https://leetcode.com/problems/set-matrix-zeroes/description/
// M1 : brute force : TC : O(m*n) , SC : O(m+n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>row(n,0);
        vector<int>col(m,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
         for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(row[i] == 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// M2 : Optimal : TC : O(m*n) , SC : O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j != 0){
                        matrix[0][j] = 0;
                    }
                    else{
                        col0 = 0;
                    }
                    
                }
            }
        }
         for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] != 0){
                    if(matrix[i][0] == 0){
                        matrix[i][j] = 0;
                    }
                    if(matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                }
                
            }
        }
        // first of all ,mark 1st row and then 1st col
        if(matrix[0][0] == 0){
            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }
        // if we have only 1 col ,eg : [[1],[0]] , then will never enter the above loop where j=1 ... , hence checking here of col0
            if(col0 == 0){
                for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
         }
        
    }
};