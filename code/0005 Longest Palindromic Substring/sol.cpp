#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
#include<bits/stdc++.h>
public:
    string longestPalindrome(string s) {
        int n = s.length();
        // Table to store [Start][End] of the string
        bool dp[n][n];
        int first_ind = 0, last_ind = 0;
        // dp[i][i] = 1 mean the string from ith index to ith index i.e. of len 1 is a palindrome
        for(int i=0;i<n;i++)
            dp[i][i] = 1;
        // Check palindromes of length 1
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                // This is essential if the string has maximum palindromic length of 2 units
                first_ind = i;
                last_ind = i+1;
            }
            else
                dp[i][i+1] = 0;
        }
        // Check palindromes starting from ith index
        for(int i=2;i<n;i++){
            int j = 0, k = i-1;
            while(++k < n){
                // If extreme elements are equal
                if(s[j] == s[k]){
                    // Check if inside substring a palindrome
                    if(dp[j+1][k-1] == 1){
                        // If then the entire string is a palindrome
                        dp[j++][k] = 1;
                        if(last_ind-first_ind < k-j+1){
                            first_ind = j-1;
                            last_ind = k;
                        }
                    }
                    else
                        dp[j++][k] = 0;
                }
                else
                    dp[j++][k] = 0;
            }
        }
        // substring from first_ind to last_ind into the result
        return s.substr(first_ind,last_ind-first_ind+1);
    }
};