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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode *res = l1, *temp_node = l1;
        int carry = 0;
        while(l1 || l2 || carry){
            if(l1 && l2){
                int temp = l1->val + l2->val + carry;
                l1->val = temp%10;
                carry = temp/10;
                temp_node = l1;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 && carry){
                int temp = l1->val + carry;
                l1->val = temp%10;
                carry = temp/10;
                temp_node = l1;
                l1 = l1->next;
            }
            else if(l1)
                break;
            else if(l2 && carry){
                int temp = l2->val + carry;
                l2->val = temp%10;
                carry = temp/10;
                temp_node->next = l2;
                l2 = l2->next;
                temp_node = temp_node->next;
            }
            else if(l2){
                temp_node->next = l2;
                break;
            }
            else if(carry){
                temp_node->next = new ListNode(carry);
                break;
            }
        }
        return res;
    }
};