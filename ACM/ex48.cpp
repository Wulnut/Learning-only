#include<iostream>
#include<queue>
using namespace std;
struct node{
    int x,y,cost,power;
    friend bool operator <(const node &u,const node &v) {
        if(v.cost == u.cost)
            return u.power < v.power; //优先走消耗查克拉少的路径，保证自身剩余的查克拉尽可能多
        return u.cost > v.cost;
    }
};

int dir[4][2] = {0,1,1,0,0,-1,-1,0},n,m;
char a[201][201];
bool vis[201][201];

int rec(int stx,int sty,int dex,int dey,int power)
{
    priority_queue<node> q;
    node cur,nxt;
    cur.x = stx, cur.y = sty, cur.cost = 0, cur.power = power;
    q.push(cur);
    while(!q.empty()){
        cur = q.top();
        q.pop();
        if(cur.x == dex && cur.y == dey){
            return cur.cost;
        }
        for(int i = 0; i < 4; ++i){
            int tx = cur.x + dir[i][0];
            int ty = cur.y + dir[i][1];
            if(tx<0||tx>=n||ty<0||ty>=m||vis[tx][ty]) // can not go
                continue;
            if(a[tx][ty]=='#' && cur.power == 0)//have no power
                continue;
            vis[tx][ty] = 1;
            nxt.power = cur.power - ((a[tx][ty]=='#') ? 1 : 0); //if have monster,defeat it!
            nxt.x = tx, nxt.y = ty;
            nxt.cost = cur.cost + 1; //time+1
            q.push(nxt);
        }
    }
    return -1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int stx,sty,dex,dey,power;
    std::cin>>n>>m>>power;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            std::cin>>a[i][j];
            if(a[i][j]=='@')
                stx = i, sty = j;
            if(a[i][j]=='+')
                dex = i, dey = j;
        }
    }
    vis[stx][sty] = 1;
    cout<<rec(stx,sty,dex,dey,power)<<std::endl;
    return 0;
}