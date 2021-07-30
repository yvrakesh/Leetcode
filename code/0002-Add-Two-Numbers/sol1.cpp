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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode resead(0), *p = &res;
        int extra = 0;
        while (l1 || l2 || extra){
            if (l1){
                extra += l1->val;
                l1 = l1->next;
            }
            if (l2){
                extra += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(extra % 10);
            // If any carry exists take it to the next step
            extra /= 10;
            p = p->next;
        }
        return res.next;
}
};