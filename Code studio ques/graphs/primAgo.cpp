//https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//TC :O(n^2) (To do : optimise using priority queue ,then TC will be O(n logn))
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<g.size();i++)
    {int u=g[i].first.first;
     int v=g[i].first.second;
     int w=g[i].second;
     adj[u].push_back(make_pair(v,w));
     adj[v].push_back(make_pair(u,w));
   }
    vector<int>key(n+1);//see ques carefully,1 se start ho rha and not 0 ,so source node will be 1
    vector<bool>mst(n+1);
    vector<int>parent(n+1);
    //initial values for key,mst,parent
    for(int i=0;i<=n;i++)
    {
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;
    }
    //staring from source node which is 1 acc to ques
    key[1]=0;
    parent[1]=-1;
    for(int i=1;i<n;i++)
    {int mini=INT_MAX;
     int u;
     //find min wali node
     for(int v=1;v<=n;v++)
     {if(mst[v]==false && key[v]<mini)
     {u=v;
     mini=key[v];}
     }
     //mark min node as true
      mst[u]=true;  
     //check its adjacent nodes
     for(auto i:adj[u])
     {int v=i.first;
      int w=i.second;
         if(mst[v]==false && w<key[v])
         {parent[v]=u; //mark u as parent of v in parent vector
         key[v]=w;
         }
     }
    }
    vector<pair<pair<int, int>, int>>ans;
    for(int i=2;i<=n;i++)
    { ans.push_back({{parent[i],i},key[i]});}//ans=parent uss node ka,that node itself,weight on edge between parent and node
    return ans;
}
