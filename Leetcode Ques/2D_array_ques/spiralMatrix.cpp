// leetcode.com/problems/spiral-matrix/
//Time Complexity: O(m*n)
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;  //Constraints: m == matrix.length and n == matrix[i].length
                         //(given in ques)
        int row=matrix.size();
        int col=matrix[0].size();
        
        int startingRow=0;
        int startingCol=0;
        int endingRow=row-1;
        int endingCol=col-1;
        //These 4 are indexes
        int totalElements =row*col;
        int count=0;
        while(count<totalElements)
        {
            //printing first row
            for(int i=startingCol;i<=endingCol && count<totalElements;i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            //printing ending column
            for(int i=startingRow;i<=endingRow && count<totalElements;i++)
            {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            //printing ending row
            for(int i=endingCol;i>=startingCol && count<totalElements;i--)
            {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            //printing starting column
            for(int i=endingRow;i>=startingRow && count<totalElements;i--)
            {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};