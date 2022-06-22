#include <iostream>
using namespace std;
bool checkPalindrome(string s, int i, int j)
{
    if (i > j)
    {
        return false;
    }
    if (s[i] == s[j])
    {
       return checkPalindrome(s, i + 1, j - 1);
       
    }
    else // if(s[i]!=s[j])
    {
        return false;
    }
}
int main()
{
    string str;
    cout << "Enter the string" << endl;
    getline(cin, str);
    if (checkPalindrome(str, 0, str.length() - 1))
    {
        cout << "It is a palindrome" << endl;
    }
    else
    {
        cout << "It is not a palindrome" << endl;
    }
    return 0;
}

/*
bool checkPalindrome(string s,int i,int j)
{
    //base case
    if(i>j)
    {return true;}
    if(s[i]!=s[j])
    {return false;}
    //recursive call
    else     //if(s[i]==s[j])
    return checkPalindrome(s,i+1,j-1);
}
*/