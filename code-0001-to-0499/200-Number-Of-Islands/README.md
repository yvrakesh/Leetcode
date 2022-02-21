[Question Link](https://leetcode.com/problems/number-of-islands/) &emsp; [BFS Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/code/0200-Number-Of-Islands/BFS.cpp) &emsp; [DFS Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/code/0200-Number-Of-Islands/DFS.cpp)

    Time Complexity : O(m*n) 

    Space Complexity : O(m*n)

DFS Approach:
1. Traverse through the matrix.
2. If the element is not visited and it's value is 1, Increment island count.
3. Make it visited by changing it's value to 2.
4. Perform DFS on four directions and change those value to 2 since they all come under same island.
5. Consider boundary cases and skip DFS for out of bound elements.

    Time Complexity : O(m*n)

    Space Complexity : O(Min(m,n))

BFS Approach:
1. Traverse through the matrix
2. If the element is not visited and it's value is 1, Increment Island count.
3. Make it visited by changin it's value to 2.
4. Perform BFS on four directions by adding them into queue and change those value to 2.

