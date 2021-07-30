#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
#include<bits/stdc++.h>
public:
    bool isValid(string s) {
        int n = s.length();
        stack <char> st;
        for(int i=0;i<n;i++){
            if(st.size() > n/2)
                return false;
            if(s[i] == '{' || s[i] == '[' || s[i] == '(')
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                char temp = st.top();
                st.pop();
                if((s[i] == ')' && temp == '(') || (s[i] == ']' && temp == '[') || (s[i] == '}' && temp == '{'))
                    continue;
                else
                    return false;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};