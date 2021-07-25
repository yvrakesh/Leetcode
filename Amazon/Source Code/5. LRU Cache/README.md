    Accepted        813,610
    Submissions     2,175,086
[Question Link](https://leetcode.com/problems/lru-cache/)   &emsp;  [Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/Amazon/Source%20Code/5.%20LRU%20Cache/sol.cpp)

**Approach:**

    Time Complexity : O(1)

    Space Complexity : O(1)
1. Use Linked List to maintain order and insert in O(1) 
2. Unordered map to insert, delete, search content in O(1) 
3. Also make Linked List deletion to O(1) by storing the address of the node as it's value.
