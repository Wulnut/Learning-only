/*
 * @lc app=leetcode.cn id=5366 lang=cpp
 *
 * [5366] 检查网格中是否存在有效路径
 */
#include <vector>
// @lc code=start
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        return dfs(0, 0, grid);
    }

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int state[6][4] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 1, 0, 0},
    };

    bool dfs(int x, int y, vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (x == n - 1 && y == m - 1) return true;

        int k = grid[x][y];
        grid[x][y] = 0;

        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m || !grid[a][b]) continue;
            if (!state[k - 1][i] || !state[grid[a][b] - 1][i ^ 2]) continue;

            if (dfs(a, b, grid)) return true;
        }

        return false;
    }
};
// @lc code=end

