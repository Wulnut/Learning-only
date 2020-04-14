// https://www.luogu.com.cn/problem/P2280
// 洛谷

#include <bits/stdc++.h>
using namespace std;
#define cin ios::sync_with_stdio(false); cin

const int M = 5005;
int maze[M][M];

int n, m;
int row, colnum;

int a, b;
int w;

int main() {

    cin >> n >> m;
    row = colnum = m;

    for (int i = 1; i <= n; ++ i) {
        cin >> a >> b >> w;

        a ++ , b++;

        maze[a][b] = w;
        
        row = max(row, a);
        colnum = max(colnum, b);
    }    

    for (int i = 1; i <= row; ++ i) {
        for (int j = 1; j <= colnum; ++ j) {
            maze[i][j] = maze[i - 1][j] + maze[i][j - 1] - maze[i - 1][j -1] + maze[i][j];
        }
    }

    int ans = 0;
    for (int i = m; i <= row; ++ i) {
        for (int j = m; j <= colnum; ++ j) {
            ans = max(ans, maze[i][j] - maze[i - m][j] - maze[i][j - m] + maze[i - m][j - m]);
        }
    }

    cout << ans << "\n";

    return 0;
}