// 问题描述
// 　　小明对类似于 hello 这种单词非常感兴趣，这种单词可以正好分为四段，第一段由一个或多个辅音字母组成，第二段由一个或多个元音字母组成，第三段由一个或多个辅音字母组成，第四段由一个或多个元音字母组成。
// 　　给定一个单词，请判断这个单词是否也是这种单词，如果是请输出yes，否则请输出no。
// 　　元音字母包括 a, e, i, o, u，共五个，其他均为辅音字母。
// 输入格式
// 　　输入一行，包含一个单词，单词中只包含小写英文字母。
// 输出格式
// 　　输出答案，或者为yes，或者为no。
// 样例输入
// lanqiao
// 样例输出
// yes
// 样例输入
// world
// no


// #include <bits/stdc++.h> 
// using namespace std;

// bool isVowel(char a) {
//     return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
// }

// int main() {
//     set<char> Vowel;
//     set<char> consonant;
//     string str;
//     int a = 0;
//     int b = 0;
//     int c = 0;
//     int d = 0;
//     int p = 0;

//     for (int i = 'a'; i <= 'z'; ++ i) {
//         if (isVowel(i)) Vowel.insert(i);
//         else consonant.insert(i);
//     }

//     cin >> str;

//     while (consonant.find(str[p]) != consonant.end()) {
//         a = 1;
//         ++ p;
//     }

//     while (Vowel.find(str[p]) != Vowel.end()) {
//         b = 1;
//         ++ p;
//     }

//     while (consonant.find(str[p]) != consonant.end()) {
//         c = 1;
//         ++ p;
//     }

//     while (Vowel.find(str[p]) != Vowel.end()) {
//         d = 1;
//         ++ p;
//     }

//     if(p == str.length() && a==1 && b==1 && c==1 && d==1) cout<<"yes"<<endl;
//  	else cout<<"no"<<endl;

//  	return 0;
// }


#include <bits/stdc++.h>
using namespace std;

bool isVowel(char a) {
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

bool solve(stack<char>& s){

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    if (s.empty()) return false;

    while (!s.empty() && isVowel(s.top())) {
        s.pop();
        a = 1;
    }

    while (!s.empty() && !isVowel(s.top())) {
        s.pop();
        b = 1;
    }
    
    while (!s.empty() && isVowel(s.top())) {
        s.pop();
        c = 1;
    }

    while (!s.empty() && !isVowel(s.top())) {
        s.pop();
        d = 1;
    }

    if (s.empty() && a == 1 && b == 1 && c == 1 && d == 1) return true;
    else return false;

}

int main() {

    bool flag = true;
    string str;
    stack<char> S;

    cin >> str;

    for (int i = 0; i < str.length(); ++ i) {
        S.push(str[i]);
    }

    flag = solve(S);

    if (flag) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}




