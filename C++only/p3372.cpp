// https://www.luogu.com.cn/problem/P3372
// 洛谷 线段树
// 学习

#include <bits/stdc++.h>
using namespace std;
#define cin ios::sync_with_stdio(false); cin

const int M = 1 << 17;

int date[2 * M - 1];
int arr[2 * M - 1];
int b[2 * M - 1]; // 标记数组

void build(int s, int t, int p) {
    // 对 [s,t] 区间建立线段树,当前根的编号为 p
    if (s == t) {
        date[s] = arr[s];
        return ;        
    }

    int m = (s + t) >> 1;
    build(s, m, p << 1), build(m + 1, t, (p << 1) + 1);
    // 递归对左右区间建树
    date[p] = date[p << 1] + date[(p << 1) + 1];
}

// 区间值查询

int query(int l, int r, int s, int t, int p) {

    if (t <= l || r <= s) {
        return INT_MIN;
    }

    // [l,r] 为查询区间,[s,t] 为当前节点包含的区间,p 为当前节点的编号
    if (l <= s && t <= r) {
        // [l, r]完全包含[s, t] 直接返回当前值
        return date[p];
    }

    int m = (s + t) >> 1;
    int sum = 0;

    if (l <= m) sum += query(l, r, s, m, p << 1);
    if (r > m)  sum += query(l, r, m + 1, t, (p << 1) + 1);

    return sum;
}

// 区间修改 区间加上某个值
void update_add(int l, int r, int c, int s, int t, int p) {
    // [l,r] 为修改区间,c为被修改的元素的变化量,[s,t] 为当前节点包含的区间,p
    // 为当前节点的编号
    if (l <= s && t <= r) {
        date[p] += (t - s + 1) * c, b[p] = c;
        return ;
    }
    // 当前区间为修改区间的子集时直接修改当前节点的值,然后打标记,结束修改
    int m = (s + t) >> 1;

    if (b[p] && s != t) {
        // 如果当前节点的懒惰标记非空,则更新当前节点两个子节点的值和懒标记值
        date[p << 1] += b[p] * (m - s + 1), date[p << 1 | 1] += b[p] * (t - m);
        b[p << 1] += b[p], b[p << 1 | 1] += b[p]; 
        b[p] = 0;
    }

    if (l <= m) update_add(l, r, c, s, m, p << 1);
    if (r > m)  update_add(l, r, c, m + 1, t, p << 1  1);

    // 区间合并
    date[p] = date[p << 1] + date[(p << 1) + 1];
}

// 区间查询（区间求和）
int getsum(int l, int r, int s, int t, int p) {
    // [l,r] 为修改区间,c 为被修改的元素的变化量,[s,t] 为当前节点包含的区间,p
    // 为当前节点的编号
    if (l <= s && r >= t) {
        return date[p];
    }

    int m = (s + t) >> 1;
    if (b[p]) {
        // // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
        date[p << 1] += b[p] * (m - s + 1), date[(p << 1) + 1] += b[p] * (t - m);
        b[p << 1] += b[p], b[p << 1 | 1] += b[p];
        b[p] = 0;
    }

    int sum = 0;
    if (l <= m) sum  = getsum(l, r, s, m, p << 1);
    if (r > m)  sum += getsum(r, s, m + 1, t, p << 1 | 1);

    return sum;  
}
// 实现区间修改为某一个值而不是加上某一个值
void update(int l, int r, int c, int s, int t, int p) {
    if (l <= s && r >= t) {
        date[p] = (t - s + 1) * c, b[p] = c;
        return ; 
    }

    int m = (s + t) << 1;
    if (b[p]) {
        date[p << 1] = (m - s + 1) * b[p], date[p << 1 | 1] = b[p] * (t - m);
        b[p << 1] = b[p << 1 | 1] = b[p];
        b[p] = 0;
    }
}
int getsum_u(int l, int r, int s, int t, int p) {
    if (l <= s && t <= r) return date[p];
    int m = (s + t) << 1;

    if (b[p]) {
        date[p << 1] = (m - s + 1) * b[p], date[(p << 1) + 1] = b[p] * (t - m);
        b[p << 1] = b[p << 1 | 1] = b[p];
        b[p] = 0;
    }

    int sum  = 0;
    if (l <= m) sum  = getsum_u(l, r, s, m, p << 1);
    if (r > m)  sum += getsum_u(l, r, m + 1, t, p << 1 | 1);
    return sum;
}

int main() {

    return 0;
}