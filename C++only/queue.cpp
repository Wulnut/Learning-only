#include<iostream>
using namespace std;


#define OK 0
#define ERROR 1
#define MAXSIZE 1005
typedef int QElementType;

typedef struct {
    QElementType data[MAXSIZE];
    int rear;
    int front;
}SsqQueue;

int InitQueue(SsqQueue &Q){
    Q.front = Q.rear = 0;
    return 0;
}

int QueueLength(const SsqQueue &Q){
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

int Enqueue(SsqQueue &Q, QElementType e){
    if((Q.rear+1) % MAXSIZE == Q.front)//是否为满队
    return ERROR;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;

    return OK;
}

int DeQueue(SsqQueue &Q, QElementType &e){
    if (Q.front == Q.rear)//是否为空队
    return ERROR;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return OK;
}