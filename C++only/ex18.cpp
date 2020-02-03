#include <bits/stdc++.h>
using namespace std;

struct node {
    int num[4];
    int step;
}first, last;

bool vis[11][11][11][11];

void bfs() {    
    int i;
    node a, next;
    queue<node> q;
    a = first;
    a.step = 0;
    q.push(a);
    //memset(vis, 0, sizeof(vis));
    vis[a.num[0]][a.num[1]][a.num[2]][a.num[3]] = 1;
    while(!q.empty()) {
        a = q.front();
        q.pop();
        //bfs 出口
        if (a.num[0] == last.num[0] && a.num[1] == last.num[1] &&
            a.num[2] == last.num[2] && a.num[3] == last.num[3])
            cout << a.step <<endl;
            return ;
        
        for (i = 0; i < 4; ++i) {
            next = a;
            next.num[i] ++ ;
            if (next.num[i] == 10) {
                next.num[i] = 1;
            }
            if (!vis[next.num[0]][next.num[1]][next.num[2]][next.num[3]]) {
                vis[next.num[0]][next.num[1]][next.num[2]][next.num[3]] = 1;
                next.step ++ ;
                q.push(next);
            }
        }

        for (i = 0; i < 4; ++i) {
            next = a;
            next.num[i]--;
            if (next.num[i] == 0) {
                next.num[i] = 9;
            }
            if (!vis[next.num[0]][next.num[1]][next.num[2]][next.num[3]]) {
                vis[next.num[0]][next.num[1]][next.num[2]][next.num[3]] = 1;
                next.step ++ ;
                q.push(next);
            }
        }

        for (i = 0; i < 3; ++i) {
            next = a;
            next.num[i] = a.num[i + 1]; 
            next.num[i + 1] = a.num[i];
            if (!vis[next.num[0]][next.num[1]][next.num[2]][next.num[3]]) {
                vis[next.num[0]][next.num[1]][next.num[2]][next.num[3]] = 1;
                next.step ++ ;
                q.push(next);
            }
        }
    }
}

int main(){

    char f[20];
    char l[20];

    cin >> f >> l;

    for (int i = 0; i < 4; ++i) {
        first.num[i] = f[i] - '0'; //转换成相应数值
        last.num[i] = l[i] - '0'; //转换成相应数值
    }

    bfs();

    return 0;
}