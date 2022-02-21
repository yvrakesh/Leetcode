class Solution {
#include<bits/stdc++.h>
public:
    vector<string> reorderLogFiles(vector<string>& logs){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector <pair <string,string> > letter_log, digit_log;
        for(auto i:logs){
            string identifier = "", content = "";
            // Seperate each log into two parts identifier and the content of the log
            int j = 0;
            for(;j<i.size();j++){
                if(i[j] == ' ')
                    break;
                identifier += i[j];
            }
            j++;
            for(;j<i.size();j++)
                content += i[j];
            // Divide the logs into digit and letter logs
            if(content[0] >= '0' && content[0] <= '9')
                digit_log.push_back({content,identifier});
            else
                letter_log.push_back({content,identifier});
        }
        // Firstly sorts content lexicographically
        // If they are same then sort based on identifier (i.e. 2nd Element of the vector pair)
        sort(letter_log.begin(),letter_log.end());
        vector <string> res;
        // First store the letter log
        for(auto i:letter_log)
            res.push_back(i.second+" "+i.first);
        // Digit log shouldn't be sorted.
        for(auto i:digit_log)
            res.push_back(i.second+" "+i.first);
        return res;
    }
};