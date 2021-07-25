class Solution {
#include<bits/stdc++.h>
public:
    vector <int> twoSum(vector <int>& nums, int target) {
        int vec_len = nums.size();
        vector <int> res;
        vector <int> nums_orig = nums;
        sort(nums.begin(),nums.end());
        int left = 0, right = vec_len-1;
        while(left<right){
            if(nums[left]+nums[right] > target)
                right--;
            else if(nums[left]+nums[right] < target)
                left++;
            else{
                for(int i=0;i<vec_len;i++){
                    if(nums_orig[i] == nums[left]){
                        res.push_back(i);
                        break;
                    }
                }
                for(int i=0;i<vec_len;i++){
                    if(nums_orig[i] == nums[right] && i != res[0]){
                        res.push_back(i);
                        break;
                    }
                }
                break;
            }
        }
        return res;
    }
};