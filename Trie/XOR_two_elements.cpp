// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
// Time Complexity: O(N*32) + O(M*32)
// Reason: For inserting all the elements of arr1 into the trie take O(N*32) [32 Bit] and O(M*32) for finding the maxXOR for every element of arr2.
// Space Complexity: O(N*32)
// Reason: Since we are inserting all the elements of arr1 into trie where every element is of size 32 bit but the space complexity will be less than O(N*32) because they might have overlapped.
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
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
    int findMaximumXOR(vector<int>& nums) {
    int n = nums.size();
    Trie trie;
    for(int i = 0; i < n; i++){
        trie.insert(nums[i]);
    } 
    int maxi = 0;
   for(int i = 0; i < n; i++){
       maxi = max(maxi, trie.getMax(nums[i]));
   }
    return maxi;
    }
};