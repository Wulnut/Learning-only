/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <vector>
// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 对于特殊情况的特判
        if (intervals.size() == 0 || intervals.size() == 1) return intervals;

        // 双指针
        int save = 0; //用于保存的数组
        int scan = 0; // 用户扫描的数组

        vector<vector<int>> result;
        sort (intervals.begin(), intervals.end());

        while (scan < intervals.size()) {

            if (intervals[scan][0] > intervals[save][1]) {
                result.emplace_back(intervals[save]);
                save = scan;
            } else if (intervals[scan][1] <= intervals[save][1]) {
                ++ scan;
            } else {
                intervals[save][1] = intervals[scan][1];
                ++ scan;
            }

        }

        result.emplace_back(intervals[save]);

        return result;
    }
};
// @lc code=end

