#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
#include<bits/stdc++.h>
public:
    int trap(vector<int>& height) {
        // l -> left end and r -> right end
        int l = 0, r = height.size()-1;
        int left_max = 0, right_max = 0, ans = 0;
        while(l <= r){
            if(height[l] < height[r]) {
                // If left height is lesser whatever may be right height it can only store from its height to left max difference.
                // Why not to consider right side
                // Because the condition ensures that right max is always greater than the left max 
                if(left_max > height[l])
                    ans += left_max-height[l++];
                else
                    left_max = height[l++];
            } 
            else {
                if(right_max > height[r])
                    ans += right_max - height[r--];
                else
                    right_max = height[r--];
            }
        }
        
        return ans;
    }
};