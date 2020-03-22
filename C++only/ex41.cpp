// 问题描述
// 　　一个正整数如果任何一个数位不大于右边相邻的数位，则称为一个数位递增的数，例如1135是一个数位递增的数，而1024不是一个数位递增的数。
// 　　给定正整数 n，请问在整数 1 至 n 中有多少个数位递增的数？
// input:30 output: 26

#include <bits/stdc++.h>
using namespace std;

int solve(const int& a) {
    bool flag = true;
    int count = 0;

    if (a == 10) return 9;
    if (a < 10) return a;

    for (int i = 11; i <= a; ++ i) {
        string str;
        stringstream ss;

        ss << i;
        ss >> str;

        for (int j = 0; j < str.length() - 1; ++ j) {
            if (str[j] > str[j + 1]) {
                flag = false;
                break;
            }
            else flag = true;
        }

        if (flag) ++ count;
    }

    return count + 9;
}


int main() {

    string str;
    int count = 0;
    int a = 0;
    stringstream ss;

    cin >> a;
    
    count = solve(a);

    cout << count << endl;
    
    return 0;
}

// 在二叉树中，满足一个条件: 度为2的节点个数总比叶子节点个数少一个，即n2=n0-1
// 在完全二叉树中，又满足一个条件，总节点数为偶数时，度为1的节点数为1个；总节点数为奇数时，度为1的节点个数为0
// 本题中，总节点数为2018，是偶数，所以n1=1
// 将n2=n0-1代入n=n0+n1+n2中，可得n=2n0，则叶子节点数，也就是n0=n/2=1009,答案就出来了
// 同样的，当总节点数为奇数时，n1=0，n=n0+0+n0-1，即n=2n0-1，n0=(n+1)/2
// 所以，可以得出结论，具有n个节点的完全二叉树，其叶子节点个数为n0/2【n为偶数】或者(n+1)/2【n为奇数】