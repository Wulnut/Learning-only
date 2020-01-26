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
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
string maze[110];//储存迷宫
bool vis[110][110];

bool in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool dfs(int x, int y){

    if (maze[x][y] == 'T') //首先规定递归出口
    return true;

    vis[x][y] = 1;
    maze[x][y] = 'm';

    int t_x = x - 1, t_y = y;//向上走
    if (in(t_x, t_y) && maze[t_x][t_y] != '*' && !vis[t_x][t_y]){
        if (dfs(t_x, t_y)){
            return true;
        }
    }

    t_x = x, t_y = y - 1;//向左走
    if (in(t_x, t_y) && maze[t_x][t_y] != '*' && !vis[t_x][t_y]){
        if (dfs(t_x, t_y)){
            return true;
        }
    }

    t_x = x + 1, t_y = y;//向下走
    if (in(t_x, t_y)  && maze[t_x][t_y] != '*' && !vis[t_x][t_y]){
        if (dfs(t_x, t_y)){
            return true;
        }
    }

    t_x = x, t_y = y + 1;//向右走
    if (in(t_x, t_y) && maze[t_x][t_y] != '*' && !vis[t_x][t_y]){
        if (dfs(t_x, t_y)){
            return true;
        }
    }

    vis[x][y] = 0; //如果走的路不对还原
    maze[x][y] = '.'; //如果失败将走过的路还原
    
    return false;
}


int main(){
    //输入迷宫
    int  x, y;

    cin >> n >> m;

    for ( int i  = 0; i < n; ++i ){
        cin >> maze[i];
    }

    for ( int i = 0; i < n; ++i ){
        for ( int j = 0; j < m; ++j ){
            if (maze[i][j] == 'S'){
                x = i, y = j;
            }
        }
    }

    if (dfs(x, y)){
        for (int i =0; i < n; ++i){
            cout << maze[i] << endl;
        }
    }
    else
    cout << "NO!" << endl;
    
    return 0;
}
//方向写的过于复杂代码量略高