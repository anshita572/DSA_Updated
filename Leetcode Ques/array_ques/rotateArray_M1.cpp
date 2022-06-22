//https://leetcode.com/problems/rotate-array/
//Time Complexity : O(n)
//Extra space of O(1) (created another temp array and then copied the values in riginal array)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
       vector<int>temp(n);//array temp of n size(temp(n))
        for(int i=0;i<n;i++)
        {
            temp[(i+k) % n]=nums[i];
        }
        //copy elements of temp array to original array
        nums=temp;
    }
};