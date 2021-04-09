#ifndef __MODEL_H
#define __MODEL_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "Vector.h"

// ��Χ��
class BoundingBox {
	public:
		Vertex min_vertex;
		Vertex max_vertex;

		BoundingBox() {};
		BoundingBox(Vertex* vertices);
};


// ��Ƭ����
class Material {
	public:
		string name;

};


// ģ����Ƭ
class Face {
	public:
		Vertex* vertices;
		BoundingBox bounding_box;
		Vector normal;
		int material_id;
		
		Face() {};
		Face(Vertex* vertices, Vector& normal, int material_id);

		friend inline ostream& operator << (ostream& out, const Face& face) {
			out << "Vertices:" << endl;
			out << face.vertices[0];
			out << face.vertices[1];
			out << face.vertices[2];
			out << "Normal Vector:" << endl;
			out << face.normal;
			out << "Bounding Box:" << endl;
			out << face.bounding_box.min_vertex;
			out << face.bounding_box.max_vertex;
			out << "Material Index:" << endl;
			out << face.material_id << endl;
			
			return out;
		}
};


// ģ��
class Model {

};

#endif