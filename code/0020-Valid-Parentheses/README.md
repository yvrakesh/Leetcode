![visitor badge](https://visitor-badge.glitch.me/badge?page_id=yvrakesh.Leetcode-0020)

    Accepted        1,548,902
    Submissions     3,847,641

[Question Link](https://leetcode.com/problems/valid-parentheses/)   &emsp; [Solution Link](https://github.com/yvrakesh/Leetcode/blob/main/code/0020-Valid-Parentheses/sol.cpp)

Approach: 

    Time Complexity : O(n)

    Space Complexity : O(n)

1. Add all opening brackets into stack.
2. If you encounter a closing bracket then pop the top element from the stack and check if it's the opening bracket.
3. Else return false. Also check if stack size is greater than half the string size if, then return false.
4. After entire iteration check if stack is empty if then true else false.
