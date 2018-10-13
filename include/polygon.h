/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

#ifndef _POLYGON_H_
#define _POLYGON_H_

#include <vector>

#include "containable.h"
#include "point.h"
#include "circle.h"

class RegularConvexPolygon : public Containable {
    public:
        // do not modify or remove this constructor
        RegularConvexPolygon(std::vector<Point> vertices);

	// do not modify or remove this accessor
        std::vector<Point> vertices();
};

#endif
