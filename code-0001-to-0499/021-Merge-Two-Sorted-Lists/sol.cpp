#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
#include<bits/stdc++.h>
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        // Swap l1 and l2 to make l1's first node as least number
        if(l1->val > l2->val){
            ListNode * temp = l1;
            l1 = l2;
            l2 = temp;
        }
        ListNode *res = l1;
        while(l1!=NULL && l2!=NULL){
            ListNode *temp;
            // Travel through the first list until you get a number greater than 2nd list first element
            while(l1!=NULL && l1->val <= l2->val){
                temp = l1;
                l1 = l1->next;
            }
            // Point to the 2nd list first node and swap l1 & l2 to make l1->val the least.
            temp->next = l2;
            l2 = l1;
            l1 = temp->next;
        }
        return res;
    }
};