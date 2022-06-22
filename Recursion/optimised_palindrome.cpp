#include<iostream>
using namespace std;
bool checkPalindrome(string& s,int i,int n)
{
    //base case
    if(i>n-1-i)
    {return true;}
    if(s[i]!=s[n-1-i])
    {return false;}
    //recursive call
    else     //if(s[i]==s[j])
    return checkPalindrome(s,i+1,n-1-i);
}
int main(){
string str;
cout<<"Enter the string"<<endl;
getline(cin,str);
if(checkPalindrome(str,0,str.length()))
{cout<<"It is a palindrome"<<endl;}
else
{cout<<"It is not a palindrome"<<endl;}
return 0;
return 0;
}