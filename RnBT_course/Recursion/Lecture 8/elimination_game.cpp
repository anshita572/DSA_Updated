//https://leetcode.com/problems/elimination-game/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastRemaining(int n) {
        if(n==1)//base case
        {return 1;}
        return (2*(1+n/2-lastRemaining(n/2)));
    }
};