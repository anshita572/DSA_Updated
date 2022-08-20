// https://prepinsta.com/cpp-program/to-check-whether-a-string-is-a-valid-shuffle-of-two-strings-or-not/
//TC :O(n logn) SC :O(1)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool validShuffle(string s1, string s2, string s3)
{
    if(s1.length()+s2.length()!= s3.length())
    {return false;}
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    sort(s3.begin(), s3.end());
    int i=0;
    int j=0;
    int k=0;
    while(k<s3.length())
    {
        if(s1[i]==s3[k] && i<s1.length())
        {i++;
        k++;}
        else if(s2[j]==s3[k] && j<s2.length())
        {j++;
        k++;}
        else 
        {return false;}
    }
    return true;

}
int main()
{ string s1="aabcc";
string s2="dbbca";
string s3="aadbbccbac";
cout<<validShuffle(s1,s2,s3)<<endl;

    return 0;
}