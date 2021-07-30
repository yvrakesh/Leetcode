![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0002)

    Accepted        2,077,800
    Submissions     5,694,937
[Question Link](https://leetcode.com/problems/add-two-numbers/) &emsp;[Solution 1](https://github.com/yvrakesh/Leetcode/blob/main/code/0001-Two-Sum/sol1.cpp) &emsp; [Solution 2](https://github.com/yvrakesh/Leetcode/blob/main/code/0001-Two-Sum/sol2.cpp)

Brute Force Approach:

    Time Complexity : O(Max(n,m))

    Space Complexity : O(Max(n,m))

1. Create a new list with a temp node.
2. Add last digit to the list and rest to the carry.
3. Continue till the end of the lists and carry.

Efficient Approach:

    Time Complexity : O(Max(n,m))

    Space Complexity : O(1)

1. Just update values of 1st list with their sums and carry.
2. If you come out of 1st list and still need to process 2nd, join the rest of the second list.