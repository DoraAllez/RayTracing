#ifndef _GEOMETRIC_LOADER_H
#define _GEOMETRIC_LOADER_H

using namespace std;
class GeometricModel;

class OBJLoader
{
	public:
		OBJLoader();
		~OBJLoader();
                bool loadModel(string name,GeometricModel *model);
	private:
		void setupForTextureCoordinates(GeometricModel* model);
		void computeNormals(GeometricModel* model);
		void computeTangents(GeometricModel* model);
};
#endif
