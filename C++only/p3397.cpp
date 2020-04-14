// https://www.luogu.com.cn/problem/P3397
// 洛谷 算法标签：差分

#include <bits/stdc++.h>
using namespace std;

#define cin ios::sync_with_stdio(false); cin

const int M = 1005;

int maze[M][M];
int n, m;
pair<int, int> pos_1; // 用x_1,y_2 比pair好
pair<int, int> pos_2; // 用x_2, y_2比pair好

int main() {

    freopen("note.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);

    cin >> n >> m;

    while (-- m) {
        cin >> pos_1.first >> pos_1.second
            >> pos_2.first >> pos_2.second;

        for (int i = pos_1.first; i <= pos_2.first; ++ i) {
            
            maze[i][pos_1.second] ++;
            maze[i][pos_2.second + 1] --;
        }
    }

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            maze[i][j] += maze[i][j - 1];
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}