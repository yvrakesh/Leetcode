![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0692) 

    Accepted        302,090
    Submissions     563,703
[Question Link](https://leetcode.com/problems/top-k-frequent-words/) &emsp; [Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/code/0692-Top-K-Frequent-Words/sol.cpp)

Approach:

    Time Complexity : O(n * logn)

    Space Complexity : O(n)

1. Store frequency of each of the words in a hash map ( unordered_map in cpp).
2. Copy the string and its frequency into a vector pair.
3. Sort the vector using custom sorting function where you sort based on decreasing order of frequency.
4. Incase of equal frequencies you sort lexicographically on basis of string.
5. Now insert k values into the result.