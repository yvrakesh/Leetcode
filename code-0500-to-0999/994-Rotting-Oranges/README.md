![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0994)

    Accepted        234,150
    Submissions     468,361

[Question Link](https://leetcode.com/problems/rotting-oranges/)   &emsp; [Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/code/0994-Rotting-Oranges/sol.cpp)

Approach:

    Time Complexity : O(m * n)

    Space Complexity : O(m * n)
1. Find total number of fresh fruits and add rotten fruits into queue with their time_stamps.
2. Apply BFS by incrementing time (similar to depth).
3. Repeat this until queue gets cleared and at each stage add rotten fruits into the queue with their correpoding time stamps.
4. Check boundary limits and finally if there are any fresh fruits left, then its impossible, return -1.
5. Else return it's count.

    