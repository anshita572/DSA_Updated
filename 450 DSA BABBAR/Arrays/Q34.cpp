//https://www.codingninjas.com/codestudio/problems/make-it-palindrome_3189160?leftPanelTab=0
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int palindrome(vector<int> A)
{   int n=A.size();
	int count=0;
    int i=0;
    int j=n-1;
 //while merging sum can be large so doing long long
    long long left =A[0];
    long long right=A[n-1];
    while(i<j)
    {
        if(left==right)
        {i++;
        j--;
        left=A[i];
        right=A[j];}
        else if(left>right)
        {
            
            right=right+A[j-1];
            j--;
            count++;
        }
        else //if(right>left)
        {  
         left=left+A[i+1];
            i++;
        count++;}
        
    }
 return count;
}