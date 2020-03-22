// 问题描述
// 　　小明有一块空地，他将这块空地划分为 n 行 m 列的小块，每行和每列的长度都为 1。
// 　　小明选了其中的一些小块空地，种上了草，其他小块仍然保持是空地。
// 　　这些草长得很快，每个月，草都会向外长出一些，如果一个小块种了草，则它将向自己的上、下、左、右四小块空地扩展，这四小块空地都将变为有草的小块。
// 　　请告诉小明，k 个月后空地上哪些地方有草。
// 输入格式
// 　　输入的第一行包含两个整数 n, m。
// 　　接下来 n 行，每行包含 m 个字母，表示初始的空地状态，字母之间没有空格。如果为小数点，表示为空地，如果字母为 g，表示种了草。
// 　　接下来包含一个整数 k。
// 输出格式
// 　　输出 n 行，每行包含 m 个字母，表示 k 个月后空地的状态。如果为小数点，表示为空地，如果字母为 g，表示长了草。
// 样例输入
// 4 5
// .g...
// .....
// ..g..
// .....
// 2
// 样例输出
// gggg.
// gggg.
// ggggg
// .ggg.

#include <bits/stdc++.h>
using namespace std;

char maze[1005][1005];
bool vis[1005][1005];
int dir[4][2] = { {-1,0}, {0, -1}, {1,0}, {0, 1}};
int n, m, ans;


bool in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void bfs(int x, int y) {

    queue<pair<int, int>> Q;

    Q.push(make_pair(x, y));

    while(!Q.empty()) {

        pair<int, int> now=Q.front();
        Q.pop();

        for (int i=0;i<4;i++) {

            int tx=now.first+dir[i][0];
            int ty=now.second+dir[i][1];

            if (in(tx, ty)) continue;
            maze[tx][ty]='g';

            if (!vis[tx][ty]) Q.push(make_pair(tx, ty));
        }
    }
}

void print() {
    for (int i = 0; i < n; ++ i) {
       cout << maze[i] << endl;
    }
}

int main() {

    freopen("note.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);

    int i, j;
    int x, y;
    int times = 0;

    cin >> n >> m;

    getchar();

    for (i = 0; i < n; ++ i) {
        cin >> maze[i];
    }

    getchar();

    cin >> times;

    for (int i = 0; i < times; ++ i) {
        
        for (i = 0; i < n; ++ i) {
            for (j = 0; j < n; ++ j) {
                if (maze[i][j] == 'g') {

                    x = i;
                    y = j;

                    bfs(x, y);
                }
            }
        }

    }

    print();

    return 0;
}