/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */
 #include <vector>
 #include <stack>
// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        // 判断行列是否均为0

        int H = matrix.size(), W = matrix[0].size();
        int height[W+1];
        int i, j , MAX = 0;
        stack<int> st;

        memset(height, 0, sizeof(height)); // 给数组初始化, 数组右端端又会有一个哨兵

        for (i = 0; i < H; ++ i) {

            while (!st.empty()) st.pop(); // 每次循环均清空栈

            for (j = 0; j < W; ++j) {

                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;

            }

            for (int j = 0; j <= W; ++j) {

                while (!st.empty() && height[st.top()] > height[j]) {

                    int tmp = st.top();
                    st.pop();

                    MAX = max(MAX, height[tmp] * (st.empty() ? j : j - st.top() - 1)); // 求最大面积

                }

                st.push(j); // 压入单调栈
            }

        }

        return MAX;

    }
};
// @lc code=end

