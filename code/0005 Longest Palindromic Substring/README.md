![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0005)

    Accepted        1,391,701
    Submissions     4,486,073

[Question Link](https://leetcode.com/problems/longest-palindromic-substring/)   &emsp; [Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/code/0005/sol.cpp)

Naive Approach:

    Time Complexity : O(n^3)  
    (O(n^2) -> For producing n^2 substrings)
    (O(n) -> To check if each is a palindrome)

    Space Complexity : O(1)
    
1. Produce all substrings and check if each of them are palindromes.
2. Store Maximum length and string corresponding to it.

Efficient Approach : Dynamic Programming

    Time Complexity : O(n^2)

    Space Complexity : O(n^2)

1. Create a dp table of nxn.(Boolean value dp[i][j] = 1 -> substring from i to j is a palindrome and vice versa).
2. Update len 1 substrings (diagonal) as they all are a palindrome. (i.e. dp[i][i] = 1)
3. Update len 2 contiguous substrings comparing if 1st element equal to 2nd.(i.e. dp[i][i+1]=1 if s[i]=s[i+1] else 0)
4. In a loop start from len 3 substring to till len n.
5. Check condition if extremes are equal and non-boundary substring a palindrome.
6. dp[i][j] = 1 if and only if s[i] == s[j] && dp[i+1][j-1] == 1