// https://www.codingninjas.com/studio/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool containKey(char ch){
        if(links[ch - 'a'] != NULL){
            return true;
        }
        return false;
    }
    void put(char ch,Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void increaseEnd(){
        cntEndWith++;
    }
    int getPrefix(){
        return cntPrefix;
    }
    int getEnd(){
        return cntEndWith;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    void deleteEnd(){
        cntEndWith--;
    }
};
class Trie{
    private:
    Node* root;
    public:

    Trie(){
         root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
        
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(node->containKey(word[i])){
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(node->containKey(word[i])){
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(node->containKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else{
                return;
            }
        }
        node->deleteEnd();
    }
};