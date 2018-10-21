/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

#ifndef _REULEAUX_H_
#define _REULEAUX_H_

#include <vector>

#include "containable.h"
#include "point.h"

class ReuleauxTriangle : public Containable {
    public:
	const Point pts[3];
	std::vector<Point> vecpts;

        // do not change this constructor
        ReuleauxTriangle(const Point vertices[3]);
	
        // do not modify or remove this accessor
        std::vector<Point> vertices();

	bool containedBy(Circle &circle);
        bool containedBy(RegularConvexPolygon &polygon);
        bool containedBy(ReuleauxTriangle &rt);
};

#endif
