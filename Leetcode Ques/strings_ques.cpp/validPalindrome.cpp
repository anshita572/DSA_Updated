//https://leetcode.com/problems/valid-palindrome/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     char toLowercase(char ch)
// {
// if(ch>='a' && ch<='z') //i.e. ch is lowercase
// {return ch;}
// else //if(ch>='A' && ch<='Z')//i.e. ch is uppercase
// {
//     char temp = ch- 'A'+'a'; //converting uppercase to lowercase
//     return temp;
// }
// }
//     bool isPalindrome(string s) {
//          int i=0;
//     int j=s.size()-1;
//     while(i<=j)
//     {
//        if(isalnum(s[i])==0)//if s[i] is not alphanumeric
//        {i++;}
//         else if(isalnum(s[j])==0)//if s[j] is not alphanumeric
//         {j--;}
//         else if(toLowercase(s[i])!=toLowercase (s[j]))
//         { return false;
            
//         }
        
//         else  //if(ch[i]==ch[j])
//         {i++;
//          j--;}
//     }
//    return true;
//     }
// };

    bool isAlphanumeric(char ch)
    {   
        if((ch>='a' && ch<='z') && (ch>=0 && ch<=9))
        {return true;}
        else
        {return false;}
    }
    bool isPalindrome(string s) {
        int n=s.length();
        bool ans=true;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {s[i]=s[i]-'A'+'a';}
        }
        int i=0;
        int j=n-1;
        while(i<=j)
        { if(!isAlphanumeric(s[i]))
           {i++;}
            else if(!isAlphanumeric(s[j]))
           {j--;
           cout<<s[j]<<endl;}
          else if (s[i]!=s[j])
            {ans=false;}
            else //if(s[i]==s[j])
            {i++;
            j--;}
          
           
        }
        return ans;
    }

int main()
{
    string s="race a car";
    bool res=isPalindrome(s);
   // cout<<res<<endl;
}