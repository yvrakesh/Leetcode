![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0297) 

    Accepted        478,365
    Submissions     931,751
[Question Link](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) &emsp; [Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/code/0297-Serialize-And-Deserialize-Binary-Tree/sol.cpp)

Serialization : The process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Approach:

This can be done in quite a different number of ways.

Approach:

    Time Complexity : O(n)

    Space Complexity : O(h) = O(n) 

1. Serialize the string in 'Inorder' traversal of binary tree.
2. Pass the string into input string stream object (istringstream).
3. Deserialize the string back to BST in 'Inorder' traversal format.