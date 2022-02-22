#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
#include<bits/stdc++.h>
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0)
            return 0;
        // Store prefix max and suffix map at each of the positions
        vector <int> prefix(n), suffix(n);
        prefix[0] = height[0];
        for(int i=1;i<n;i++)
            prefix[i] = max(prefix[i-1],height[i]);
        suffix[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--)
            suffix[i] = max(suffix[i+1],height[i]);
        int res = 0;
        // Thus left_max and right_max can be accessed in O(1)
        for(int i=0;i<n;i++)
            res += min(prefix[i],suffix[i]) - height[i];
        return res;
    }
};