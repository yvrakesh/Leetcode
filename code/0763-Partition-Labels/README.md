![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0763)

    Accepted        274,438
    Submissions     350,708

[Question Link](https://leetcode.com/problems/partition-labels/)   &emsp; [Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/code/0763-Partition-Labels/sol.cpp)

Approach:

    Time Complexity : O(n)
    
    Space Complexity : O(n)

1. Store last indexes of each of the alphabets.
2. Traverse through the loop and update the end ocurrence of each of the visited alphabet.
3. When all visited alphabets occurences are visited push the length of the string to result vector.
4. Update start position and continue till the end of the array.
