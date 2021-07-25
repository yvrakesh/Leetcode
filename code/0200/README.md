![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0200) 

    Accepted        1,129,116
    Submissions     2,226,012
[Question Link](https://leetcode.com/problems/number-of-islands/) &emsp; [Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/code/0937/sol.cpp)

    Time Complexity : O(n*m)  [Actually it's 5*n*m]

    Space Complexity : O(1)
Approach:
1. Traverse through the matrix.
2. If the element is not visited and it's value is 1,
3. Make it visited and perform DFS on four directions (Top, Left, Bottom, Right).
4. Consider boundary cases and skip DFS for out of bound elements.


