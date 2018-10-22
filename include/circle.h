/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

//contains function prototypes for circle class, and few definitions of helper functions.
#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include "containable.h"
#include "point.h"
#include "line.h"

class Circle : public Containable {
	private:
		Point center_;
		double radius_;

	public:
		// do not modify or remove this constructor
		Circle(const Point &center, double radius);

		// do not modify or remove these accessors
		Point center();
		double radius();

		bool containedBy(Circle &circle);
		bool containedBy(RegularConvexPolygon &polygon);
		bool containedBy(ReuleauxTriangle &rt);

		// Return true if this circle intersects line a
		bool intersect(Line a) {
        // Line equation coefficients: y = mx + b
        double m = a.gradient();
        double b = a.yIntercept();
        // Circle equation coefficients: (x - p)^2 + (y - q)^2 = r^2
        double p = center_.x;
        double q = center_.y;
        double r = radius_;
        // Quadratic equation coefficients: Ax^2 + Bx + C = 0
        double A = pow(m,2) + 1;
        double B = 2*(m*b - m*q - p);
        double C = pow(q,2) - pow(r,2) + pow(p,2) - 2*b*q + pow(b,2);

        // A discriminant < 0 results in imaginary roots, therefore line does not intersect circle
        double discriminant = pow(B,2)-4*A*C;
        if (discriminant < 0) {
            return false;
        }

        // Since discriminant >= 0, find roots
        double x1 = (-B+sqrt(discriminant)) / (2*A);
        double y1 = m*x1 + b;
        double x2 = (-B-sqrt(discriminant)) / (2*A);
        double y2 = m*x2 + b;

        // If either root exists on line, the line intersects the circle
        if (a.onLine(Point(x1,y1))) { 
            return true;
        } else if (a.onLine(Point(x2,y2))) {
            return true;
        }
        // Otherwise, if neither intesect appear on line segment, shapes do not intersect
        return false;
    }
    // Return true if circle a intersects this circle
    bool intersect(Circle a) {
        double distance = a.center_.distance(center_);
        if (distance <= a.radius_ + radius_) {  
            return true;    
        }
        return false;
    }
    // Catch-all intersect function in case intersect is called on a higher shape
    template <typename Type>
    bool intersect(Type a) {
        return a.intersect(*this);
    }
};
#endif
