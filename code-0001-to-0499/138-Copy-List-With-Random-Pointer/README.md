![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0138)

    Accepted        600,351
    Submissions     1,394,991

[Question Link](https://leetcode.com/problems/copy-list-with-random-pointer/)   &emsp; [Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/code/0138-Copy-List-With-Random-Pointer/sol.cpp)

Naive Approach: Hash Map
    
    Time Complexity : O(n)

    Space Complexity : O(n)
1. Create a new node and store the address as the value for the key (Old node's address) in a hash map.
2. Again traverse the old linked list to know the next pointer and random pointer address.
3. Using hashmap find the corresponding new linked list node addresses and create link.


Efficient Approach:

    Time Complexity : O(n)

    Space Complexity : O(1)
1. Create a temp node with original node value and link the node to the next of it.
2. Now we have old link node 1 -> new link node 1 -> old link node 2 -> new link node 2 .....
3. Now map random node pointers similar to that of old ones.
4. Next map next node pointers thus removing links between old and new pointers and seperating them.

    