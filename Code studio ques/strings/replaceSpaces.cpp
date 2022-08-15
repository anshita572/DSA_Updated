//https://bit.ly/3sfP71Q 
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//M1 : TC :O(n),SC:O(1)
string replaceSpaces(string &str){
	string s="@40";
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==' ')
        {str.replace(i,1,s);}
    }
    return str;
}
//M2 : TC :O(n) , SC:O(n)
string replaceSpaces(string &str){
	string temp=""; //creating a string temp
        for(int i=0;i<str.length();i++)
        {
            if(str[i]==' ')
            {temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');}
            else  //if there is no space and normal character is encountered
            {temp.push_back(str[i]);}
        }
    return temp;
}