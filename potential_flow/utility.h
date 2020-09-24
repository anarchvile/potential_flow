#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
//#include <glut.h>

struct UtilParams
{
	bool clear = false;
	std::vector<float> keyPoints, keyColors;
	int windowWidth = 500, windowHeight = 500;
};

class Utility
{
public:
	void InitializeKey();
	void UpdateKey();
	void SelectFlow();
	void AddFlow();
	void MoveFlow();
	void DeleteFlow();
	void SetGradient(std::vector<float> &colors, std::vector<float> &values, float &minimum, float &step);
};

extern UtilParams utilParams;
extern Utility utility;

#endif