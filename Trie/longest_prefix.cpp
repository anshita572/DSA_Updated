// https://practice.geeksforgeeks.org/problems/8d157f11af5416087251513cfc38ffc4d23be308/1
// TC: O(N)xO(length of string) , N is total number of words given in i/p
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    bool flag = false;
    bool containKey(char ch){
        if(links[ch - 'a'] != NULL){
            return true;
        }
        return false;
    }
    Node *get(char ch){
        return links[ch - 'a'];
    }
    void put(char ch,Node* node){
        links[ch - 'a'] = node;
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag; 
    }
    
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool checkIfAllPrefixExists(string word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(node->containKey(word[i])){
                node = node->get(word[i]);
                //isEnd should be true, if true , move ahead
                if(node->isEnd() == false){
                    return false;
                }
            }
            else // if(!node->containKey(word[i]))
            {return false;}
        }
        return true;
    }
};
class Solution
{
public:
    string longestString(vector<string> &words)
    {Trie* obj = new Trie();
     for(auto it : words){
         obj->insert(it);
     }
     string ans = "";
     for(auto it : words){
         if(obj->checkIfAllPrefixExists(it)){
             if(it.size() > ans.size()){
                 ans = it;
             }
             // if equal , then lexicographically smallest
             else if (it.size() == ans.size() && it < ans){
                 ans = it;
             }
         }
     }
      return ans;
    }
};