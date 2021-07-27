#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
#include<bits/stdc++.h>
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
            mp[nums[i]] = i+1;
        for(int i=0;i<n;i++){
            cout<<mp[target-nums[i]]<<endl;
            if(mp[target-nums[i]] && mp[target-nums[i]] != i+1)
                return {i,mp[target-nums[i]]-1};
        }
        return {};
    }
};