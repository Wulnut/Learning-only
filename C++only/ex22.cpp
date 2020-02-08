//binary_search

#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
int q[N];
int n = 0;

bool binary_search(int x) {
    int l = 0, r = n;

    while(r - l >= 1) {
        int i = (l + r) >> 1;
        
        if(q[i] == x) return true;
        else if (q[i] < x) l = i + 1;
        else r = i;
    }

    return false;
}

int main(){
    cin >> n;

    for (int i  = 0; i < n; ++ i) cin >> q[i];

    sort(q, q + n);

    binary_search(12);
    return 0;
}