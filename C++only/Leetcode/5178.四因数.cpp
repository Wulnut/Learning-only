/*
 * @lc app=leetcode.cn id=5178 lang=cpp
 *
 * [5178] 四因数
 */
#include <vector>
// @lc code=start
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (auto x : nums) {
            int sum = 0, cnt = 0;
            for (int i = 1; i * i <= x; i ++ ) {
                if (x % i == 0) {
                    sum += i, cnt ++ ;
                    if (x / i != i) sum += x / i, cnt ++ ;
                }
            }

            if (cnt == 4) res += sum;
        }

        return res;
    }
};

// @lc code=end

