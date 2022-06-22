//https://leetcode.com/problems/peak-index-in-a-mountain-array/
//Brute force : Find max element in array but time complexity : O(n)
//Optimised:using Binary search,Time complexity:O(log n)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int start=0;
        int end=n-1;
        while(start<end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid+1]>arr[mid]) //left side of peak
            {start=mid+1;}
            else //if(arr[mid-1]>arr[mid] || (arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]))
            {end=mid;} //right side of peak or peak itself
        }
        return start;
    }
};