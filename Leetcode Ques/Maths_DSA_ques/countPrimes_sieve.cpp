//https://leetcode.com/problems/count-primes/
//Sieve of Eratosthenes
//Time Complexity : O(n*(log(log n)))
class Solution {
public:
    int countPrimes(int n) {
        int count=0;
         // A vector of n+1 elements with value true (default: false)
        vector<bool>prime(n+1,true);  //array(here vector) of bool type containing n+1 elements with value true.(e.g. if n=10,n+1 means from 0 to 10 i.e. in total 11)
        prime[0]=false;
        prime[1]=false;  //0 and 1 ko false set krdo
        for(int i=2;i<n;i++)
        {
            if(prime[i])  //if(prime[i]==true)
            {count++;
        
            for(int j=2*i;j<n;j=j+i)   //j=j+i ki uske multiples cut krne
            {
                prime[j]=false;       //setting multiples as false
            }
        }
        }
        return count;
    }
};