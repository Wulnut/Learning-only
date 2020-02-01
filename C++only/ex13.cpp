#include <bits/stdc++.h>
using namespace std;

char maze[100][100];
bool vis[100][100];
int dir[4][2] = { {-1,0}, {0, -1}, {1,0}, {0, 1}};
int n, m, ans;

struct node {
    int x;
    int y;
    int d;
    node(int xx, int yy, int dd) {
        x = xx;
        y = yy;
        d = dd;
    }
};

bool in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int bfs(int x, int y) {
    queue<node> q;
    q.push(node(x, y, 0));
    vis[x][y] = 1;

    while(!q.empty()) {
        node now = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int tx = now.x + dir[i][0];
            int ty = now.y + dir[i][1];//要使用结构体内所保存的数据不然数据不会被更新
            if (in(tx, ty) && maze[tx][ty] != '#' && !vis[tx][ty]) {
                if (maze[tx][ty] == '*') {
                    return now.d + 1;
                }
                else {
                    vis[tx][ty] = 1;
                    q.push(node(tx, ty, now.d + 1));
                }
            }
        }
    }

    return -1;
}

int main(){
    freopen("note.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);

    int i ,j;
    int x, y;
    cin >> n >> m;

    for (i = 0; i < n; ++i) {
        cin >> maze[i];
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (maze[i][j] == '@'){
                x = i;
                y = j;
                break;
            }
        }
        if (maze[i][j] == '@') break;
    }

    ans = bfs(x, y);
    
    cout << ans;
    return 0;
}
