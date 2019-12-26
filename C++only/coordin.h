#ifndef COORDIN_H_
#define COORDIN_H_


typedef struct {
    double distance;
    double angle;
}polar;

typedef struct {
    double x;
    double y;
}rect;

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif
//写结构体 类 函数的声明