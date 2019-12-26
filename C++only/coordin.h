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