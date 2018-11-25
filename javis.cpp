#include "javis.h"

#include <iostream>
#include <vector>
using namespace std;
int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) -
    (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

void convexHull(Point points[], int n){
    // There must be at least 3 points
    if (n < 3) return;

    // Initialize Result
    vector<Point> hull;

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    
    int p = l, q;
    do
    {
        // Add current point to result
        hull.push_back(points[p]);

        q = (p+1)%n;
        for (int i = 0; i < n; i++){
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        p = q;

    } while (p != l);  // While we don't come to first point
    
    for (int i = 0; i < hull.size(); i++)
        cout << "(" << hull[i].x << ", "
        << hull[i].y << ")\n";
}
