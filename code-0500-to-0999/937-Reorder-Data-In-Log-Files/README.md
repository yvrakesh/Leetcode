[Question Link](https://leetcode.com/problems/reorder-data-in-log-files/)  &emsp; [Solution 1 Link](https://github.com/yvrakesh/Leetcode/blob/main/code-0501-to-0999/0937-Reorder-Data-In-Log-Files/sol1.cpp) &emsp; [Solution 2 Link](https://github.com/yvrakesh/Leetcode/blob/main/code-0501-to-0999/0937-Reorder-Data-In-Log-Files/sol2.cpp)

    Time Complexity : O(N*logN)

    Space Complexity : O(N)

Approach:
1. Divide each of the logs into two parts Identifier and content.
2. Based on content classify it as either letter log or digit log.
3. Store it in corresponding vector pair with 1st element as content and 2nd as identifier 
4. Sort the letter log vector (This basically sorts based on 1st element and if it coincides then based on 2nd element).
5. Copy the Letter log strings back to the original array.
6. Digit log should not be sorted, so just copy them and return the vector.

<br>

    Time Complexity : O(N*logN)

    Space Complexity : O(1)

Approach 2:

1. Using <b>Stable Partition</b>, Divide the logs into letter logs followed by digit logs.
2. Stable partition returns iterator of the first element of the second group.
3. Sort logs until the iterator (The end of Letter logs).
4. In the custom sorting, first compare the content substrings. If they are equal, then compare the <b>strings</b>.