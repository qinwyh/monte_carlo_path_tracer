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


// Model 类函数
Model::Model(string obj_file_path, string mtl_file_path) {
	this->obj_file_path = obj_file_path;
	this->mtl_file_path = mtl_file_path;
}

bool Model::load_files() {
	clock_t t = clock();

	load_obj();

	cout << "模型加载耗时：" << float(clock() - t) << "ms。" << endl;
	return true;
}


bool Model::load_obj() {
	ifstream file(obj_file_path);
	if (!file.is_open()) return false;

	// 必要参数列表
	string type;
	std::vector<Vertex> vertices;
	std::vector<Vector> normals;

	while (file >> type) {
		if (type == "v") {
			Vertex vt;
			file >> vt.x >> vt.y >> vt.z;
			vertices.push_back(vt);
		} else if (type == "vn") {
			Vector vn;
			file >> vn.x >> vn.y >> vn.z;
			normals.push_back(vn);
		} else if (type == "usemtl") {
			string material_name;
			file >> material_name;

			// 确认是否为有效材质
			bool is_found = false;
			for (std::vector<Material>::iterator mtl_iter = materials.begin(), 
				end = materials.end(); mtl_iter != end; ++mtl_iter) {
				Material& cur_mtl = *mtl_iter;

				if (cur_mtl.name == material_name) {
					is_found = true;
					break;
				}
			}

			if (is_found != true)
				cout << "Material not found:" << material_name << endl;
		}
	}
	file.close();
	return true;
}