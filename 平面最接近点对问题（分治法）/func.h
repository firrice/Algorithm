//函数头文件
//=======================================
#ifndef FUNC_H
#define FUNC_H

#include "dataset.h"

double closest_distance(point s[], int low, int high, point rec[]);
double Distance(point a, point b);
bool comp_x(point a, point b);
bool comp_y(point a, point b);

#endif