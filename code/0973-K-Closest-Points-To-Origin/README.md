![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0973)

    Accepted        510,725
    Submissions     783,914
[Question Link](https://leetcode.com/problems/k-closest-points-to-origin/)  &emsp; [Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/code/0973/sol.cpp)

Approach:

    Time Complexity : O(k + n*logn) => O(n*logn)

    Space Complexity : O(n)

1. Store pair of distance and corresponding vertices pair in a vector.
2. Sort the vector on basis of distance.
3. Copy first k elements into the output vector.