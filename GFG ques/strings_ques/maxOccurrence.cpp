//https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1#
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//TC :O(n) ,SC:O(n)
//M1
class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
      int n=str.length();
      int maxFreq=INT_MIN;
      char ans;
      map<char,int>mp;
      for(int i=0;i<n;i++)
      {mp[str[i]]++;}
      for(auto it:mp)
      {if(it.second > maxFreq)
      {maxFreq=it.second;
          ans=it.first;
      }
      }
      return ans;
      
    }

};
//M2
class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {int arr[26]={0};   //represents initial count i.e. 0 of all characters
       for(int i=0;i<str.length();i++)
       {   int count=0;
       count=str[i]-'a';
       arr[count]++;
           
       }
       int maxi=-1;
       int ans=0;
       for(int i=0;i<26;i++)
       {
           if(maxi<arr[i])
           {ans=i;
           maxi=arr[i]; //updating maxi
           }
       }
       return ans+'a';
    }

};
