#include "divideandconqueralgo.h"
#include "javis.h"
#include <iostream>
#include <algorithm>
#include <set>
//визначається точка h , для якої трикутник hlr має найбільшу площу серед всіх трикутників = distance(h, lr=max) because S=0.5*(lr)*h
using namespace std;

int main(){
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
        {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points, n);
    return 0;
}

