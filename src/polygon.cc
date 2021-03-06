// polygon.c
/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

#include <iostream>

#include "polygon.h"
#include "geom.h"

RegularConvexPolygon::RegularConvexPolygon(std::vector<Point> points) {	

	vertices_ = points;
}
std::vector<Point> RegularConvexPolygon::vertices(){
	return vertices_;
}
bool RegularConvexPolygon::containedBy(Circle &circle) {
	int i = 0;
	int sized = this->vertices_.size();
	for (Point const &point: this->vertices_){
		std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
		int next = i + 1;
		if (i < (sized-1))
		{
			std::cout << "i:" << i << "next:" << next << std::endl;
			std::cout << this->vertices_[i].x;
			Line l(Point(this->vertices_[i].x,this->vertices_[i].y),
					Point(this->vertices_[next].x,this->vertices_[next].y));
			i++;
			if (l.intersect(circle)) return false;
		} //prints xy coordinates
	}
	return true;
	throw "Not implemented";
}


bool RegularConvexPolygon::containedBy(RegularConvexPolygon &polygon) {
	int i_inner=0;
	int sized = polygon.vertices_.size();
	int sized_inner = this->vertices_.size();
	double centerpolyx = 0;
	double centerpolyy = 0;
	double centerpolyx2 = 0;
	double centerpolyy2 = 0;
	for (Point const &point: polygon.vertices_){
		std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
		centerpolyx += point.x;
		centerpolyy += point.y;
	}
	for (Point const &point: this->vertices_){
		std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
		centerpolyx2 += point.x;
		centerpolyy2 += point.y;
	}
	int centerxinner = centerpolyx2 / sized_inner;
	int centeryinner = centerpolyy2 / sized_inner;
	int centerxouter = centerpolyx / sized;
	int centeryouter = centerpolyy / sized;

	for (Point const &point: this->vertices_)
	{
	std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
		int next_inner = i_inner+1;
		if (i_inner < (sized_inner - 1)){
			Line l_inner(Point(this->vertices_[i_inner].x,this->vertices_[i_inner].y),
					Point(this->vertices_[next_inner].x,this->vertices_[next_inner].y));
			i_inner++;
			int i = 0;
			for (Point const &point: polygon.vertices_){
				std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
				int next = i + 1;
				if (i < (sized-1))
				{
					std::cout << "i:" << i << "next:" << next << std::endl;
					std::cout << polygon.vertices_[i].x;
					Line l(Point(polygon.vertices_[i].x,polygon.vertices_[i].y),
							Point(polygon.vertices_[next].x,polygon.vertices_[next].y));
					i++;
					Line from_mid(Point(centerxinner, centeryinner), Point(centerxouter, centeryouter));
					if (from_mid.intersect(l)) return false;
					if (l.intersect(l_inner)) return false;
				} //prints xy coordinates
			}
		}
	}
	return true;
	throw "Not implemented";
}

bool RegularConvexPolygon::containedBy(ReuleauxTriangle &rt) {
	throw "Not implemented";
}

/*RegularConvexPolygon::vertice(int vertex)
  {

  return RegularConvexPolygon_[vertex];
  }
 */

/*bool Circle::containedBy(Circle &circle) {
  return Geom::distanceBetween(center(), circle.center()) <= (circle.radius() - radius());
  }

  bool Circle::containedBy(RegularConvexPolygon &polygon) {
  throw "Not implemented";
  }

  bool Circle::containedBy(ReuleauxTriangle &rt) {
  throw "Not implemented";
  }
 */
