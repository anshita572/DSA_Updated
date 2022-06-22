//Pair Sum [https://bit.ly/3EwlU6e ]
vector<vector<int>> pairSum(vector<int> &arr, int s){
    int n=arr.size();
    vector<vector<int>>ans;
   for(int i=0;i<n;i++)
   {for(int j=i+1;j<n;j++)
    {
        if(arr[i]+arr[j]==s)
        {vector<int>temp;
        temp.push_back(min(arr[i],arr[j]));//e.g suppose ans is 4,1 so it has to be sorted.min is 1
        temp.push_back(max(arr[i],arr[j]));//max is 4,so 1,4
            ans.push_back(temp);

         }
    }
   }
     sort(ans.begin(), ans.end());//e.g. 2,3 and 1,4 ,so sort it : 1,4 and 2,3
     return ans;
   }
   