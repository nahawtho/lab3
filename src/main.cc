/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */
// https://opencast-player-1.lt.ucsc.edu:8443/engage/theodul/ui/core.html?id=e37d6e88-1809-4058-9c2d-fed46395e6dd
#include <iostream>
using namespace std;
#include <vector>
#include "circle.h"
#include "polygon.h"
#include "point.h"
static void circleCircle(Circle inner, Circle outer, bool expected, const char *msg)
{
    
    if (inner.containedBy(outer) == expected)
        std::cout << "PASS\n";
    else
        std::cout << "FAIL\n";
    std::cout << " " << msg << std::endl;


}
static void circlePolygon(Circle inner, RegularConvexPolygon outer, bool expected, const char *msg)
{
    
    if (inner.containedBy(outer) == expected)
        std::cout << "PASS\n";
    else
        std::cout << "FAIL\n";
    std::cout << " " << msg << std::endl;


}
/*static void circlePolygon(RegularConvexPolygon outer)
//, bool expected, const char *msg)
{
	cout << "circlePolygon" << std::endl;
}
*/

int main(int argc, char *argv[]) 
{
    circleCircle(Circle(Point(0.0,0.0), 4.0), 
	Circle(Point(0.0,0.0), 8.0), true, "Circle-In-Circle: ");
    circleCircle(Circle(Point(19.0,0.0), 4.0),
	 Circle(Point(0.0,0.0), 8.0), false, "Circle-Outside-Circle: "); //expecting circleCircle return false
    circleCircle(Circle(Point(0.0, 0.0), 4.0),
	Circle(Point(0.0, 4.0), 4.0), false, "Circle-OutsideTangent-Circle: ");
    circleCircle(Circle(Point(0.0, 0.0), 4.0),
	Circle(Point(0.0, 4.0), 8.0), true, "Circle-InsideTangent-Circle: ");

   // points = std::vector<Point>{Point(-8.0,-8.0), Point(0.0,8.0), Point(8.0, -8.0)};
//    RegularConvexPolygon(points);
    RegularConvexPolygon(std::vector<Point>{Point(-8.0,-8.0), Point(0.0,8.0), Point(8.0, -8.0)});

    

/*   for (Point const &point: points){
	cout << "(" << point.x << ", " << point.y << ")" << std::endl;
	} //prints xy coordinates
*/

	return 0;
}
