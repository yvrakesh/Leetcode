![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0937)

    Accepted        225,229
    Submissions     407,942
[Question Link](https://leetcode.com/problems/reorder-data-in-log-files/)  &emsp; [Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/code/0937-Reorder-Data-In-Log-Files/sol.cpp)

    Time Complexity : O(m*n*logn)

    Space Complexity : O(m*n)

    Where m -> Max number of words in a single log 
          n -> Number of logs
Approach:
1. Divide each of the string into two parts Identifier and content.
2. Store it in a vector pair with 1st element as content and 2nd as identifier based on identfier as either letter log or digit log.
3. Sort the letter log vector (This basically sorts based on 1st element and if it coincides then based on 2nd element).
4. Copy the Letter log strings back to the original array.
5. Digit log should not be sorted, so just copy them and return the vector.