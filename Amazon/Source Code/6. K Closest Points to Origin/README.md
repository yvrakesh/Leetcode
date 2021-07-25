    Accepted        510,725
    Submissions     783,914
Approach:

    Time Complexity : O(k + n*logn) => O(n*logn)

    Space Complexity : O(n)

1. Store pair of distance and corresponding vertices pair in a vector.
2. Sort the vector on basis of distance.
3. Copy first k elements into the output vector.