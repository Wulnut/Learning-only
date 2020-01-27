#include <bits/stdc++.h>
using namespace std;

int n, m;
string maze[110];
bool vis[110][110];
int dir[4][2] = {{-1,0}, {0, -1}, {1,0}, {0, 1}};//一般是逆时针的方向,方便于 ++ -- 取模。

bool in(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m; 
}

bool dfs(int x, int y){
    if (maze[x][y] == 'T')
    return true;

    vis[x][y] = 1;
    maze[x][y] = 'm';

    for (int i = 0; i < 4; ++i) {
        int t_x = x + dir[i][0];
        int t_y = y + dir[i][1];

        if (in(t_x, t_y) && maze[t_x][t_y] != '*' && !vis[t_x][t_y]) {
            if (dfs(t_x, t_y)){
                return true;
            }
        }
    }

    vis[x][y] = 0;
    maze[x][y] = '.';
    
    return false;
}


int main(){
    int x ,y;

    cin >> n >> m;

    for ( int i = 0; i < n; ++i){
        cin >> maze[i];
    }

    for ( int i = 0; i < n; ++i){
        for ( int j = 0; j < m; ++j){
            if(maze[x][y] == 'S')
            x = i;
            y = j;
        }
    }

    if (dfs(x, y)){
        for ( int i = 0; i < n; ++i){
            cout << maze[i] <<endl;
        }
    }
    else
    cout << "NO!" << endl;

    return 0;
}