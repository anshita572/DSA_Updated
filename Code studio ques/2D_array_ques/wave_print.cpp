//https://bit.ly/329Le3K
//Time Complexity: O(m*n)
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{vector<int>ans;
    for(int col=0;col<mCols;col++)
    {
        if(col % 2==0)  //even no. of column index
            //Traversing top to bottom
      
        {
            for(int row=0;row<nRows;row++)
            {
                ans.push_back(arr[row][col]);
            }
        }
          else   //odd no. of column index
              //Traversing bottom to top
          {
              for(int row=nRows-1;row>=0;row--)
              {
                  ans.push_back(arr[row][col]);
              }
          }
    }
 return ans;
}

