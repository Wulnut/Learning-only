// https://www.acwing.com/problem/content/description/284/

#include <bits/stdc++.h>
using namespace std;

const int N = 310;
int n;
int s[N]; // 前缀和
int dp[N][N];

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> s[i], s[i] += s[i - 1];

    for (int len = 2; len <= n; ++ len) { // 先枚举区间长度
        for (int i = 1; i + len - 1 <= n; ++ i) { // 再枚举区间左端点

            int j = i + len - 1; // 区间右端点
            dp[i][j] = 1e8;

            for (int k = i; k < j; ++ k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
            }

        }
    }

    cout << dp[1][n] << endl; // 满足分析法的定义

    return 0;
}