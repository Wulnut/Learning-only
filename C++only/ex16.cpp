//ex14.cpp 的pair写法
#include <bits/stdc++.h>
using namespace std;

char maze[205][205];
bool vis[205][205];
int step[205][205];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
queue<pair<int,int>> p;
int n, m;

bool in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}
    
int bfs(int x, int y) {
    p.push(make_pair(x, y));
    vis[x][y] = 1;

    while(!p.empty()) {
        pair<int, int> now = p.front();
        p.pop();

        for (int i = 0; i < 4; ++i) {
            int tx = now.first + dir[i][0];
            int ty = now.second + dir[i][1];
            if(in(tx, ty) && maze[tx][ty] != '#' && !vis[tx][ty]) {
                if (maze[tx][ty] == 'a') {
                    return step[tx][ty] = step[now.first][now.second] + 1;
                }
                else if (maze[tx][ty] == 'x') {
                    vis[x][y] = 1;
                    p.push(make_pair(tx, ty));
                    step[tx][ty] = step[now.first][now.second] + 2;
                }
                else {
                    vis[x][y] = 1;
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

    int i, j;
    int x, y;
    int ans = -1;
    cin >> n >> m;

    for (i = 0; i < n; ++i) {
        cin >> maze[i];
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (maze[i][j] == 'r') {
                x = i;
                y = j;
                break;
            }
        }
        if (maze[i][j] == 'r') break;
    }

    ans = bfs(x, y);

    if (ans == -1){
        cout << "Impossible" << endl;
    }
    else {
        cout << ans << endl;
    }

    return 0;
}