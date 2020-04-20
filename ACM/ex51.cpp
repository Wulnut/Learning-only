//
// Created by 98595 on 2020/4/1.
// 前缀和
//
#include <iostream>
using namespace std;

const int M = 10000;
int N;
int A[M];
int B[M];


int main() {
      cin >> N;
      for (int i = 0; i < N; ++ i) cin >> A[i];

      B[0] = A[0];

      for (int i = 1; i < N; ++ i) {
          B[i] = B[i - 1] + A[i];
      }

      for (int i = 0; i < N; ++ i) cout << B[i] << " ";

    return 0;
}

