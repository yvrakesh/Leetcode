#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
#include<bits/stdc++.h>
public:
    vector<int> partitionLabels(string s) {
        vector <int> last_idx(26,0);
        int len = s.length();
        // Stores last index of that alphabet
        for(int i=0;i<len;i++)
            last_idx[s[i]-'a'] = i;
        vector <int> res;
        int start = 0, end = 0;
        for(int i=0;i<len;i++){
            // This will update the end of all the visited substrings
            end = max(end,last_idx[s[i]-'a']);
            if(i == end){
                // Returning size of the substring from start to curr position
                res.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};