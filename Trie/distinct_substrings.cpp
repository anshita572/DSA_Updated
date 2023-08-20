// https://practice.geeksforgeeks.org/problems/count-of-distinct-substrings/1
// Time Complexity: O(n2), because we have to go through the entire string for all possible different starting points in order to generate all the substrings.

// Space Complexity: O(n2), because in the worst case, all the substrings can be distinct and there will be a node for every substring. Number of substrings of a string of length n is (n * (n + 1) / 2). Hence in the worst case, space complexity will be O(n2).
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node{
  Node* links[26];
  bool containsKey(char ch){
      if(links[ch - 'a'] != NULL){
          return true;
      }
      return false;
  }
  void put(char ch,Node* node){
      links[ch - 'a'] = node;
  }
  Node *get(char ch){
      return links[ch - 'a'];
  }
};
int countDistinctSubstring(string s)
{ Node *root = new Node();
  int count = 1; // 1 for empty substring
  for(int i = 0; i < s.size(); i++){
      Node *node = root;
      for(int j = i; j < s.size(); j++){
          if(!node->containsKey(s[j])){
              node->put(s[j],new Node());
              count++;
          }
          node = node->get(s[j]);
      }
  }
  return count;
    
}