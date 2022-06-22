//https://leetcode.com/problems/sqrtx/
class Solution {
public:
    int mySqrt(int x) {
        int start=0;
        int end=x;
        int ans=0;
        while(start<=end)
        {
            long long int mid=start + (end-start)/2;
            if((mid*mid)==x)
            {return mid;}
            else if((mid*mid)>x)
            {end=mid-1;}
            else //if(mid*mid<x)
            {ans=mid;
            start=mid+1;}
        }
        return ans;
    }
};
//we are using long long int for mid because
// we know range of int is : -2^31 to 2^31
//suppose if mid comes out to be 2^31 ,then midmid 
//i.e 2^31  2^31 will be out of the range of int and
// hence integer overflow error,so use long long int 
//for mid i.e. from : -2^63 to 2^63