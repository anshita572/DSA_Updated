//https://leetcode.com/problems/trapping-rain-water/
//3 approaches Brute,better,optimal
//Brute Force
//TC :O(n^2)
//SC:O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
       
        int n=height.size();
        for(int i=0;i<n;i++)
        {  int left_max=0;
           int right_max=0;
           for(int k=0;k<=i;k++)
             {left_max=max(height[k],left_max);}
           for(int j=i;j<n;j++)
             {right_max=max(height[j],right_max);}
             ans=ans+(min(right_max,left_max)-height[i]);
        }
        return ans;
    }
};
//Better 
//TC :O(n)
//SC:O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>arr1(n);
        vector<int>arr2(n);
        int prefix_sum=0;
        int suffix_sum=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            prefix_sum=max(height[i],prefix_sum);
            arr1[i]=prefix_sum;
        }
         for(int j=n-1;j>=0;j--)
        {
            suffix_sum=max(height[j],suffix_sum);
             arr2[j]=suffix_sum;
        }
        for(int k=0;k<n;k++)
        {
            ans=ans+(min(arr1[k],arr2[k])-height[k]);
        }
        return ans;
    }
};
//Optimal
//TC :O(n)
//SC:O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int l=0;
        int r=n-1;
        int left_max=0;
        int right_max=0;
        
       while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>=left_max)
                {left_max=height[l];}
                else //if(height[l]<left_max)
                {ans=ans+(left_max-height[l]);}
                l++;
            }
            else //if(height[l]>height[r])
            {
                if(height[r]>=right_max)
                {right_max=height[r];}
                else //if(height[r]<right_max)
                {ans=ans+(right_max-height[r]);}
                r--;
                    
            }
        }
        return ans;
    }
};