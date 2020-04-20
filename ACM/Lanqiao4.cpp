//
// Created by 98595 on 2020/4/18.
// 蓝桥杯校内模拟
//问题描述
//　　对于一个 n 行 m 列的表格，我们可以使用螺旋的方式给表格依次填上正整数，我们称填好的表格为一个螺旋矩阵。
//　　例如，一个 4 行 5 列的螺旋矩阵如下：
//　　1 2 3 4 5
//　　14 15 16 17 6
//　　13 20 19 18 7
//　　12 11 10 9 8
//输入格式
//　　输入的第一行包含两个整数 n, m，分别表示螺旋矩阵的行数和列数。
//　　第二行包含两个整数 r, c，表示要求的行号和列号。
//输出格式
//　　输出一个整数，表示螺旋矩阵中第 r 行第 c 列的元素的值。
//样例输入
//4 5
//2 2
//样例输出
//15
//评测用例规模与约定
//　　对于 30% 的评测用例，2 <= n, m <= 20。
//　　对于 70% 的评测用例，2 <= n, m <= 100。
//　　对于所有评测用例，2 <= n, m <= 1000，1 <= r <= n，1 <= c <= m。

#include <iostream>
#define cin ios::sync_with_stdio(false); cin
using namespace std;
typedef unsigned long long ll;

const int M = 1005;
ll maze[M][M];
ll n, m;
ll x, y;

int main() {

    cin >> n >> m >> x >> y;

    int sum = n * m;
    int row = 0, column = 0, count = 1;
    maze[row][column] = 1;

    while (count < sum)
    {
        // 向右走，直到走到头或者下一个已经走过
        while (column + 1 < m && !maze[row][column+1])
            maze[row][++column] = ++count;
        // 向下走，直到走到头或者下一个已经走过
        while (row + 1 < n && !maze[row+1][column])
            maze[++row][column] = ++count;
        // 向左走，直到走到头或者下一个已经走过
        while (column - 1 >= 0 && !maze[row][column-1])
            maze[row][--column] = ++count;
        // 向上走，直到走到头或者下一个已经走过
        while (row - 1 >= 0 && !maze[row-1][column])
            maze[--row][column] = ++count;
    }

    cout << maze[x - 1][y - 1];

//    cout << maze[x][y] << '\n';

    return 0;
}
