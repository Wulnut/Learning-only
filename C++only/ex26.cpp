#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int maze[N][N];
bool vis[N][N];
int step[N][N];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int n, m;
queue<pair<int , int>> p;

bool in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool fly(int x, int y) {
    int i = x;
    int j = y;
        if (in(i, j + 2) && maze[i][j + 2] != -1)
        return true;
        else{
            return false;
        }
}

int bfs(int x, int y) {
    p.push(make_pair(x, y));
    vis[x][y] = true;

    while(!p.empty()) {
        pair<int, int> now = p.front();
        p.pop();

        for (int i = 0; i < 4; ++i) {
            int tx = now.first + dir[i][0];
            int ty = now.second + dir[i][1];

            if (in(tx, ty) && !vis[tx][ty]){
                if (maze[tx][ty] == -1 && fly(tx, ty)) {
                    vis[tx][ty + 2] = true;
                    p.push(make_pair(tx,ty + 1));
                    step[tx][ty + 2] = step[now.first][now.second] + 1;
                }
            }

            if (in(tx, ty) && !vis[tx][ty] && maze[tx][ty] != -1) {
                if (maze[tx][ty] == 0)
                return step[tx][ty] = step[now.first][now.second] = 1;
            }

            if (vis[tx][ty] && maze[tx][ty] != -1 && !vis[tx][ty]) {
                if (maze[tx][ty] == 1){
                vis[tx][ty] = true;
                p.push(make_pair(tx, ty));
                step[tx][ty] = step[now.first][now.second] + 1;
                }
            }
        }
    }

    return -1;
}

int main(){
    freopen("note.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);

    int i, j, ans;
    cin >> n >> m;

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j)
        cin >> maze[i][j];
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
        if (maze[i][j] == 0)
        vis[i][j] = true;
        ans = bfs(i, j);
        break;
        }
        if (maze[i][j] == 0)
        break;
    }  

    cout << ans;
    return 0;
}