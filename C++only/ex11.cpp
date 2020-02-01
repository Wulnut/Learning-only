#include <bits/stdc++.h>
using namespace std;

char maze[110][110];
bool vis[110][110];
int dir[4][2] = {{-1,0}, {0, -1}, {1,0}, {0, 1}};
int n, m, ans;
int ct;

bool in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x, int y) {
    int tx, ty;

    vis[x][y] = 1;

    if (maze[x][y] == '#') {
        return ;
    }

    for (int i = 0; i < 4; ++i) {
        tx = x + dir[i][0];
        ty = y + dir[i][1];
        if (in(tx, ty) && maze[tx][ty] != '#' && !vis[tx][ty]) {
            if (maze[tx][ty] == '.'){
                ans ++;
                dfs(tx, ty);
            }
        }
    }
}

void print(){
    cout << ans + 1 << endl;
}

int main() {
   freopen("note.txt", "r", stdin);
   freopen("ans.txt", "w", stdout);

    int i , j;
    int x, y, ans = 0;
    cin >> m >> n;

    for (i = 0; i <n; ++i) {
        cin >> maze[i];
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (maze[i][j] == '@') {
                dfs(i, j);
                break;
            }
        }
        if (maze[i][j] == '@') break;
    }

    print();

    return 0;
}