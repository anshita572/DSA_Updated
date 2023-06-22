// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/
// TC : O(n*k log k) , SC : O(k)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
public:
  int data;
  int row;
  int col;
  node(int d,int r,int c) //constructor
  {data=d;
  row=r;
  col=c;
  } 
};
class compare{
public:
 bool operator() (node *a,node*b)
 {return a->data > b->data;}
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
     int mini=INT_MAX;
     int maxi=INT_MIN;
     priority_queue<node*,vector<node*>,compare>pq;
     int k=nums.size();
     for(int i=0;i<k;i++)
     {
       int element=nums[i][0];
       mini=min(mini,element);
      maxi=max(maxi,element);
      node*temp=new node(element,i,0);
      pq.push(temp);
     }
     int start=mini;
     int end=maxi;
     while(!pq.empty())
     { node*temp=pq.top();
       pq.pop();
       mini=temp->data;
       if(maxi-mini < end-start)
       {start=mini;
       end=maxi;}
       int n=nums[temp->row].size();
       if(temp->col+1 < n)
       {maxi=max(maxi,nums[temp->row][temp->col+1]);
        node*temp1=new node(nums[temp->row][temp->col+1],temp->row,temp->col+1);
        pq.push(temp1);
       }
       else
       {break;}
     }
     vector<int>ans;
     ans.push_back(start);
     ans.push_back(end);
     return ans;
    }
};