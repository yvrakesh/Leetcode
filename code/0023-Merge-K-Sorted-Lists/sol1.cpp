// Divide and Conquer Method
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
    // Divide and conquer 
    ListNode *merge(vector<ListNode*>& lists,int left,int right){
        // Base case only one list
        if(left==right) 
            return lists[left];
        
        int k = right-left+1;   //No of current lists
        ListNode *l1 = NULL,*l2 = NULL;
        l1 = merge(lists,left,left+k/2-1);    //Merge 1st half and store its head in h1
        l2 = merge(lists,left+k/2,right); //Merge 2nd half and store its head in h2
        
        // Same as merging two sorted lists leetcode
        // https://leetcode.com/problems/merge-two-sorted-lists/   21. Merge Two Sorted Linked Lists
        if(!l1 and !l2) //Both are null
            return NULL;
        else if(!l1)    //1st list is null
            return l2;
        else if(!l2)    //2nd list is null
            return l1;
        
        if(l1->val > l2->val){
            ListNode * temp = l1;
            l1 = l2;
            l2 = temp;
        }
        ListNode *res = l1;
        while(l1!=NULL && l2!=NULL){
            ListNode *temp;
            while(l1!=NULL && l1->val <= l2->val){
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            l2 = l1;
            l1 = temp->next;
        }
        return res;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        int k = lists.size();
        
        // Boundary cases
        if(k==0)
            return NULL;
        else if(k==1)
            return lists[0];
        
        return merge(lists,0,k-1);
    }
};