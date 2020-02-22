#include <bits/stdc++.h>
using namespace std;

const int N = 10001;
int heap[N];
int size;

void push(int x) {
    int i = size++ ;//important

    while (i > 0) {
        int p = (i - 1) >> 2;

        if (heap[p] <= x) break;

        heap[i] = heap[p];
        i = p;
    }

    heap[i] = x;
}

int pop() {
    int ret = heap[0];

    int x = heap[--size];

    int i = 0;

    while (i * 2 + 1 < size) {
        int a = i * 2 + 1, b = i * 2 + 2;

        if (b < size && heap[a] > heap[b]) a = b;

        if (heap[a] >= x) break;

        heap[i] = heap[a];
        i = a;
    }

    heap[i] = x;

    return ret;
}

void print() {
    for (int i = 0; i < 3; i++) {
        cout << heap[i] << " ";
    }
}

int main() {
    int x;
    for (int i = 0 ; i < 3; ++ i) {
        cin >> x;
        push(x);
    }

    print();

    return 0;
}
