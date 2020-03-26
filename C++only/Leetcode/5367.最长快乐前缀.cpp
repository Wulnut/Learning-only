/*
 * @lc app=leetcode.cn id=5367 lang=cpp
 *
 * [5367] 最长快乐前缀
 */
#include <string>
// @lc code=start
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<int> next(n + 1);

        for (int i = 2, j = 0; i <= n; i ++ ) {
            while (j && s[i] != s[j + 1]) j = next[j];
            if (s[i] == s[j + 1]) j ++ ;
            next[i] = j;
        }

        return s.substr(1, next[n]);
    }
};

// @lc code=end

