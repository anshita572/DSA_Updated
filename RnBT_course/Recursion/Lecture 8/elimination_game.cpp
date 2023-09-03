//https://leetcode.com/problems/elimination-game/
// M1 : recursive
// TC : O(logn) , SC : O(logn)
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
// M2 : iterative
// TC : O(logn) , SC : O(1)
class Solution {
public:
    int lastRemaining(int n) {
        int remaining = n;
        bool left = true; // false represents right
        int diff = 1;
        int head = 1;
        while(remaining > 1){
            if(left || (remaining & 1)){ // if left is true or remaining is odd
                head += diff;
            }
            diff *= 2;
            remaining /= 2;
            left = !left; // now move from R to L
        }
        return head;
    }
};