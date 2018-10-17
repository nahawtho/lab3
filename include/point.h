/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

#ifndef _POINT_H_
#define _POINT_H_
#include <cmath>

class Point {
    public:
        // do not remove or modify these attributes
        double x;
        double y;

        // do not remove or modify or remove these constructors
        Point() { x = 0.0, y = 0.0; }
        Point(double dx, double dy) { x = dx; y = dy; }
        Point(const Point &p) { x = p.x; y = p.y; }

// Calculate distance between points
        double distance(Point a) {
            double dX = x - a.x;
            double dY = y - a.y;
            return sqrt(pow(dX,2) + pow(dY,2));
        }
};

#endif
