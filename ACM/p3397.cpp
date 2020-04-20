//
// Created by 98595 on 2020/4/14.
// https://www.luogu.com.cn/problem/P3397
// 洛谷



// https://www.luogu.com.cn/problem/P3397
// 洛谷 算法标签：差分

#include <bits/stdc++.h>
using namespace std;

#define cin ios::sync_with_stdio(false); cin

const int M = 1005;

int maze[M][M];
int n, m;
int x_1, y_1;
int x_2, y_2;
int main() {
    //freopen("note.txt", "r", stdin);
    //freopen("ans.txt", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= m; ++ i) {

        cin >> x_1 >> y_1
            >> x_2 >> y_2;

        for (int j = x_1; j <= x_2; ++ j) {
            maze[j][y_1] ++;
            maze[j][y_2 + 1] --; // 二维差分就是对每一行进行差分
        }
    }

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++j) {
            maze[i][j] += maze[i][j - 1]; // 通过前缀和还原
            cout << maze[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}