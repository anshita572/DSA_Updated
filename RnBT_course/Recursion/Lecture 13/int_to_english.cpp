//https://leetcode.com/problems/integer-to-english-words/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<pair<int, string>> arr ={{1000000000, "Billion "}, {1000000, "Million "}, 
    {1000, "Thousand "}, {100, "Hundred "}, {90, "Ninety "}, {80, "Eighty "}, {70, "Seventy "},
    {60, "Sixty "}, {50, "Fifty "}, {40, "Forty "}, {30, "Thirty "}, {20, "Twenty "}, {19, "Nineteen "}, 
    {18, "Eighteen "}, {17, "Seventeen "}, {16, "Sixteen "}, {15, "Fifteen "}, {14, "Fourteen "}, 
    {13, "Thirteen "}, {12, "Twelve "}, {11, "Eleven "}, {10, "Ten "}, {9, "Nine "}, {8, "Eight "}, 
    {7, "Seven "}, {6, "Six "}, {5, "Five "}, {4, "Four "}, {3, "Three "}, {2, "Two "}, {1, "One "}};
    
    //jaise int m return 0 krte,void m return;string m agar kuch na return krna ho do return ""
    string solve(int num)
    {
        //base case
        if(num==0)
        {return "Zero ";}
        for(auto i:arr)
        {
            if(num >= i.first)
            {string number= (num>=100 ? solve(num/i.first) : ""); 
            string placeValue=i.second;
            string remaining=(num%i.first==0 ? "" :solve(num % i.first));
            return number+placeValue+remaining;
            }
        }
        return "";
    }
    string numberToWords(int num) {
        string ans=solve(num);
        ans.pop_back();
        return ans;
    }
};