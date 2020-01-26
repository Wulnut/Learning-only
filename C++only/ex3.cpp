#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 100
#define IN 65535
#define MAX 100

typedef char VertexType; //顶点类型应由用户定义
typedef int EdgeType; //边上的权值类型应由用户定义
bool visited[MAX];

typedef struct MGraph{
    VertexType vexs[MAXVEX];//顶点列表
    EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵
    int numVertexes, numEdges;
}MGraph;

void CreateMGraph(MGraph& G){
    int i, j, k, w;

    cout << "Enter numVertexes and numEdges:\n";

    cin >> G.numVertexes>>G.numEdges;

    cout << "Enter vertex name:" << endl;
    for ( i = 0; i < G.numVertexes; ++i){
        cin >> G.vexs[i];
        getchar();
    }

    for ( i = 0; i < G.numVertexes; ++i){
        for ( j = 0; j < G.numVertexes; ++j){
            G.arc[i][i] = IN;
        }
    }

    for ( k = 0; k < G.numEdges; ++k){
                cout << "Enter edge (vi, vj) sup i,sub j and value w;" << endl;

               // getchar();
                cin >> i >> j >> w;

                G.arc[i][j] = w;
                G.arc[j][i] = G.arc[i][j];
    }
}

void DFS(MGraph G, int i){
    int j;

    visited[i] = true;

    cout << G.vexs[i] <<endl;

    for( j = 0; j < G.numVertexes; ++j){
        if ( G.arc[i][j] == 1 && !visited[j]){
            DFS(G, j);
        }
    }
}

void DFSTraverse(MGraph G){
    int i;

    for ( i = 0; i < G.numVertexes; ++i){
        visited[i] =false;
    }

    for ( i = 0; G.numVertexes; ++i){
        if ( !visited[i])
        DFS(G, i);
    }
}


int main(){
    MGraph g;

    CreateMGraph(g);
    DFSTraverse(g);


    return 0;
}