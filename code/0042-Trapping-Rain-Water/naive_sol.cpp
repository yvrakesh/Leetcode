#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
#include<bits/stdc++.h>
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0)
            return 0;
        int res = 0;
        for(int i=0;i<n;i++){
            int left_max = 0, right_max = 0;
            // Find left maximum -> O(n)
            for(int j=0;j<=i;j++)
                left_max = max(left_max,height[j]);
            // Find right maximum -> O(n)
            for(int j=i;j<n;j++)
                right_max = max(right_max,height[j]);
            res += min(left_max,right_max) - height[i];
        }
        return res;
    }
};