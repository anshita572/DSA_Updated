// https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // prepare adjaceny list
    map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    // creating distance vector with initial value infinity for each node
    vector<int> distance(vertices);
    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INT_MAX;
    }
    // creation of set on basis of distance,node
    set<pair<int, int>> s;
    // initialise distance and set with source node
    distance[source] = 0;
    s.insert(make_pair(0, source));
    while (!s.empty())
    {
        auto top = *(s.begin());
        int nodeDistance = top.first;
        int topNode = top.second;
        // remove top record now
        s.erase(s.begin());
        for (auto i : adj[topNode])
        {
            if (nodeDistance + i.second < distance[i.first])
            { // if already uss node ka kuch distance h erase it
                auto record = s.find(make_pair(distance[i.first], i.first));
                if (record != s.end())
                {
                    s.erase(record);
                }

                // and update with lesser distance now
                distance[i.first] = nodeDistance + i.second;
                // push record in set
                s.insert(make_pair(distance[i.first], i.first));
            }
        }
    }
    return distance;
}
