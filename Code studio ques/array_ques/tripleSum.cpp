//Triplet sum [https://bit.ly/3GbgVs3]
//Brute-Force : use 3 nested for loops
//Time Complexity : O(n^3)

//Optimised approach : 2-pointer approach
//Time complexity : O(n^2)
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    for(int i=0;i<n-2;i++) //tbhi aage l and h honge ,if i<n toh l and h k liye jagah hi nhi hogi as array will be finished
    {int l=i+1;
    int h=n-1;
        while(l<h)
        {int sum= arr[i]+arr[l]+arr[h];
            if(sum==K)
            {ans.push_back({arr[i],arr[l],arr[h]});
              int left_element=arr[l];
                int right_element=arr[h];
                while(l<h && arr[l]==left_element)l++; //to skip the duplicate of l in next iteration
                while(l<h && arr[h]==right_element)h--; //to skip the duplicate of h in next iteration
  //Give in ques : find all distinct triplets       
            }
            else if(sum<K)
            {l++;}
            else //(arr[i]+arr[l]+arr[h]>K)
            {h--;}
           while(i+1<n && arr[i]==arr[i+1])i++;  //to skip the duplicate of i in next instance
        }
 
    }
    return ans;
}
