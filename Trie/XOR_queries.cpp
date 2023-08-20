// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// M1 : Brute force (TLE) , TC: O(n * m) , SC: O(1)
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
      int n = nums.size();
      int m = queries.size();
      vector<int>ans(m,-1);
      for(int i = 0; i < m; i++){
          int x = queries[i][0];
          int q = queries[i][1];
          for(int j = 0; j < n; j++){
              if(nums[j] <= q){
                  ans[i] = max(ans[i], nums[j] ^ x);
              }

          }
      } 
      return ans; 
    }
};
// M2 : optimal , Time Complexity:O(M) + O(MlogM) + O(M*32 + N*32) , Space Complexity:O(32*N)
struct Node{
    Node*links[2]; // size = 2 (for 0 and 1)
    bool containsKey(int bit){
        if(links[bit] != NULL){
            return true;
        }
        return false;
    }

    Node* get(int bit){
        return links[bit];
    }
    void put(int bit,Node*node){
        links[bit] = node;
    }
};
class Trie{
    private: 
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
   
        void insert(int num){
            Node* node = root;
            // start inserting or checking from 32nd bit (31st index)
            for(int i = 31; i >= 0; i--){
                 // check if bit is set or not i.e 1 or 0
                int bit = (num >> i) & 1;
                if(!node->containsKey(bit)){
                    node->put(bit,new Node());
                }
                node = node->get(bit);
            }
        }
        int getMax(int x){
            Node* node = root;
            int maxi = 0;
            for(int i = 31; i >= 0; i--){
            
            int bit = (x >> i) & 1;
            if(node->containsKey(!bit)) // for max , we want opposite bit
            {
                maxi = maxi | (1 << i);
                node = node->get(!bit);
            }
            else{
                node = node->get(bit);
             }
            }
            return maxi;
        }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
      int n = nums.size();
      int m = queries.size();
      sort(nums.begin(),nums.end());
      vector<int>ans(m,0);
      vector<pair<int,pair<int,int>>>q;
      for(int i = 0; i < m; i++){
          q.push_back({queries[i][1],{queries[i][0],i}});
      }
      sort(q.begin(),q.end());
      int index = 0;
      Trie trie;
      for(int i = 0; i < m; i++){
          int ai = q[i].first;
          int x = q[i].second.first;
          int qi = q[i].second.second;
          while(index < n && nums[index] <= ai){
              trie.insert(nums[index]);
              index++;
          }
          if(index != 0){
              ans[qi] = trie.getMax(x);
          }
          else{
              ans[qi] = -1;
          }
      }
      return ans;
    }
};