/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */
// https://opencast-player-1.lt.ucsc.edu:8443/engage/theodul/ui/core.html?id=e37d6e88-1809-4058-9c2d-fed46395e6dd
// https://codereview.stackexchange.com/questions/95935/c-2d-shape-intersections-template-reduction
#include <cmath>
#include <iostream>
using namespace std;
#include <vector>
#include "circle.h"
#include "polygon.h"
#include "point.h"
#define min(a,b) (((a)<(b)? a:b))
#define max(a,b) (((a)<(b)? b:a))
//#include "line.h"
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
static void polygonPolygon(RegularConvexPolygon inner, RegularConvexPolygon outer, bool expected, const char *msg)
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
	std::cout << "circlePolygon" << std::endl;
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

    std::vector<Point> points = std::vector<Point>{Point(-8.0,-8.0), Point(0.0,8.0), Point(8.0, -8.0)};
    RegularConvexPolygon poly = RegularConvexPolygon(points);

    try { 
    circlePolygon(Circle(Point(0.0,0.0), 4.0),
	 RegularConvexPolygon(points), false, "Circle-InsideTangent-Polygon");
   } catch (const char *msg) {std::cout << msg << std::endl;} 

    try {
    circlePolygon(Circle(Point(0.0,0.0), 2.0),
         RegularConvexPolygon(points), true, "Circle-InsideTangent-Polygon");
   } catch (const char *msg) {std::cout << msg << std::endl;}

    try {
    circlePolygon(Circle(Point(0.0,0.0), 4.0),
         RegularConvexPolygon(std::vector<Point>{Point(2.0,-8.0), Point(10.0,8.0), Point(18.0, -8.0)}), false, "Circle-InsideTangent-Polygon");
   } catch (const char *msg) {std::cout << msg << std::endl;}

    try {
    polygonPolygon(RegularConvexPolygon(points),
         RegularConvexPolygon(std::vector<Point>{Point(2.0,-8.0), Point(10.0,8.0), Point(18.0, -8.0)}), false, "Circle-InsideTangent-Polygon");
   } catch (const char *msg) {std::cout << msg << std::endl;}
   /*for (Point const &point: poly.vertices_){ 
	cout << "(" << point.x << ", " << point.y << ")" << std::endl;
	} //prints xy coordinates
	*/
  
	Line l1(Point(0,2),Point(2,-2)); 
	std::cout << l1.length() << std::endl; //length test
	//test line intersect
	//std::cout << l1.intersect(Line({0,-2},{2,-3})) << std::endl;
	Circle c1(Point(1,0),1);
	std::cout << l1.intersect(c1) << std::endl; //expect true
	return 0;
}
