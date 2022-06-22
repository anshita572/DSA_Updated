//https://leetcode.com/problems/fibonacci-number/
class Solution {
public:   //Indexing starts from 0 (0 is 0th term)
    int fib(int n) {
        if(n==0)   //base case
        {return 0;}
        if(n==1)    //base case
        {return 1; }
        int ans=fib(n-1)+fib(n-2); //recursive call
        return ans;
    }
};