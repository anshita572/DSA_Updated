//https://leetcode.com/problems/count-primes/
//Time Compexity : O(n^2)   //that is why giving TLE
class Solution {
public:
    bool isPrime(int n)
{
    if(n<=1)   //i.e. 0 or 1
{return false;}
    for(int i=2;i<n;i++)
    {
        if(n % i ==0)
        {return false;}
        
    }
    return true;
}
    int countPrimes(int n) {
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(isPrime(i))
            {count++;}
        }
        return count;
    }
};