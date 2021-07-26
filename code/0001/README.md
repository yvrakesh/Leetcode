![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0001)

    Accepted        4,610,311
    Submissions     9,750,027
[Question Link](https://leetcode.com/problems/two-sum/) &emsp;[Solution 1](https://github.com/yvrakesh/Leetcode/blob/main/code/0001/sol1.cpp) &emsp;[Solution 2](https://github.com/yvrakesh/Leetcode/blob/main/code/0001/sol2.cpp)

Brute Force Approach :

    Time Complexity : O(n^2)

    Space Complexity : O(n)
1. Check if the sum of any two possibilities equal to that number if so then return those two indexes.

Efficient Approach 1 :

    Time Complexity : O(n)

    Space Complexity : O(n)
1. Store value and it's corresponding index.
2. Iterate over a loop and check if the target - curr has a valid index.
3. If then return those two values.

Efficient Approach :

    Time Complexity : O(nlogn) + O(2*n)  => O(nlogn) 
    (For Sorting + For 2 way sum)

    Space Complexity : O(n)
                 
1. Sort the elements and use two pointers at the extremes.
2. Get the two values corresponding to that sum.
3. Traverse through the vector to get indices of those two values. 