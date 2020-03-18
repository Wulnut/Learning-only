#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;

vector<int> G[MAX];
int V;
int color[MAX];

bool dfs(int v, int c) {
    color[v] = c;
    
    for (int i = 0 ; i < G[v].size(); ++ i) {

        if (color[G[v][i]] == 0) {
            if (!dfs(G[v][i], -c)) return false;
        }

        if (color[G[v][i]])
        return ;
    }
}

void solve() { 
    //cout << "V: " << V << endl;

    for (int i = 0; i < V; ++i) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                cout << "no" << endl;
            }
        }
    }

    cout << "yes" << endl;
}

int main() {
    cin >> V;
    solve();
    return 0;
}