//using namespace std;
#include "point.h"
#include <cmath>
#define min(a,b) (((a)<(b)? a:b))
#define max(a,b) (((a)<(b)? b:a))

// Line class, defined by two endpoints
class Line {
	public:
		Point start, end;
		Line(Point start, Point end)
			: start(start)
			  , end(end)
	{ }
		// Return length of line
		double length() {
			return start.distance(end);
		}
		// Return true if point a exists on this line segment
		bool onLine(Point a) {
			if (a.x <= max(start.x, end.x) && a.x >= min(start.x, end.x) && a.y <= max(start.y, end.y) && a.y >= min(start.y, end.y)) 
			{
				double m = gradient();
				double b = yIntercept();
				return a.y == m * a.x + b;
			}
			return false;
		}
		// Return gradient of line
		double gradient() {
			double dX = start.x - end.x;
			double dY = start.y - end.y;
			return dY/dX;
		}
		double yIntercept() {
			double m = gradient();
			return start.y - m*start.x;
		}
		// Return orientation of line endpoints & point a
		int orientation(Point a) {
			double val = (end.y - start.y) * (a.x - end.x) - (end.x - start.x) * (a.y - end.y);
			if (val == 0) {
				return 0;   // 0 = colinear
			} else if (val > 0) {
				return 1;   // 1 = clockwise
			} else {
				return 2;   // 2 = counter-clockwise
			}
		}
		// Return true if this line intersects line a
		bool intersect(Line a) {
			// Orientations: 0 is colinear, 1 is clockwise, 2 is counter-clockwise
			int o1 = a.orientation(start);
			int o2 = a.orientation(end);
			int o3 = orientation(a.start);
			int o4 = orientation(a.end);

			// General case - each line's points are on opposite sides of the other line
			if (o1 != o2 && o3 != o4) {
				return true;
				// Line a and this line's start are colinear and this line's start lies on line a's segment
			} else if (o1 == 0 && a.onLine(start)) {
				return true;
				// Line a and this line's end are colinear and this line's end lies on line a's segment
			} else if (o2 == 0 && a.onLine(end)) {
				return true;
				// This line and a.start are colinear and a.start lies on this line segment
			} else if (o3 == 0 && onLine(a.start)) {
				return true;
				// This line and a.end are colinear and a.end lies on this line segment
			} else if (o4 == 0 && onLine(a.end)) {
				return true;
			}
			return false; // Doesn't fall in any of the above cases
		}
		// Catch-all intersect function in case intersect is called on a higher shape
		template <typename Type>  //returns 0 no intersect 1 for yes
			bool intersect(Type a) {
				return a.intersect(*this);
			} 
};
