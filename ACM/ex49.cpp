//
// Created by 98595 on 2020/3/28.
//https://www.cnblogs.com/llee-123/p/11265812.html set unordered_set区别

#include <unordered_set>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> s; // 可以块数查找

        for (auto i : wordList) s.insert(i);
        // first 表示字符
        // second 表示走过的路长

        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));

        string temp;
        int step; // 表示用暂时存贮走过的步子

        while (!q.empty()) {
            if (q.front().first == endWord) return q.front().second;

            temp = q.front().first;
            step = q.front().second;
            q.pop();

            char ch;
            for (int i = 0; i <= temp.size(); ++ i) {
                ch = temp[i];

                for (int a = 'a'; a < 'z'; ++ a) {
                    if (ch == a) continue;

                    temp[i] = a;
                    if (s.find(temp) != s.end()) { // 这里表示如果找到了可以转换的两个单词，就把该数存放入队列里
                        q.push(make_pair(temp, step + 1));
                        s.erase(temp); // 删掉结点的意思防止找到重复
                    }

                    temp[i] = ch;
                }
            }
        }

        return 0;
    }

    // 双向队列解法
    int dbfs(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (dict.find(beginWord) != dict.end()) return 0;

        //初始化
        unordered_set<string> beginSet, endSet, tmp, visited;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int len = 1; // len表示所走的步数

        //beginSet与endSet进行交换，从两端开始搜索。如果一端比较小就可以交换
        //这是对于双向搜索的一种写法
        while (!beginSet.empty() && !endSet.empty()) {
            if (beginSet.size() > endSet.size()) {
                tmp = beginSet;
                beginSet = endSet;
                endSet = tmp;
            }
            tmp.clear();

            // 循环每个单词
            for (string word : beginSet) {
                for (int i = 0; i < word.size(); ++ i) {
                    char old = word[i];

                    // 循环每一位上的26个字母
                    for (char a = 'a'; a < 'z'; ++ a) {
                        if (old == a) continue;

                        word[i] = a;

                        //endSet存的是endWord，如果找到说明就是找到了一个路径
                        if (endSet.find(word) != endSet.end()) {
                            return len + 1;
                        }

                        if (visited.find(word) == visited.end() && dict.find(word) != dict.end()) {
                            tmp.insert(word);
                            visited.insert(word);
                        }
                    }

                    word[i] = old;
                }
            }

            //把走过的结点删除掉，走有连接的结点
            beginSet = tmp;
            ++ len;
        }

        return 0;
    }
};


int main() {
    return 0;
}


