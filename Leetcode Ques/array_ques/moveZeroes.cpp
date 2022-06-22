//https://leetcode.com/problems/move-zeroes/
//Move zeroes to end
/*class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;   // i is non-zero element which acc to ques should be on left side and hence 0th index should be of course non-zero
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]!=0)
            {
                swap(nums[i],nums[j]);
                i++;
            }
        }
    } 
};
*/


