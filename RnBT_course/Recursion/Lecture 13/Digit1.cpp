//https://leetcode.com/problems/number-of-digit-one/
// Brute force
// TC : O(nlog10(n)) , SC : O(1)
class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for(int i = 0; i <= n; i++){
            int num = i;
            while(num > 0){
            if(num % 10 == 1){
                count++;
            }
            num = num / 10;
         }
        }
        return count;
    }
};
// optimised
// TC : O(log10(n)) ~ O(log(n)) , SC : O(log10(n)) ~ O(log(n))  (log base 10)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
        int getLength(int n)
    {
        string s= to_string (n);
        int len=s.length();
        //OR
        // while(n!=0)
        // {
        //     n=n/10;
        //     len++;
        // }
        return len;
        
    }
    int countDigitOne(int n) {
        if(n==0)
        {return 0;}
        if(n<10)
        {return 1;}
        int len=getLength(n);
        int base=pow(10,len-1);
        int remainder=n%base;
        int firstDigit=n/base;
        int startingDig1=0;
        if(firstDigit==1)
        {startingDig1=n-base+1;}
        else
        {startingDig1=base;}
        return countDigitOne(remainder)+(firstDigit*countDigitOne(base-1))+startingDig1 ;
    }
};