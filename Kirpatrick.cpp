//
//  Kirpatrick.cpp
//  lab3
//
//  Created by Anhelina Lohvina on 29.11.2018.
//  Copyright © 2018 Anhelina Lohvina. All rights reserved.
//

#include "Kirpatrick.hpp"
#include <iostream>
#include <vector>
using namespace std;
bool operator<(Point p1, Point p2) {
    
    return p1.y < p2.y;
}

bool operator>(Point p1, Point p2) {
    return p1.y >= p2.y;
}
bool operator==(Point p1, Point p2) {
    return p1.y == p2.y;
}
bool operator!=(Point p1, Point p2) {
    return (p1.x != p2.x && p1.y != p2.y);
}
int orientationK(Point p1, Point p2, Point p3) {
    int val = (p2.y - p1.y) * (p3.x - p2.x) -
    (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0) return 0;      // 0 - colinear
    return (val > 0)? 1: 2;      // 1 - clockwise
}                                // 2 - counterclockwise
vector<Point> convexHullK (Point points[], int n){
    vector<Point> hull;
    for (int i=0; i<n; i++)
        hull.push_back(points[i]);
    sort(hull.begin(), hull.end());
    hull.erase(unique(hull.begin(), hull.end()), hull.end());
    unsigned long mY = hull.size();
    vector<Point> Al;
    vector<Point> Ar;
    for (int i = 0; i < mY; i++){
        Point leftPoint= hull[i];
        Point rightPoint = hull[i];
        for (int j = 0; j < n; j++){
            if (hull[i].y == points[j].y && hull[i].x != points[j].x) {
                //cout << i << ": for" << "(" << hull[i].x << ", " << hull[i].y << ") ";
                //cout << "Same y point" << "(" << points[j].x << ", " << points[j].y << ")\n";
                if (points[j].x < leftPoint.x) {
                    leftPoint = points[j];
                }
                if (points[j].x > rightPoint.x){
                    rightPoint = points[j];
                }}}
        Al.push_back(leftPoint); //"left" points
        Ar.push_back(rightPoint); //"right" points
        //sort(Ar.begin(), Ar.end(), greater<Point>());
    }
    vector<Point> result;
    int newleft = 0; int next = 1;
    int current;
    result.push_back(Al[newleft]);
    for (int i = 0; i < Al.size();i++){
        current = i + 2;
        result.push_back(hull[next]);
        if (orientationK(hull[newleft], hull[current], hull[next]) == 1){
            result.pop_back();
            next= current;
        }
        else {
            newleft = next;
            next = current;
        }
    }
    int resultSize1 = result.size();
    vector<Point> resultR;
    int newleftR = 0; int nextR = 1;
    int currentR;
    if(Al[0]!=Ar[Ar.size()-1]){
    resultR.push_back(Ar[newleftR]);
    }
    for (int i = 0; i < Ar.size() && !(result[resultSize1-1] == Ar[i]); i++){
        currentR = i + 2;
        resultR.push_back(hull[nextR]);
        if (orientationK(hull[newleftR], hull[currentR], hull[nextR]) == 2){
            resultR.pop_back();
            nextR= currentR;
        }
        else {
            newleftR = nextR; nextR = currentR;
        }
    }
    if (result[resultSize1-1] == resultR[resultR.size()-1])
    resultR.pop_back();
    sort(resultR.begin(), resultR.end(), greater<Point>());

    vector<Point> answer;
    for (int i = 0; i < result.size(); i++)
        answer.push_back(result[i]);
    for (int i = 0; i < resultR.size(); i++)
        answer.push_back(resultR[i]);
    return answer;
    /*cout<<"Al\n";
    for (int i = 0; i < Al.size(); i++)
        cout << "(" << Al[i].x << ", " << Al[i].y << ")\n";
    cout << "==========="<<endl;
    cout<<"Ar\n";
    for (int i = 0; i < Ar.size(); i++)
        cout << "(" << Ar[i].x << ", " << Ar[i].y << ")\n";
    cout << "==========="<<endl;

    
    for (int i = 0; i < mY; i++)
        cout << "(" << hull[i].x << ", " << hull[i].y << ")\n";
    cout << "==========="<<endl;
    for (int i = 0; i < n; i++)
        cout << "(" << points[i].x << ", " << points[i].y << ")\n";
     */
}
