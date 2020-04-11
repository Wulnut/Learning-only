// 洛谷最大正方形
// dp解法

#include <bits/stdc++.h>
using namespace std;

const int M = 111;

int dp[M][M];
int n, m, ans;

int Min(int a, int b, int c) {
    return min(min(a, b), c);
}

int main() {

    freopen("note.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            int a = 0;
            cin >> a;
            dp[i][j] = a ? Min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + a : 0;
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;

    return 0;
}