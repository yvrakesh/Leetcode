#pragma GCC optimize("Ofast")
class MedianFinder {
#include<bits/stdc++.h>
    double median;
    // Max heap for 1st half
    priority_queue<int> max_heap;
    // Min heap for 2nd half
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    // Constructor
    MedianFinder() {
        ios_base::sync_with_stdio(false);    
        cin.tie(NULL);
    }
    // Inserting a new element
    void addNum(int num) {
        // Increase left half size in case of equal count
        if(max_heap.size() == min_heap.size()){
            min_heap.push(num);
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        // If left half size is greater than right half size
        else if(max_heap.size() > min_heap.size()){
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    double findMedian(){
        // If no element is present
        if(max_heap.empty())
            return 0;
        // If left half count equal to right half count
        // i.e. if even size so return average of both the middle elements
        if(max_heap.size() == min_heap.size())
            return (max_heap.top() + min_heap.top())/2.0;
        // return the middle element
        return max_heap.top();
    }
};