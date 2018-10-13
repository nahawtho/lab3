/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "containable.h"
#include "point.h"

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
};

#endif
