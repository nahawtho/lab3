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

bool Circle::containedBy(RegularConvexPolygon &polygon) { //good?
	int i = 0;
	int sized = polygon.vertices_.size();
	double centerpolyx = 0;
	double centerpolyy = 0;
	for (Point const &point: polygon.vertices_){
		//std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
		centerpolyx += point.x;
		centerpolyy += point.y;	
	} 
	for (Point const &point: polygon.vertices_){
	std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
		if(Geom::distanceBetween(Point(polygon.vertices_[i].x,polygon.vertices_[i].y)
			, this->center()) < this->radius_) return false;
		int next = i + 1;
		//if(Geom::distanceBetween(Point(polygon.vertices_[next].x,polygon.vertices_[next].y)
                 //       , this->center()) < this->radius_) return false;
		if (i < (sized-1)) 
		{
			std::cout << "i:" << i << "next:" << next << std::endl;
			std::cout << polygon.vertices_[i].x;
			Line l(Point(polygon.vertices_[i].x,polygon.vertices_[i].y),
					Point(polygon.vertices_[next].x,polygon.vertices_[next].y));
			i++;
			Line cp2cc(Point((centerpolyx/sized), (centerpolyy/sized)), Point(this->center()));
        		if (l.intersect(cp2cc)) return false;
			if (l.intersect(*this)) return false;
		} //prints xy coordinates
	}
	return true;
	throw "Circle::containedBy(RegularConvexPolygon &polygon) Not implemented";
}

bool Circle::containedBy(ReuleauxTriangle &rt) {
	throw "Not implemented";
}

/*
bool Circle::containedBy(ConvexPolygon &polygon) {
    throw "Not implemented";
}


