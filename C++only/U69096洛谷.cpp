//
// Created by 98595 on 2020/4/5.
//
#include <iostream>
using namespace std;

const int M = 1000;
int A[M];
int B[M];

int main() {
    int n = 0;
    for (int i = 0; i < n; ++ i) cin >> B[i];
    A[0] = B[0];

    for (int i = 1; i < n; ++ i) {
        A[i] = B[i] - B[i - 1];
    }

    for (int i = 0; i < n; ++ i) {
        cout << A[i] << " ";
    }
    
    return 0;
}
