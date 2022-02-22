![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0042)

    Accepted        806,850
    Submissions     1,534,223

[Question Link](https://leetcode.com/problems/trapping-rain-water/)   &emsp; [Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/code/0042-Trapping-Rain-Water/sol.cpp)   

Naive Approach:

    Time Complexity : O(n^2)

    Space Complexity : O(1)

1. For each position i, Find left maximum height by a loop 0 to i.
2. Find right maximum height by a loop from i+1 to n.
3. Then the amount of water stored would be min(max_left_height, max_right_height).
4. The amount of water stored is difference of a[i] (height of ith element) and minimum boundary by left & right.

Better Approach : Prefix Sum

    Time Complexity : O(3 *n) = O(n)

    Space Complexity : O(2*n) = O(n)

1. Find prefix array and suffix array.
2. This will give left maximum and right maximum heights in O(1).
3. Then traversing through each of the index and calculate the entire water trapped.

Efficient Approach: Two Point Approach

    Time Complexity : O(n)

    Space Complexity : O(1)

1. Two pointers one at the start of the vector and other at the end.
2. Compare if left height is lesser than right height then 
3. Difference of the current height and leftmax is the water stored.
4. Note: Why right side isn't considered?
5. Because the condition check ensures that left max is always less than the rightmax.