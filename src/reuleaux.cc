#include <vector>
#include "reuleaux.h"
#include "point.h"
#include "containable.h"

ReuleauxTriangle::ReuleauxTriangle(const Point vertices[3]) {

	std::vector<Point> vecpts (vertices, vertices + sizeof(*vertices)
							/ sizeof(Point));
	
}

bool ReuleauxTriangle::containedBy(Circle &circle){
	throw "not implemented";
}

bool ReuleauxTriangle::containedBy(RegularConvexPolygon &polygon){
	throw "not implemented";
}

bool ReuleauxTriangle::containedBy(ReuleauxTriangle &rt){
	throw "not implemented";
}
