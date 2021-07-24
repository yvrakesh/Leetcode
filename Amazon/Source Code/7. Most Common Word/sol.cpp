#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
#include<bits/stdc++.h>
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // Change entire sentence into lowercase
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        // Store words and their frequencies
        unordered_map <string, int> mp;
        string temp = "";
        for(int i=0;i<paragraph.length();i++){
            // Wait until it is not a lowercase alphabet
            // May be space, ',' , '.'
            if(paragraph[i] < 'a' || paragraph[i] > 'z'){
                if(temp == "" || temp == " ")
                    continue;
                // Add the word to the map and increment its frequency
                mp[temp]++;
                temp = "";
                continue;
            }
            temp += paragraph[i];
        }
        // Final word should also be added
        if(temp != "")
            mp[temp]++;
        // Now we have frequencies but they are not sorted
        vector <pair <int,string>> v;
        for(auto i:mp)
            v.push_back({i.second,i.first});
        // Reverse sort the vector based on the word count
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(auto i:v){
            // Traverse from the largest occurence and check if it's not a banned word
            if(find(banned.begin(),banned.end(),i.second) != banned.end())
                continue;
            return i.second;
        }
        return "";
    }
};