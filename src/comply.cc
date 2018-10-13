/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

/******************  DO NOT MODIFY THIS FILE ****************************
 *
 * It is not included in the subission archive ceated by 'make submit' .
 *
 * If you modify it and your code relies on those modifications, your code
 * will not compile in the automated test harness and will be unable to
 * execute any tests.
 *
 * To put it another way, if you modify this file, you will get a big fat
 * ZERO on this lab.
 *
 ************************************************************************/

#include <iostream>

#include "circle.h"
#include "polygon.h"
#include "reuleaux.h"

int main(int argc, char *argv[]) 
{
    Point p1 = Point();
    Point p2 = Point(0.0, 0.0);
    Point p3 = Point(p2);

    Circle circle = Circle(Point(0.0,0.0), 4.0);
    double x = circle.center().x;
    double r = circle.radius();

    RegularConvexPolygon polygon = RegularConvexPolygon({Point(0,2), Point(2,0), Point(-2,0)});
    int vp = polygon.vertices().size();

    Point vertices[3] = {Point(0,2), Point(2,0), Point(-2,0)};
    ReuleauxTriangle reuleaux = ReuleauxTriangle(vertices);
    int vr = reuleaux.vertices().size();

    circle.containedBy(circle);
    circle.containedBy(polygon);
    circle.containedBy(reuleaux);

    polygon.containedBy(circle);
    polygon.containedBy(polygon);
    polygon.containedBy(reuleaux);

    reuleaux.containedBy(circle);
    reuleaux.containedBy(polygon);
    reuleaux.containedBy(reuleaux);
}
