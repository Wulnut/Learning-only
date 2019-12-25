#include<iostream>
using namespace std;

#define MAXVEX 1005
typedef char VertexType;
typedef int EdgeType;
bool visited[25] = {false};
typedef struct EdgeNode{
    int adjvex;
    EdgeType weight;
    EdgeNode* next;
}EdgeNode;

typedef struct VertexNode{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct{
    AdjList ajdList;
    int numVertexes;
    int numEdges;
}GraphAdjList;

void CreateALGraph(GraphAdjList &G){
    int i, j, k;
    EdgeNode *e;
    cout << "输入顶点个数和边数\n";
    cin >> G.numVertexes >> G.numEdges;
    for ( i = 0; i < G.numVertexes; ++i){
        cin >> G.ajdList[i].data;
        G.ajdList[i].firstedge = NULL;
    }

    for ( k = 0; k < G.numEdges; ++k){
        cout << "输入边（vi, vj）上的顶点序号：\n";
        cin >> i >> j;

        e = new EdgeNode;
        e->adjvex = j;
        e->next = G.ajdList[i].firstedge;
        G.ajdList[i].firstedge = e;

        e = new EdgeNode;
        e->adjvex = i;
        e->next = G.ajdList[j].firstedge;
        G.ajdList[i].firstedge = e;
    }
}

void DFS(GraphAdjList GL, int i){
    EdgeNode *p;
    visited[i] = true;
    cout << GL.ajdList[i].data;
    p = GL.ajdList[i].firstedge;
    while(p){
        if(!visited[p->adjvex]){
            DFS(GL, p->adjvex);
        }
        p = p->next;
    }
}


int main(){
    GraphAdjList a;
    CreateALGraph(a);
    DFS(a, a.numVertexes);
    return 0;
}