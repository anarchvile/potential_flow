#ifndef FIELD_H
#define FIELD_H

#include <glm.hpp>
#include <vector>

struct Flow
{
	std::vector<float> velocity;
	std::vector<float> potential;
	std::vector<float> stream;
};

class Field
{
public:
	bool updateField, updateWindow, uniformBool = false, sourceBool = true, vortexBool = false, doubletBool = false, showOrigin = true, pointSelected = false, change, del = false, sinkBool;
	int showBackground = 0, pixelSize = 1, ID;
	std::vector<float> points, pointsColors, origin, originColors, stream, streamColors, potential, potentialColors, background, flowType, __test;
	float minStream = 10000.0f, maxStream = -10000.0f, minPotential = 10000.0f, maxPotential = -10000.0f, minVel = 10000.0f, maxVel = -10000.0f;

	void InitializeField();
	void ReinitializeField(std::vector<float> &points);
	void UpdateField(std::vector<float> &points);
	void Clear();
	glm::vec4 testValue;
//private:
	Flow Uniform(std::vector<float> &points, float xDisplacement, float yDisplacement, float speed, float flowAngle);
	Flow Source(std::vector<float> &points, float xDisplacement, float yDisplacement, float flowRate);
	Flow Vortex(std::vector<float> &points, float xDisplacement, float yDisplacement, float circulation);
	Flow Doublet(std::vector<float> &points, float xDisplacement, float yDisplacement, float strength);
	void InitializeNewFlow(Flow &flow, std::vector<float> &points);
	void UpdateSelectedFlow(int ID, Flow &flow, std::vector<float> &points, bool del);
};

extern Flow uniform, source, vortex, doublet, null;
extern Field field;

#endif // !FIELD_H