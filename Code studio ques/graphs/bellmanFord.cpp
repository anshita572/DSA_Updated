//https://www.codingninjas.com/codestudio/problems/bellmon-ford_2041977?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
  vector<int>distance(n+1,1e9);//n+1 as starting from 1 and not from 0
    //initially initialising all values with infinity
//     for(int i=0;i<=n;i++)
//     {distance[i]=INT_MAX;}
    distance[src]=0;
    //n-1 times
    for(int i=1;i<=n;i++)
    {for(int j=0;j<m;j++)
    {//traverse on edge list
        int u=edges[j][0];
        int v=edges[j][1];
        int wt=edges[j][2];
        if(distance[u]!=1e9 && ((distance[u]+wt) < distance[v]))
        {distance[v]=distance[u]+wt;}
    }}
    //check for negative cycle (checking for 3rd time)
    bool flag=0;
     for(int j=0;j<m;j++)
    {//traverse on edge list
        int u=edges[j][0];
        int v=edges[j][1];
        int wt=edges[j][2];
        if(distance[u]!=1e9 && ((distance[u]+wt) < distance[v]))
        {flag=1;}
    }
    if(flag==0)
    {return distance[dest];}
    else
    {return -1;}
}