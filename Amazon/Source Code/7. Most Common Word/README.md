    Accepted        242,467
    Submissions     534,016
[Question Link](https://leetcode.com/problems/most-common-word/)   &emsp; [Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/Amazon/Source%20Code/7.%20Most%20Common%20Word/sol.cpp)

Approach:

    Time Complexity : O(N+M)

    Space Complexity : O(N+M)

    N -> Number of characters in input string
    M -> Number of characters in banned words
1. Convert string to lowercase.
2. Store frequency of each of the words in a map.
3. Copy word, frequency pair to the vector pair.
4. Reverse sort the vector based on the frequency.
5. Iterate from the first element of the vector and return the string that is not in banned words vector.