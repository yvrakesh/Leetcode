class Solution {
#include<bits/stdc++.h>
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // Two types of logs are there : Letter log and Digit Log
        // Divide the one set of words into two parts identifier of the log and content of the log
        vector <pair <string,string> > letter_log, digit_log;
        for(auto i:logs){
            string identifier = "", content = "";
            // Flag to know whether to add string to identifier or content of the log
            bool isIdentifier = true;
            for(int j=0;j<i.size();j++){
                if(i[j] == ' ' && isIdentifier){
                    isIdentifier = false;
                    continue;
                }
                if(isIdentifier)
                    identifier += i[j];
                else
                    content += i[j];
            }
            if(content[0] >= '0' && content[0] <= '9')
                digit_log.push_back({content,identifier});
            else
                letter_log.push_back({content,identifier});
        }
        // Firstly sorts content lexicographically
        // If they are same then sort based on identifier
        sort(letter_log.begin(),letter_log.end());
        vector <string> res;
        for(auto i:letter_log)
            res.push_back(i.second+" "+i.first);
        // Digit log shouldn't be sorted
        for(auto i:digit_log)
            res.push_back(i.second+" "+i.first);
        return res;
    }
};