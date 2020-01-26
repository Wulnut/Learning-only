/*
迷宫为：
....S*
.***..
.*..*.
*.***.
.T....

.表示路
*表示墙壁
S表示起点
T表示终点
用m表示走过的路
求走到出口的最短路径
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
string maze[110];
bool vis[110][110];
int dir[4][2] = {{-1,0}, {0, -1}, {1,0}, {0, 1}};//一般是逆时针的方向,方便于 ++ -- 取模。
int ans = 1000000000;

bool in(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m; 
}

void dfs(int x, int y, int steep){
    if (maze[x][y] == 'T'){
        if (steep < ans) {
            ans = steep;
        }
        return ;
    }
    vis[x][y] = 1;

    for ( int i =0; i < 4; ++i) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];

        if ( in(tx, ty) && maze[tx][ty] != '*' && !vis[tx][ty] ) {
            dfs(tx, ty, steep+1);
        }
    }

    vis[x][y] = 0;
}


int main(){
    int x, y;
    cin >> n >> m;

    for ( int i = 0; i < n; ++i){
        cin >> maze[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'S') {
                x = i, y = j;
            }
        }
    }

    dfs(x, y, 0);
    cout << ans << endl;

    return 0;
}