/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tempSum, maxSum, tempSumIter;
        maxSum = tempSum = nums[0];
        for (int j = 1; j < int(nums.size()); j++) {
            // cout << nums[j] << endl;
            tempSumIter = tempSum + nums[j];
            if (nums[j] < tempSumIter) {
                tempSum = tempSumIter;
            }
            else {
                tempSum = nums[j];
            }
            if (tempSum > maxSum) {
                maxSum = tempSum;
            }
            // cout << nums[j] << " The max sum is: " << maxSum << " The temp sum is: " << tempSum << endl;
            
        }
        return maxSum;
    }
};
// @lc code=end

