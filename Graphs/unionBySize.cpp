// https://takeuforward.org/data-structure/disjoint-set-union-by-size-union-by-size-path-compression-g-46/
// The time complexity is O(4 alpha) which is very small and close to 1. So, we can consider 4 as a constant.
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Disjoint{
   
        vector<int>parent;
        vector<int>size;
     public:
        Disjoint(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i = 0; i <= n; i++){
                parent[i] = i;
            }
        }
        int findUpar(int node){         //find ultimate parent
                if(parent[node] == node){
                    return node;
                }
                return parent[node] = findUpar(parent[node]); // path compression

                // without path compression
                //  return node = findUpar(parent[node]);
        }   
        void unionBysize(int u,int v){
            int ulp_u = findUpar(u);  //ultimate parent of u 
            int ulp_v = findUpar(v);
            if(ulp_u == ulp_v){
                return;
            }
            if(size[ulp_u] > size[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
            else // if(size[ulp_u] <= size[ulp_v])
            {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            
        }
};

int main(){
    Disjoint ds(7);
    ds.unionBysize(1,2);
    ds.unionBysize(2,3);
    ds.unionBysize(4,5);
    ds.unionBysize(6,7);
    ds.unionBysize(5,6);
    // check if 3 and 7 belong to same component or not
    if(ds.findUpar(3) == ds.findUpar(7)){
        cout<<"Same component"<<endl;
    }
    else{
        cout<<"Not same component"<<endl;
    }

    ds.unionBysize(3,7);
    // cout<<ds.findUpar(3)<<endl;
    // check if 3 and 7 belong to same component or not
    if(ds.findUpar(3) == ds.findUpar(7)){
        cout<<"Same component"<<endl;
    }
    else{
        cout<<"Not same component"<<endl;
    }


return 0;
}