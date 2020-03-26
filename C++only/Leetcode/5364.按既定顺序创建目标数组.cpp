/*
 * @lc app=leetcode.cn id=5364 lang=cpp
 *
 * [5364] 按既定顺序创建目标数组
 */
#include <vector>
// @lc code=start
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        
        vector<int> target;

        for (int i = 0; i < nums.size(); i ++ )
            target.insert(target.begin() + index[i], nums[i]);

        return target;
    }
};
// @lc code=end

