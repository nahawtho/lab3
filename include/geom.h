/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include "point.h"

class Geom {
    public:
        static double distanceBetween(const Point &a, const Point &b);
};

#endif
