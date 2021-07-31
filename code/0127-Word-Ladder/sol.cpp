#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
#include<bits/stdc++.h>
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> words_left;
        bool isPresent = false;
        // Insert all the words into dictionary
        for(auto i:wordList){
            if(!endWord.compare(i))
                isPresent = true;
            words_left.insert(i);
        }
        if(!isPresent)
            return 0;
        queue <string> q;
        // Push the start element into the queue
        q.push(beginWord);
        int curr_depth = 0;
        // BFS
        while(!q.empty()){
            curr_depth++;
            int curr_size = q.size();
            while(curr_size--){
                string curr = q.front();
                q.pop();
                for(int i=0;i<curr.length();i++){
                    string temp = curr;
                    for(char c='a';c<='z';c++){
                        if(curr[i] == c)
                            continue;
                        // Change ith letter to one of those
                        temp[i] = c;
                        if(!temp.compare(endWord))
                            return curr_depth+1;
                        // If the word is existing push it into queue and remove it from words list
                        if(words_left.find(temp) != words_left.end()){
                            q.push(temp);
                            words_left.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};