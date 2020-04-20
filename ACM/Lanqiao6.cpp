//
// Created by 98595 on 2020/4/18.
// https://blog.csdn.net/qq_42815590/article/details/103544729?depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-1&utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-1
// 蓝桥杯校内模拟
// 问题描述
//　　小明和朋友们一起去郊外植树，他们带了一些在自己实验室精心研究出的小树苗。
//　　小明和朋友们一共有 n 个人，他们经过精心挑选，在一块空地上每个人挑选了一个适合植树的位置，总共 n 个。他们准备把自己带的树苗都植下去。
//　　然而，他们遇到了一个困难：有的树苗比较大，而有的位置挨太近，导致两棵树植下去后会撞在一起。
//　　他们将树看成一个圆，圆心在他们找的位置上。如果两棵树对应的圆相交，这两棵树就不适合同时植下（相切不受影响），称为两棵树冲突。
//　　小明和朋友们决定先合计合计，只将其中的一部分树植下去，保证没有互相冲突的树。他们同时希望这些树所能覆盖的面积和（圆面积和）最大。
//输入格式
//　　输入的第一行包含一个整数 n ，表示人数，即准备植树的位置数。
//　　接下来 n 行，每行三个整数 x, y, r，表示一棵树在空地上的横、纵坐标和半径。
//输出格式
//　　输出一行包含一个整数，表示在不冲突下可以植树的面积和。由于每棵树的面积都是圆周率的整数倍，请输出答案除以圆周率后的值（应当是一个整数）。
//样例输入
//6
//1 1 2
//1 4 2
//1 7 2
//4 1 2
//4 4 2
//4 7 2
//样例输出
//12
//评测用例规模与约定
//　　对于 30% 的评测用例，1 <= n <= 10；
//　　对于 60% 的评测用例，1 <= n <= 20；
//　　对于所有评测用例，1 <= n <= 30，0 <= x, y <= 1000，1 <= r <= 1000。

#include <iostream>
#include <algorithm>
#include <cmath>
#define cin ios::sync_with_stdio(false); cin
using namespace std;

const int M = 1005;
int n;

int x[M], y[M], r[M];

double pi = acos( - 1);

bool vis[M];
int ans;

bool check(int i) {
    for (int j = 0; j < n; ++ j) {
        if (i != j && vis[j]) {
            int dis = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (dis < (r[i] + r[j]) * (r[i] + r[j])) return false;
        }
    }

    return true;
}

void dfs(int step, int sum) {
    if (step == n) {
        ans = max(ans, sum);
        return ;
    }

    for (int i = 0; i < n; ++ i) {
        if (!vis[i]) {

            int temp = r[i];

            if (!check(i)) {
                r[i] = 0;
            }

            vis[i] = true;
            dfs(step + 1, sum + r[i] * r[i]);
            vis[i] = false;
            r[i] = temp;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++ i) {
        cin >> x[i] >> y[i] >> r[i];
    }

    dfs(0,0);

    cout << ans;

    return 0;
}
