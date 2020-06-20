/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        if (matrix.empty() || matrix[0].empty()) return {};
        int height = matrix.size(), width = matrix[0].size();
        vector<int> res;
        int up = 0, down = height - 1, left = 0, right = width - 1;
        while (true) {
            //从左往右
            for(int j=left;j<=right;j++)
               res.push_back(matrix[up][j]);
            //上面大于下面
            if(++up>down)
                break;
            
            //从右上往右下
            for(int i=up;i<=down;i++)
                res.push_back(matrix[i][right]);
            //右边小于左边
            if(--right<left)
                break;
            
            //从右下往左下
            for(int j=right;j>=left;j--)
                res.push_back(matrix[down][j]);
            //下边小于上面
            if(--down<up)
                break;
            
            //从左下往左上
            for(int i=down;i>=up;i--)
                res.push_back(matrix[i][left]);
            //左边超过了右边
            if(++left>right)
                break;
        }
        return res;
    }
};
// @lc code=end

