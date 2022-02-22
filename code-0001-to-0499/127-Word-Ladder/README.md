![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0127)

    Accepted        614,452
    Submissions     1,858,354

[Question Link](https://leetcode.com/problems/word-ladder/)   &emsp; [Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/code/0127-Word-Ladder/sol.cpp)  

Approach: BFS

    Time Complexity : O


Note: 
1. BFS or DFS can be used for finding shortest path in trees since there is only unique path between two nodes.
2. But this is not the case with graphs, since many paths exists we should use BFS to find shortest path.
3. BFS will take polynomial time whereas DFS will take exponential time.

Procedure:

1. Insert word list into unordered set and check if end element is present in the wordlist, else return 0.
2. Push start node into queue and apply BFS.
3. Change one of the digits to 'a' to 'z' and check if the new word present in the wordlist.
4. If then push it into the queue.
5. Change depth levels accordingly. 