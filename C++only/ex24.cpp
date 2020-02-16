//动态规划解决
//41143一共5个数，
/*
如果选择一个数与其相邻的两个数就不能选，例如选左数第一个数“4”那么其右边的1就不能选择
如果选择左数第二个数“1”那么其左边的“1”和右边的“4”就不能选择
求从里面选择出几个数，其和最大。
*/


#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;

int dp[7] = {1, 2, 4, 1, 7, 8, 3};
int opt[7];

int OPT(int x) {
    int i = 0;
    
    i = x;

    if (i == 0) return dp[0];
    if (i == 1) return max(dp[0], dp[1]);
    
    int A = OPT(i - 2) + dp[i];
    int B = OPT(i - 1);

    return max(A, B);
}//OPT表示最优解的意思

int dp_OPT() {
    opt[0] = dp[0];
    opt[1] = max(dp[0], dp[1]);

    for (int i = 2; i < 7; ++i) {
        int A = opt[i-2] + dp[i];
        int B = opt[i-1];
        opt[i] = max(A, B);
    }

    return opt[6];
}//dp求解

int main(){

    memset(opt, 0, sizeof(opt));
    int i = 0;

    i = dp_OPT();

    cout << i << endl;

    return 0;
}
