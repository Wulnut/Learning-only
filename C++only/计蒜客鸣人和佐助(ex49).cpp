//https://nanti.jisuanke.com/t/T1214
#include <bits/stdc++.h>
using namespace std;

char maze[205][205];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool vis[205][205];
int n, m, t;
// m行 n列

struct node {
    int x;
    int y;
    int time; // 花费时间
    int t; // 当前所含查克拉

    node(int X, int Y, int Time, int T) : x(X), y(Y), time(Time), t(T) {}
    
    friend bool operator < (const node &A, const node &B) {

        if (A.time == B.time) {
            return A.t < B.t;
        }

        return A.time > B.time;
    }


};

int bfs(int x, int y) {

    vis[x][y] = true;

    priority_queue<node> q;

    q.push(node(x, y, 0, t));

    while (!q.empty()) {

        node now = q.top();
        q.pop();

        for (int i = 0; i < 4; ++ i) {
            int tx = now.x + dir[i][0];
            int ty = now.y + dir[i][1];

            if (0 > tx || tx > m || 0 > ty || ty > n || vis[tx][ty] || (now.t <= 0 && maze[tx][ty] == '#'))
                continue;
            
            if (maze[tx][ty] == '+') {
                return now.time + 1;
            } else if (maze[tx][ty] == '#') {
                vis[tx][ty] = true;
                now.t -- ;
                now.time ++;
                q.push(node(tx, ty, now.time, now.t));
            } else {
                vis[tx][ty] = true;
                now.time ++ ;
                q.push(node(tx, ty, now.time, now.t));
            }
        }
    }

    return -1;

}


int main() {

    int i = 0, j = 0;
    int flag = -1;

    cin >> n >> m >> t;

    // 输入地图
    for (i = 0; i < m; ++i) cin >> maze[i];

    // 驯悍找到鸣人位置
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            
            if (maze[i][j] == '@') {
                flag = bfs(i, j);
                break;
            }
        }

        if (maze[i][j] == '@') break;
    }

    if (flag == -1) cout << -1 << endl;
    else cout << flag << endl;

    return 0;
}