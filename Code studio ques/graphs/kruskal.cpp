//https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769?leftPanelTab=0
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void makeSet(vector<int>&parent, vector<int>&rank,int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;//in starting,sb apne khud hi parent h
        rank[i]=0;//initially rank of all vertices=0
    }
}
int findParent(vector<int>&parent,int node)
  {
        if(parent[node]==node)//base case
        {return node;}
      return parent[node]=findParent(parent,parent[node]);
    }
void unionSet(int u,int v,vector<int>&parent,vector<int>&rank)
{
    //Step 1 : Find parents of u,v
    u=findParent(parent,u);
    v=findParent(parent,v);
    //Step 2 : Compare ranks of parents obtained in step 1
    if(rank[u]<rank[v])
    {parent[u]=v;
    }
    else if(rank[v]<rank[u])
    {
        parent[v]=u;
        
    }
    else //if(rank[u]==rank[v])
    {
        parent[v]=u;
            rank[u]++;
    }
    
}
bool cmp(vector<int>&a,vector<int>&b)
{
    return a[2]<b[2];//weight is 2nd index
    
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{sort(edges.begin(),edges.end(),cmp);//sort acc to weights
  vector<int>parent(n);
  vector<int>rank(n);
    makeSet(parent,rank,n);
 int minWeight=0;
 for(int i=0;i<edges.size();i++)
 {//Find parent of u,v
     int u=findParent(parent,edges[i][0]);
     int v=findParent(parent,edges[i][1]);
     int weight=edges[i][2];
     //If u,v don't have same parents=>merge them
     if(u != v)
     {
         minWeight=minWeight+weight;//add that weight to ans
         unionSet(u,v,parent,rank);
     }
 }
 return minWeight;
}