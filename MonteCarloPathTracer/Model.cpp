#include "Model.h""

using namespace std;


// BoundingBox 类函数
BoundingBox::BoundingBox(Vertex* vertices) {
	Vertex vertex_0 = vertices[0];
	Vertex vertex_1 = vertices[1];
	Vertex vertex_2 = vertices[2];

	float min_x = min(min(vertex_0.x, vertex_1.x), vertex_2.x);
	float min_y = min(min(vertex_0.y, vertex_1.y), vertex_2.y);
	float min_z = min(min(vertex_0.z, vertex_1.z), vertex_2.z);
	float max_x = max(max(vertex_0.x, vertex_1.x), vertex_2.x);
	float max_y = max(max(vertex_0.y, vertex_1.y), vertex_2.y);
	float max_z = max(max(vertex_0.z, vertex_1.z), vertex_2.z);

	min_vertex = Vertex(min_x, min_y, min_z);
	max_vertex = Vertex(max_x, max_y, max_z);
}


// Face 类函数
Face::Face(Vertex* vertices, Vector& normal, int material_id) {
	this->vertices = vertices;
	this->normal = normal;
	this->material_id = material_id;

	bounding_box = BoundingBox(vertices);
}