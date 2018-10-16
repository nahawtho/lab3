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
//	vertices = points;	
	
}
bool RegularConvexPolygon::containedBy(Circle &circle) {
    throw "Not implemented";
}


bool RegularConvexPolygon::containedBy(RegularConvexPolygon &polygon) {
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
