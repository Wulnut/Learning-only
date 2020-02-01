//dfs最短路径

#include <bits/stdc++.h>
using namespace std;

char maze[105][105];
bool vis[105][105];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int n, m;
int ans = 100000;

bool in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x, int y, int steep) {
    vis[x][y] = 1;

    if (maze[x][y] == 'G'){
        if (steep < ans){
            ans = steep;
        }
    }

    for (int i = 0; i < 4; ++i) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if ( in(tx, ty) && maze[tx][ty] != '#' && !vis[tx][ty]){
            dfs(tx, ty, steep + 1);
        }
    }

    vis[x][y] = 0;
}

int main(){
   // freopen("note.txt", "r", stdin);
    //freopen("ans.txt", "w", stdout);
    cin >> n >> m;

    int i , j;
    int x, y;
    int steep = 0;

    for (i = 0; i < n; ++i) {
        cin >> maze[i];
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j){
            if (maze[i][j] == 'S'){
                x = i;
                y = j;
                break;
            }
        }
        if (maze[i][j] == 'S') break;
    }

    dfs(x, y, 0);
    cout << ans << endl;
    return 0;
}