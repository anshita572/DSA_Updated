//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=1;i<n;i++) 
 //Imp :starting from i=1 as if i=0,then 0-1 will be -1
        {
        if(nums[i]<nums[i-1])
        {count++;}     
        }
        if(nums[n-1]>nums[0])//checking first and last element
        {count++;}
       // return count<=1;
      //OR
    
   if(count<=1) //less than 1 i.e.0 for array of equal elements
    {return true;}
        else
        {return false;}
    }
};