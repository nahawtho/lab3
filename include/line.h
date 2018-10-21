//using namespace std;
#include "point.h"
#include <cmath>
#define min(a,b) (((a)<(b)? a:b))
#define max(a,b) (((a)<(b)? b:a))

// Line class, defined by two endpoints
class Line {
	public:
		Point strt, end;
		Line(Point strt, Point end)
			: strt(strt)
			  , end(end)
	{ }
		// Return length of line
		double length() {
			return strt.distance(end);
		}
		// Return true if point a exists on this line segment
		bool onLine(Point a) {
			if (a.x <= max(strt.x, end.x) && a.x >= min(strt.x, end.x) && a.y <= max(strt.y, end.y) && a.y >= min(strt.y, end.y)) 
			{
				double m = gradient();
				double b = yIntercept();
				return a.y == m * a.x + b;
			}
			return false;
		}
		// Return gradient of line
		double gradient() {
			double dX = strt.x - end.x;
			double dY = strt.y - end.y;
			return dY/dX;
		}
		double yIntercept() {
			double m = gradient();
			return strt.y - m*strt.x;
		}
		// Return position of line endpoints & point a
		int position(Point a) {
			double val = (end.y - strt.y) * (a.x - end.x) - (end.x - strt.x) * (a.y - end.y);
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
			int o1 = a.position(strt);
			int o2 = a.position(end);
			int o3 = position(a.strt);
			int o4 = position(a.end);

			// General case - each line's points are on opposite sides of the other line
			if (o1 != o2 && o3 != o4) {
				return true;
				// Line a and this line's strt are colinear and this line's strt lies on line a's segment
			} else if (o1 == 0 && a.onLine(strt)) {
				return true;
				// Line a and this line's end are colinear and this line's end lies on line a's segment
			} else if (o2 == 0 && a.onLine(end)) {
				return true;
				// This line and a.strt are colinear and a.strt lies on this line segment
			} else if (o3 == 0 && onLine(a.strt)) {
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
#undef min
#undef max
