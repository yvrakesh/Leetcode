/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
#include<bits/stdc++.h>
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node * iter = head;
        // Step 1 -> Create new nodes and link with older ones
        while(iter != NULL){
            Node * newnode = new Node(iter->val);
            newnode->next = iter->next;
            iter->next = newnode;
            iter = iter->next->next;
        }
        // Step 2 -> Update Random Links of the old links to the new node
        iter = head;
        while(iter != NULL){
            iter->next->random = iter->random?iter->random->next:nullptr;
            iter = iter->next->next;
        }
        // Step 3 -> Seperate new nodes from the older and re-establish old nodes as such
        Node *res = head->next;
        iter = head->next;
        while (head) {
            head->next = head->next->next;
            head = head->next;
            iter->next = iter->next ? iter->next->next : nullptr;
            iter = iter->next;
        }
        return res;  
    }
};