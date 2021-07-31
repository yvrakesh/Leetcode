![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0021)

    Accepted        1,540,591
    Submissions     2,687,651

[Question Link](https://leetcode.com/problems/merge-two-sorted-lists/)   &emsp; [Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/code/0021-Merge-Two-Sorted-Lists/sol.cpp)

Brute Force Approach:

    Time Complexity : O((M+N)^2)

    Space Complexity : O(1) 
    (If Insertion sort used)

    Time Complexity : O((M+N)* log(M+N))

    Space Complexity : O(log(M+N))
    (If Merge Sort used)

1. Merge both the linked lists.
2. Sort the resultant using merge sort or insertion sort.

Efficient Approach:

    Time Complexity : O(n)

    Space Complexity : O(n)

1. Update first list with the sum of first and second list elements.
2. Take last digit into the node and rest as carry.
3. Check if it's end of 1st list or end of 2nd list.
