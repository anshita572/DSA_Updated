#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void subseq(string s, string ans, int i)
{
    if (i == s.length())
    {
        cout << ans << endl;
        return;
    }
    subseq(s, ans + s[i], i + 1);//include
    // cout << "i : " << i << endl;
    subseq(s, ans, i + 1);//exclude
}

int main()
{
    string s = "ab";
    string ans = "";
    subseq(s, ans, 0);
    return 0;
}
