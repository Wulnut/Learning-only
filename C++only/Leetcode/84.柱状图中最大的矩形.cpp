/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include <vector>
#include <stack>
#include <algorithm>
// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> s; // 单调递增栈

        heights.push_back(0); // 压入第一个作为哨兵
        int sum = 0;

        for (int i = 0; i < heights.size(); ++ i) {
            
            if (s.empty() || heights[i] > heights[s.top()]) s.push(i);

            else {
                int tmp = s.top();
                s.pop();
                sum = max(sum, heights[tmp] * (s.empty() ? i : i - s.top() - 1));
                i --;
            }

        }

        return sum;
    }
};
// @lc code=end

