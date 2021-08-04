#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
#include<bits/stdc++.h>
public:
    static bool comp(pair<string,int>p1, pair<string,int>p2){
        if(p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second > p2.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector <string> res;
        unordered_map <string, int> freq;
        for(int i=0;i<words.size();i++)
            freq[words[i]]++;
        vector<pair<string,int>> freq_vector;
        for(auto i:freq)
            freq_vector.push_back({i.first,i.second});
        sort(freq_vector.begin(),freq_vector.end(),comp);
        for(int i=0;i<k;i++)
            res.push_back(freq_vector[i].first);
        return res;
    }
};