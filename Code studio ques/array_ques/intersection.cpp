//Array Intersection [https://bit.ly/3Il0c7n ]

//Method-2 : Optimised
//Time Complexity : O(n+m)
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int i=0;
    int j=0;
 vector<int>ans;
 while(i<n && j<m)
 {
    if(arr1[i]==arr2[j])
    {
        ans.push_back(arr1[i]);
        i++;
        j++;
        
    }
     else if(arr1[i]<arr2[j])
    {i++;}
    else //if(arr[i]>arr[j])
    {j++;}
 }
 return ans;
}




//Method 1 : Brute-force 
//Time Complexity : O(n^2)
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{vector<int>ans;
	for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {if(arr1[i]<arr2[j])
            {break;}
                if(arr1[i]==arr2[j])
                {ans.push_back(arr1[i]);
                arr2[j]=-23311;
//updating matched value with a random integer so that
//it does not match again
                break;}
            }
    }
 return ans;
}