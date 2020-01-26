
#include <bits/stdc++.h>
using namespace std;

char s[10][10];
int x, y;
bool f;
int dir[8][2] = {{2,1}, {1,2}, {-1,2}, {-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
bool vis[10][10];

bool in(int x, int y) {
    return 0 <= x && x < 10 && 0 <= y && y < 9;
}

void dfs(int x, int y) {
    vis[x][y] = true;

    if (f) {
        return ;
    }
    if (s[x][y] == 'T') {
        f = true;
        return;
    }

    for ( int i = 0; i < 8; ++i ) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];

        if ( in(tx, ty) && s[tx][ty] != '#' && !vis[tx][ty] ) {
            dfs(tx, ty);
        }
    }
}

int main(){
    /*
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    文件操作读入文件和写入文件
    */

    for (int i = 0; i < 10; ++i) {
        cin >> s[i];
    }

    for ( int i = 0; i < 10; ++i) {
        for ( int j = 0; j < 9; ++j) {
            if (s[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }

    dfs(x, y);
    if (f){
        cout << "Yes\n";
    }
    else
    cout << "NO\n";

    return 0;
}
//象棋马的走法。