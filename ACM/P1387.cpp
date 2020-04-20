//
// Created by 98595 on 2020/4/6.
//洛谷

#include <iostream>
#include <algorithm>
using namespace std;

int column;//  列
int row;// 行

int a[105][105];
int b[105][105];

int main() {
    //freopen("fileRead/note.txt", "r", stdin);
    //freopen("ans.txt", "w", stdout);

    cin >> row >> column;

    for (int i = 1; i <= row; ++ i) {
        for (int j = 1; j <= column; ++ j) {
            cin >> a[i][j];
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
            // 也可以写成这样 b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + b[i][j];
            // 只使用一个数组
        }
    }

    for (int i = 1; i <= row; ++ i) {
        for (int j = 1; j <= column; ++ j) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    int ans = 1;
    int l = 2;// 如果l为1是无法构成正方形

    // b[i][j] - b[i - l][j] - b[i][j - l] + b[i - l][j - l] 二维的前缀和求的是面积通过减去l来控制面积的边长
    // 对于一维的前缀和求得是长度，一位得前缀和可以用来求区间得最值
    // 二维得前缀和可以用来求区域面积
    // 建议将此题和AT2412做类比
    while (l <= min(row, column)) {

        for (int i = l; i <= row; ++ i) {
            for (int j = l; j <= column; ++ j) {
                if (b[i][j] - b[i - l][j] - b[i][j - l] + b[i - l][j - l] == l * l)
                    ans = max(ans,l);
            }
        }

        ++ l;
    }

    cout << ans << endl;

    return 0;
}
