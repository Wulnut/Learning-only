//
// Created by 98595 on 2020/4/18.
// https://www.acwing.com/blog/content/9/
// 自定义哈希表，在unordered_map和unordered_set中不能直接存入pair
// https://blog.csdn.net/cloud323/article/details/63251495这个博客可以学习一下const关键字的用法

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Myclass {
public:
    int first;
    vector<int> second;

    // 重载等号，判断两个Myclass类型的变量是否相等
    bool operator == (const Myclass &other) const {
        return first == other.first && second == other.second;
    }

};

// 实现Myclass类的hash函数
namespace std {
    template <>
    struct hash<Myclass> {
        size_t operator () (const Myclass &k) const {
            int h = k.first;

            for (auto x : k.second) {
                h ^= x;
            }

            return h;
        }
    };
}

int main() {
    unordered_map<Myclass, double> S;
    Myclass a = {2, {3, 4}};
    Myclass b = {3, {1, 2, 3, 4,}};

    S[a] = 2.5;
    S[b] = 3.123;

    cout << S[a] << ' ' << S[b] << endl;

    return 0;
}

