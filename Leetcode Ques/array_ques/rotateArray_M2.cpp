//https://leetcode.com/problems/rotate-array/
class Solution {
public:
    void reverse(vector<int>& A,int i,int j)
{
     

while(i<=j)
{
 swap(A[i],A[j]);
i++;
j--;
}
}
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n; //if k is larger than n,k ko range m laane k liye
        //Dry run for k>n and you will understand
        reverse(nums,0,n-1);//reversing the entire array
        reverse(nums,0,k-1);//now reversing the reversed array till k-1
        reverse(nums,k,n-1);//now reversing the reveresed array from k to n-1
    }
};