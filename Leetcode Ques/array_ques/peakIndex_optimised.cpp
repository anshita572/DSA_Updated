//https://leetcode.com/problems/find-pivot-index/
//optimised : Time compelxity : O(n)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int leftSum=0;
        
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
        }
        int rightSum=sum;
        for(int i=0;i<n;i++)
        {
            rightSum=rightSum-nums[i];
            if(leftSum==rightSum)
            {return i;}
            else
            {leftSum=leftSum+nums[i];}
        }
        return -1;
    }
};