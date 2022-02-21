class Solution {
#include<bits/stdc++.h>
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Partition - Letter logs followed by Digit logs.
        // We're using stable_partition instead of partition to retain the original order.
        // stable_partition returns an iterator to the first element of the second group.
        auto it = stable_partition(logs.begin(), logs.end(), [](const string& str) {
            return isalpha(str.back());
        });
        // Sort letter-logs: We're only iterating on letter-logs in this case.
        // We're creating a substring for every element we compare that doesn't include the identifier
        // If the logs are the same except the identifier, we compare the strings, otherwise, the substrings
        
        sort(logs.begin(), it, [](const string& str1, const string& str2) {
            auto substr1 = string(str1.begin() + str1.find(' '), str1.end());
            auto substr2 = string(str2.begin() + str2.find(' '), str2.end());
            return (substr1 == substr2) ? str1 < str2 : substr1 < substr2;
        });
        
        return logs;
    }
};