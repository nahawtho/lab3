/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

#include <iostream>
#include "circle.h"
#include "geom.h"
#undef max
#include "polygon.h" //undef max fixes error here

Circle::Circle(const Point &center, double radius) {
    center_.x = center.x;
    center_.y = center.y;
    radius_ = radius;
}

Point Circle::center() {
    return center_;
}

double Circle::radius() {
    return radius_;
}

/*
 * If distance between centers is less than difference between the radius of containing 
 * circle and the radius of this circle, this circle is not contained
 */
bool Circle::containedBy(Circle &circle) {
    return Geom::distanceBetween(center(), circle.center()) <= (circle.radius() - radius());
}

bool Circle::containedBy(RegularConvexPolygon &polygon) {
    for (Point const &point: polygon.vertices_){
        std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
	std::cout << polygon.vertices_.size() << std::endl;
	std::cout << polygon.vertices_.point.x;
        } //prints xy coordinates
    throw "Circle::containedBy(RegularConvexPolygon &polygon) Not implemented";
}

bool Circle::containedBy(ReuleauxTriangle &rt) {
    throw "Not implemented";
}
