#pragma GCC optimize("Ofast")
class MedianFinder {
#include<bits/stdc++.h>
    double median;
    // Max heap for 1st half
    priority_queue<int> max_heap;
    // Min heap for 2nd half
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        ios_base::sync_with_stdio(false);    
        cin.tie(NULL);
        this->median = 0;
    }
    // Inserting a new element
    void addNum(int num) {
        // Check if both min heap and max heap sizes are equal
        if(max_heap.size() == min_heap.size()){
            // So now as both are of equal size we can add to either of them.
            // So let's do based on the median.
            // If the number is less than the previous median, then insert it to the left half.
            if((double)num < median){
                max_heap.push(num);
                median = max_heap.top();
            }
            // Else insert it to the right half
            else{
                min_heap.push(num);
                median = min_heap.top();
            }
        }
        // If left half size is greater than right half size
        else if(max_heap.size() > min_heap.size()){
            // If number is less than median insert 1st half top to the 2nd half.
            // Pop 1st half element and insert the number.
            if((double)num < median){
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
            else{
                min_heap.push(num);
            }
            median = (max_heap.top() + min_heap.top())/2.0;
        }
        else{
            if((double)num > median){
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
            else{
                max_heap.push(num);
            }
            median = (max_heap.top() + min_heap.top())/2.0;
        }
    }
    
    double findMedian() {
        return median;
    }
};