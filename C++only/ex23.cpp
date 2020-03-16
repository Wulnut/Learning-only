#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;

int dp[MAX];
int ans;

int fib(int x) {

    if (dp[x] >= 0) return dp[x]; //可以认为dp数组的便宜量是用标记是否到达过该位置的标志，而偏移量所存储
    if (x == 1 || x == 2) return 1;//的数值用来记忆化数据，和剪枝类似。

    return dp[x] = fib(x - 1) + fib(x - 2);
}//记忆化解决斐波拉且数列

void fibb(int x) {
    int i = 2;
    dp[0] = 0;
    dp[1] = 1;
    
    for ( i; i < x; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }//动态规划实现

    cout << dp[i];
}

int main(){

    memset(dp, -1, sizeof(dp));//memset可以用来初始化数组；
    int i = 0;

    cin >> i;

    //i = fib(i);

    //cout << i;

    fibb(i);

    return 0;
}