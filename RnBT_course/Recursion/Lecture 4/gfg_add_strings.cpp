//https://practice.geeksforgeeks.org/problems/sum-of-numbers-or-number1219/1
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
        string findSum(string X, string Y) {
        
        int i=X.length()-1;
        int j=Y.length()-1;
       string ans;
       int carry=0;
        while(i>=0 || j>=0 || carry !=0)
       {   int first=0;
        int second=0;
           if(i>=0)
        {  first=X[i]-'0';}
        if(j>=0)
        {second=Y[j]-'0';}
           int sum=first+second+carry;
        int last_dig=sum % 10;
        carry=sum/10;
        ans=ans+to_string(last_dig);
           i--;
           j--;
       }
       reverse(ans.begin(),ans.end());
        while(ans[0]=='0' && ans.size()>1)
        {ans.erase(ans.begin());}
        return ans;
    }
