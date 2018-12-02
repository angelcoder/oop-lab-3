#include "Jarvis.hpp"
#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;
int orientationJ(Point p1, Point p2, Point p3) {
    int val = (p2.y - p1.y) * (p3.x - p2.x) -
    (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0) return 0;      // 0 - colinear
    return (val > 0)? 1: 2;      // 1 - clockwise
}                                // 2 - counterclockwise

vector<Point> convexHullJ(Point points[], int n) {
    vector<Point> hull;
    int leftPoint = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[leftPoint].x)
            leftPoint = i;

    int newLeft = leftPoint, current;
    do {
        hull.push_back(points[newLeft]);
        current = (newLeft+1)%n;
        for (int i = 0; i < n; i++){
            if (orientationJ(points[newLeft], points[i], points[current]) == 1)
                current = i;
        }
        newLeft = current;
    } while (newLeft != leftPoint);
    return hull;
} 
