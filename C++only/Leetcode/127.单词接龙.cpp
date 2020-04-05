/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:

    // int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //    unordered_set<string> s;

    //    for (auto i : wordList) s.insert(i);
    //    queue<pair<string, int>> q;

    //    // first 表示单词
    //    // second 表示走过的步数

    //    q.push(make_pair(beginWord, 1));

    //    string tmp;
    //    int step;

    //    while (!q.empty()) {

    //        if (q.front().first == endWord) {
    //            return q.front().second;
    //        }

    //        tmp = q.front().first;
    //        step = q.front().second;
    //        q.pop();

    //        char ch;
    //        for (int i = 0; i < tmp.length(); ++ i) {
    //            ch = tmp[i];

    //            for (char c = 'a'; c <= 'z'; ++ c) {
    //                if (ch == c) continue;

    //                tmp[i] = c;

    //                if (s.find(tmp) != s.end()) {
    //                    q.push(make_pair(tmp, step + 1));
    //                    s.erase(tmp);
    //                }

    //                tmp[i] = ch;
    //            }
    //        }
    //    }

    //    return 0;

    // }
     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end() ) return 0;
        // 初始化起始和终点
        unordered_set<string> beginSet, endSet, tmp, visited;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int len = 1;

        while (!beginSet.empty() && !endSet.empty()){
            if (beginSet.size() > endSet.size()){
                tmp = beginSet;
                beginSet = endSet;
                endSet = tmp;
            }
            tmp.clear();
            
            for ( string word : beginSet){
                for (int i = 0; i < word.size(); i++){
                    char old = word[i];
                    for ( char c = 'a'; c <= 'z'; c++){
                        if ( old == c) continue;
                        word[i] = c;
                        if (endSet.find(word) != endSet.end()){
                            return len+1;
                        }
                        if (visited.find(word) == visited.end() && dict.find(word) != dict.end()){
                            tmp.insert(word);
                            visited.insert(word);
                        }
                    }
                    word[i] = old;
                }
            }

            beginSet = tmp;
            len++;
            
        }
        return 0;
     }

};
// @lc code=end

