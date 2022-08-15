//https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part)<s.length())
        {
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};
//string 's' m se uss string ko(part) ko find kiya h and 
//then usko erase(remove) kiya h 's' m se
//erase takes 2 parameters (what to erase ? , and kitni length erase krni h ?)
