#include <vector>
#include "reuleaux.h"

ReuleauxTriangle::ReuleauxTriangle(const Point vertices[3]) {

	std::vector<Point> vecpts (vertices, vertices + sizeof(*vertices)
							/ sizeof(Point));
	
	//const Point* pts = &vertices_[0];
}
