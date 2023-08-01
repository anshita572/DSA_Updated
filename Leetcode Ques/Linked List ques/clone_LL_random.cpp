// https://leetcode.com/problems/copy-list-with-random-pointer/description/
// M1 : Brute Force : TC : O(n)  SC: O(n) using maps
class Solution {
public:
    void insertAtTail(Node *&cloneHead,Node *&cloneTail,int val){
        Node *temp = new Node(val);
        if(cloneHead == NULL){
            cloneHead = temp;
            cloneTail = temp;
        }
        else{
            cloneTail->next = temp;
            cloneTail = temp;
        }
    }
    Node* copyRandomList(Node* head) {
        Node *cloneHead = NULL;
      Node *cloneTail = NULL;
      Node *temp = head;
      while(temp != NULL){
          insertAtTail(cloneHead,cloneTail,temp->val);
          temp = temp->next;
      }
       unordered_map<Node*,Node*>mp;
       temp = head;
       Node *originalNode = head;
       Node *cloneNode = cloneHead;
       // creating mapping of originalNode with cloneNode in map
       while(originalNode != NULL){
           mp[originalNode] = cloneNode;
           originalNode = originalNode->next;
           cloneNode = cloneNode->next;
       }
       originalNode = head;
       cloneNode = cloneHead;
       while(originalNode != NULL){
           cloneNode -> random = mp[originalNode -> random];
           originalNode = originalNode->next;
           cloneNode = cloneNode->next;
           
       }
       return cloneHead;
    }
};
// M2 : Optimized : TC:O(n) SC:O(1)
class Solution {
public:
    void insertAtTail(Node *&cloneHead,Node *&cloneTail,int val){
        Node *temp = new Node(val);
        if(cloneHead == NULL){
            cloneHead = temp;
            cloneTail = temp;
        }
        else{
            cloneTail->next = temp;
            cloneTail = temp;
        }
    }
    Node* copyRandomList(Node* head) {
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;
         Node *temp = head;
      while(temp != NULL){
          insertAtTail(cloneHead,cloneTail,temp->val);
          temp = temp->next;
      }
    
       Node *originalNode = head;
       Node *cloneNode = cloneHead;
       while(originalNode != NULL && cloneNode != NULL){
           Node *org_next = originalNode -> next;
           originalNode -> next = cloneNode;
           originalNode = org_next;

           org_next = cloneNode -> next;
           cloneNode -> next = originalNode;
           cloneNode = org_next;
       }
       temp = head;
       while(temp != NULL){
           if(temp->random != NULL){
               temp->next->random = temp->random->next;
           }
           else{
               temp->next->random = NULL;
           }
           temp = temp->next->next;
       }
        originalNode = head;
       cloneNode = cloneHead;
       while(originalNode != NULL && cloneNode != NULL){
           originalNode -> next = cloneNode -> next;
           originalNode =  originalNode -> next;
           if(originalNode != NULL){
           cloneNode -> next = originalNode -> next;
           }
           cloneNode = cloneNode -> next;
       }
       return cloneHead;
    }
}; 