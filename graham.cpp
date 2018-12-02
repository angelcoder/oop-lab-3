#include "Graham.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include "Point.h"
using namespace std;
Point p0;
int orientationG(Point p1, Point p2, Point p3) {
    int val = (p2.y - p1.y) * (p3.x - p2.x) -
    (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0) return 0;      // 0 - colinear
    return (val > 0)? 1: 2;      // 1 - clockwise
}                                // 2 - counterclockwise
Point nextToTop(stack<Point> &S) {
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

void swap(Point &p1, Point &p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int distSq(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) +
    (p1.y - p2.y)*(p1.y - p2.y);
}

int compare(const void *vp1, const void *vp2) {
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;
    int o = orientationG(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
    return (o == 2)? -1: 1;
}

vector<Point>  convexHullG(Point points[], int n){
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++){
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y;
            min = i;
    }
    swap(points[0], points[min]);
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(Point), compare);
    int m = 1; 
    for (int i=1; i<n; i++){
        while (i < n-1 && orientationG(p0, points[i], points[i+1]) == 0)
            i++;
        points[m] = points[i];
        m++;
    }
    stack<Point> S;
   // S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    // Process remaining n-3 points
    for (int i = 3; i < m; i++){
        while (orientationG(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }
    vector<Point> answer;
    while (!S.empty()){
        Point p = S.top();
        answer.push_back(p);
        S.pop();
    }
    return answer;
}
