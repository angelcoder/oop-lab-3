#include "divideandconqueralgo.h"
#include "javis.h"
#include <iostream>
#include <algorithm>
#include <set>
//визначається точка h , для якої трикутник hlr має найбільшу площу серед всіх трикутників = distance(h, lr=max) because S=0.5*(lr)*h
using namespace std;

int main(){
    int main(){
        int method;
        cin >> method;
        switch (method) {
            case 4:{
                cout <<"javis method\n";
                Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                    {3, 0}, {0, 0}, {3, 3}};
                int n4 = sizeof(points)/sizeof(points[0]);
                convexHull(points, n4);
                break;
            }
            case 6:{
                cout <<"Divide and counquer method\n";
                Pair a[ ] =  {{0, 3}, {2, 2}, {1, 1}, {2, 1},{3, 0}, {0, 0}, {3, 3}};
                int n6 = sizeof(a)/sizeof(a[0]);
                printHull(a, n6);
                break;
            }
        }
        return 0;
    }
}

