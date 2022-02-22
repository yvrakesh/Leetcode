#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
#include<bits/stdc++.h>
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector< pair<int,pair<int,int>> > v;
        // Store distances and vertices in the vector
        for(auto i:points)
            v.push_back({i[0] * i[0] + i[1] * i[1],{i[0],i[1]}});
        // Sort the vector
        sort(v.begin(),v.end());
        vector< vector<int> > res;
        // Take first k elements into the result
        for(auto i:v){
            if(k--)
                res.push_back({i.second.first,i.second.second});
            else
                break;
        }
        return res;
    }
};