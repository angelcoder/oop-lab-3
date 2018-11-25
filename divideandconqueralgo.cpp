#include "divideandconqueralgo.h"

#include <set>
using namespace std;

set<Pair> hull;  //points of convex hull

int findSide(Pair p1, Pair p2, Pair p){
    int val = (p.second - p1.second) * (p2.first - p1.first) -
    (p2.second - p1.second) * (p.first - p1.first);

    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

int lineDist(Pair p1, Pair p2, Pair p){
    return abs ((p.second - p1.second) * (p2.first - p1.first) -
                (p2.second - p1.second) * (p.first - p1.first));
}

void quickHull(Pair a[], int n, Pair p1, Pair p2, int side){
    int ind = -1;
    int max_dist = 0;

    // finding the point with maximum distance
    // from L and also on the specified side of L.
    for (int i=0; i<n; i++){
        int temp = lineDist(p1, p2, a[i]);
        if (findSide(p1, p2, a[i]) == side && temp > max_dist){
            ind = i;
            max_dist = temp;
        }
    }

    if (ind == -1){
        hull.insert(p1);
        hull.insert(p2);
        return;
    }

    // Recur for the two parts divided by a[ind]
    quickHull(a, n, a[ind], p1, -findSide(a[ind], p1, p2));
    quickHull(a, n, a[ind], p2, -findSide(a[ind], p2, p1));
}

void printHull(Pair a[], int n){
    // a[i].second -> y-coordinate of the ith point
    if (n < 3) {
        cout << "Convex hull not possible\n";
        return;
    }
    
    int min_x = 0, max_x = 0;
    for (int i=1; i<n; i++){
        if (a[i].first < a[min_x].first) min_x = i;
        if (a[i].first > a[max_x].first) max_x = i;
    }
    quickHull(a, n, a[min_x], a[max_x], 1);
    quickHull(a, n, a[min_x], a[max_x], -1);

    cout << "The points in Convex Hull are:\n";
    while (!hull.empty()){
        cout << "(" <<( *hull.begin()).first << ", "
        << (*hull.begin()).second << ") ";
        hull.erase(hull.begin());
    }
}
