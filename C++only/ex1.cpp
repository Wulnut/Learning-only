#include <bits/stdc++.h>
using namespace std;

/*
     2
    / \
   3   4
      / \
     5   6

搜索该树的某数子的深度

例如：3 深度为 2
*/



struct TreeNode{
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} //构造函数
};

int minDepth(TreeNode* root) {
    if (!root) return 0;
    int right = minDepth(root -> right);
    int left = minDepth(root -> left);
    if( !left || !right) return left + right +1;
    return min(left, right) + 1;
}


int main(){
    return 0;
}