![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0295) 

    Accepted        347,852
    Submissions     711,389
[Question Link](https://leetcode.com/problems/find-median-from-data-stream/) &emsp; [Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/code/0295-Find-Median-From-Data-Stream/sol.cpp)

Brute Force Approach:

    Time Complexity : O(n^2)

    Space Complexity : O(1)

1. Insert a new element using insertion sort insert function (To keep the array ordered). -> O(n)
2. Finding the median -> O(1). Using direct formula (n+1)/2 or ((n/2) + (n/2+1))/2.

Observations:

1. We can see that using any of the sorting algorithm to maintain order complexity is O(n^2).
2. Finding median in a sorted array is O(1).

*Do we need to sort the array?*

No. We just want the middle elements. So if the array was sorted we just have to know which elements come under middle.

Balanced Binary Tree is best suitable here. (Insertion here is O(n))

*Problem here* is if we use a heap we can only get either minimum or maximum elements. But we need middle element.

Approach: 

1. Divide the array into two parts. Implement max heap on left half and min heap on right half.
2. If total number of elements are even then fetch the max heap from 1st half and min heap from second half.
3. Else fetch max heap from the first half.
4. Insertion: Compare insertion element with max heap of the 1st half and if it is less than 