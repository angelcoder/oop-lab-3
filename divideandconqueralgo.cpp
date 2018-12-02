#include "DivideAndConquerAlgo.hpp"
#include <vector>

using namespace std;
vector<Point> hull;  //points of convex hull
bool operator<(Point p1, Point p2) {
    if (p1.y == p2.y) return p1.x < p2.x;
    return (p1.y < p2.y);
}
bool operator==(Point p1, Point p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}
int findSide(Point p1, Point p2, Point p){
    int val = (p.y - p1.y) * (p2.x - p1.x) -
    (p2.y - p1.y) * (p.x - p1.x);
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}
int lineDist(Point p1, Point p2, Point p){
    return abs ((p.y - p1.y) * (p2.x - p1.x) -
                (p2.y - p1.y) * (p.x - p1.x));
}

void convexHullRec(Point a[], int n, Point p1, Point p2, int side){
    int ind = -1;
    int max_dist = 0;
    for (int i=0; i<n; i++){
        int temp = lineDist(p1, p2, a[i]);
        if (findSide(p1, p2, a[i]) == side && temp > max_dist){
            ind = i;
            max_dist = temp;
        }
    }
    if (ind == -1){
        hull.push_back(p1);
        hull.push_back(p2);
        sort(hull.begin(), hull.end());
        return;
    }
    convexHullRec(a, n, a[ind], p1, -findSide(a[ind], p1, p2));
    convexHullRec(a, n, a[ind], p2, -findSide(a[ind], p2, p1));
}

vector<Point> printHull(Point a[], int n){
    int min_x = 0, max_x = 0;
    for (int i=1; i<n; i++){
        if (a[i].x < a[min_x].x) min_x = i;
        if (a[i].x > a[max_x].x) max_x = i;
    }
    convexHullRec(a, n, a[min_x], a[max_x], 1);
    convexHullRec(a, n, a[min_x], a[max_x], -1);
    cout << "The points in Convex Hull are:\n";
    sort(hull.begin(), hull.end());
    hull.erase(unique( hull.begin(), hull.end() ), hull.end());
    return hull;
}
