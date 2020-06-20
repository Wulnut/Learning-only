/*
 * @lc app=leetcode.cn id=1000 lang=cpp
 *
 * [1000] 合并石头的最低成本
 */

// @lc code=start
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        
        for (int i = 1; i < stones.size(); ++i) {
            stones[i] += stones[i - 1];
        }

        for (int len = 1; len <=n; ++len) {
            for (int i = 0; i + len - 1 <= n; ++ i) {
                int j = i + len - 1;
                da[]
            }
        }
    }
};
// @lc code=end
