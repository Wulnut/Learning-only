//poj No.2386
#include <bits/stdc++.h>
using namespace std;

char maze[105][105];
int dir[8][2] = {{-1, 0}, {-1, 1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
int n, m;

bool in (int x , int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs (int x, int y) {
   maze[x][y] = '.';

    for (int i = 0; i < 8; ++i) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];

        if ( in(tx, ty) && maze[tx][ty] == 'W') {
            dfs(tx, ty);
        }
    }
}

int main(){
    int ans;

    cin >> n >> m;
    //freopen("note.txt", "r", stdin);
    //freopen("ans.txt", "w", stdout);

    for ( int i = 0; i < n; ++i) {
        cin >>maze[i];
    }

    for (int i = 0; i < n; ++i) {
        for ( int j = 0; j < m; ++j) {
            if (maze[i][j] == 'W') {
                dfs(i ,j);
                ans ++;
            }
        }
    }

    cout << ans;

    return 0;
}