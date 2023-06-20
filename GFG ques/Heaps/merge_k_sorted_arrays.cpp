// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
// TC : O(k^2 (log k)) , SC : O(k^2)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    int i;
    int j;
    // constructor
    node(int data,int row,int col){
    this->data=data;
    i=row;
    j=col;}
};
class compare{
public:
bool operator() (node*a,node*b)
{return (a->data > b->data);}
};
class Solution
{
    public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {priority_queue<node*,vector<node*>,compare>pq;
    //  step 1 : put 1st element of each array(which is
    // minimum in its array) in min heap
     for(int i=0;i<K;i++)
     {node *temp=new node(arr[i][0],i,0);
      pq.push(temp);
     }
     vector<int>ans;
    //  step 2 : store min element of heap (i.e top element)
    // in ans and store next element of the array that had
    //  that min element in heap
     while(!pq.empty())
     {node*temp=pq.top();
      ans.push_back(temp->data);
      pq.pop();
      int i=temp->i;
      int j=temp->j;
      if(j+1 < arr[i].size())
      {node*next=new node(arr[i][j+1],i,j+1);
        pq.push(next);
      }
         
     }
        return ans;
    }
    
};