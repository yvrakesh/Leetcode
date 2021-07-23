Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

    Input: nums = [2,7,11,15], target = 9

    Output: [0,1]

    Output: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

    Input: nums = [3,2,4], target = 6

    Output: [1,2]

Example 3:

    Input: nums = [3,3], target = 6

    Output: [0,1]

Constraints:

    2 <= nums.length <= 104

    -109 <= nums[i] <= 109

    -109 <= target <= 109

    Only one valid answer exists.


Brute Force Approach 

Time Complexity : O(n^2)

Space Complexity : O(n)

    class Solution {
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


Efficient Approach :

Time Complexity : O(nlogn) + O(2*n)  => O(nlogn) (For Sorting + For 2 way sum)

Space Complexity : O(n)
                 
    class Solution {
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