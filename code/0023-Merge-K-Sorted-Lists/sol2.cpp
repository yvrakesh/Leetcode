#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
// Min Heap Method
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
struct Compare
{
    bool operator()(ListNode* const& a, ListNode* const& b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& A) {
        int k = A.size();
        if(k == 0)
            return NULL;
        else if(k == 1)
            return A[0];
        ListNode* res = new ListNode(0);
        ListNode* tail = res;
        // To make it min heap since by default it's max heap
        priority_queue<ListNode*, vector<ListNode*>, Compare> Q;

        // Insert first element of all the k linked lists into min heap
        for (auto i = 0; i<k; ++i)
            if (A[i])
                Q.emplace(A[i]);

        while (!Q.empty()){
            // Extract the minimum element
            tail->next = Q.top();
            Q.pop();
            tail = tail->next;
            // Insert element next to the extracted element
            if (tail->next)
                Q.emplace(tail->next);
        }

        return res->next;
    }
};