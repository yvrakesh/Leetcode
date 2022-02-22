![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0023)

    Accepted        941,321
    Submissions     2,136,967

[Question Link](https://leetcode.com/problems/merge-k-sorted-lists/)   &emsp; [Divide and Conquer](https://github.com/yvrakesh/Leetcode/blob/main/code/0023-Merge-K-Sorted-Lists/sol1.cpp) &emsp; [Min Heap](https://github.com/yvrakesh/Leetcode/blob/main/code/0023-Merge-K-Sorted-Lists/sol2.cpp)

Brute Force Approach 1:

    Time Complexity : O(N*k) where N -> Maximum elements in a list

    Space Complexity : O(1)

1. Merge each list one by one.
2. Say L1, L2, L3, ... Lk are k lists then L1 + L2 -> L12.
3. L12 + L3 -> L123 then L123 + L4 = L1234 and so on.

Brute Force Approach 2:

    Time Complexity : O(N * K) where N -> Maximum elements in a list

    Space Complexity : O(1) or O(N) (Depends on way of implementing)

1. Take minimum of k sorted lists each time for all the n numbers.

Simple Approach :

    Time Complexity : O(k + N*logN) = O(N*logN) where N -> total number of elements in the k linked lists

    Space Complexity : O(1)

1. Add all lists into a single list.
2. Sort the entire list.

Better Approach: Divide and Conquer

    Time Complexity : O(N * logk) -> N calls to extract min from the priority queue of len k.

    Space Complexity : O(N)

1. Using the merge function in the merge sort.
2. Merge two lists at once. ([Prerequisite](https://leetcode.com/problems/merge-two-sorted-lists/)  [Solution]())
3. this can be improved by merging all the linked lists so count reduces to k/2.
4. Total number of calls = (k/2) + (k/4) + (k/8) + ...... + 1 = (k/2) * 2 * ( 1 - (1/2)^n) = k * (1 - (1/2)^n)
5. So a total of k sorts and each sort is of O(l) complexity.
6. Note here that here a temporary linked list is used in the function call.
7. So as it is stored in the heap through out the execution it has to be considered in space complexity.

Best Approach: Priority Queues ( Min Heap )

    Time Complexity : O(N * logk) -> N calls to extract min from the priority queue of len k.

    Space Complexity : O(1)

1. Take first element (Minimum) of all k lists and push them into priority queue.
2. Pop the minimum element and insert it's next element.
3. Pop the minimum element and attach it to the next of the previous minimum and insert it's next and continue.
