// https://nanti.jisuanke.com/t/T1184

#include <bits/stdc++.h>
using namespace std;

int m, x;

bool solve(int y) {
    if (y > x) return false;

    if (y == x) return true;

    if (solve(2 * y + 1) || solve(3 * y + 1)) return true;

    return false;
}


int main() {
    bool flag = true;

    cin >> m;

    getchar();

    cin >> x;

    flag = solve(m);

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}


// bfs解法
// #include<iostream>
// #include<queue>
// using namespace std;
// typedef long long ll;

// int k,x;
// bool flag=false;

// int fun1(int x){
// 	return 2*x+1;
// }

// int fun2(int x){
// 	return 3*x+1; 
// }

// void bfs(int t){
// 	if(t==x) {
//    flag = true;
//    return;
//    }
// 	queue<int> q;
// 	q.push(t);
// 	while(!q.empty()){
// 		ll newK=q.front();
// 		q.pop();
// 		if(fun1(newK) < x) q.push(fun1(newK));
// 		if(fun2(newK) < x) q.push(fun2(newK));
// 		if(fun1(newK) == x){
// 			flag=true;
// 			break;
// 		}
// 		if(fun2(newK)==x){
// 			flag=true;
// 			break;
// 		}
// 	}
// 	return ;
// }

// int main(){
// 	scanf("%d,%d",&k,&x);
// 	if(k==x){
// 		cout<<"YES"<<endl;
// 		return 0;
// 	}
// 	bfs(k);
// 	if(flag){
// 		cout<<"YES"<<endl;
// 	}else{
// 		cout<<"NO"<<endl;
// 	}
// 	return 0;
// }
