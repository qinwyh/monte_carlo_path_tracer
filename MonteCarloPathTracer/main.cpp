#include <iostream>
#include "Model.h"

using namespace std;

int main() {
	Vertex* vertices = new Vertex[3];
	vertices[0] = Vertex(3.0f, 2.1f, -1.6f);
	vertices[1] = Vertex(7.0f, 3.1f, -5.6f);
	vertices[2] = Vertex(2.0f, 4.1f, -7.6f);

	Vector normal = Vector(5.0f, 4.1f, -7.6f);
	Face face = Face(vertices, normal, 3);

	cout << face;

	return 0;
}