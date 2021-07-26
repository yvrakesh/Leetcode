#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution{
#include<bits/stdc++.h>
public:
    bool isPalindrome(string s, int i, int j){
        while(i <= j)
            if(s[i++] != s[j--])
                return 0;
        return 1;
    }
    string longestPalindrome(string s){
        int n = s.length(),max_len = 1,first_ind=0,last_ind=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(j-i+1 > max_len && isPalindrome(s,i,j)){
                    max_len = j-i+1;
                    first_ind = i;
                    last_ind = j;
                }
            }
        }
        string res = "";
        for(int i=first_ind;i<last_ind+1;i++)
            res += s[i];
        return res;
    }
};