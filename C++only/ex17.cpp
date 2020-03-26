//ac
#include <bits/stdc++.h>
using namespace std;

char maze[205][205];
bool vis[205][205];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int n, m;

struct node {
    int x;
    int y;
    int d;
    node(int xx, int yy, int dd) : x(xx), y(yy), d(dd) {}
    friend bool operator < (const node& a, const node& b) {
        return a.d > b.d;
    }
};

int bfs(int x, int y) {
    priority_queue<node> q;
    vis[x][y] = true;
    q.push(node(x, y, 0));

    while(!q.empty()) {
        node now = q.top();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int tx = now.x + dir[i][0];
            int ty = now.y + dir[i][1];

            if (0 > tx || tx >= n || 0 > ty || ty >= m || maze[tx][ty] == '#' || vis[tx][ty])
            continue;

            if (maze[tx][ty] == 'a') {
                return now.d + 1;
            }
            else if (maze[tx][ty] == 'x') {
                vis[tx][ty] = true;
                q.push(node(tx, ty, now.d + 2));
            }
            else{
                vis[tx][ty] = true;
                q.push(node(tx, ty, now.d + 1));
            }

        }
    }

    return -1;
}

int main(){
    freopen("note.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);

    int i, j;
   // int x, y;
    int ans = -1;

    cin >> n >> m;
    for (i = 0; i < n; ++i) {
        cin >> maze[i];
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (maze[i][j] == 'r'){
                //x = i;
                //y = j;
                break;
            }
        }
        if (maze[i][j] == 'r') break;
    }

    ans = bfs(i, j);

    if (ans == -1) {
        cout << "Impossible" << endl;
    }
    else{
        cout << ans << endl;
    }
    return 0;
}