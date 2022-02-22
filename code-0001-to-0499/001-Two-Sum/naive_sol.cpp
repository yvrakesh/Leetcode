class Solution {
#include<bits/stdc++.h>
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int vec_len = nums.size();
        vector <int> temp;
        for(int i=0;i<vec_len;i++){
            for(int j=i+1;j<vec_len;j++){
                if(nums[i]+nums[j] == target){
                    temp.push_back(i);
                    temp.push_back(j);
                    return temp;
                }
            }
        }
        return temp;
    }
};