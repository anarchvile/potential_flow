#include "pch.h"
#include "field.h"
#include "utility.h"
#include <glut.h>
#include <iostream>

Field field;
Flow uniform, source, vortex, doublet, null;
std::vector<float> __velocity, __tempVelocity, __velocityContainer, __velocityMagnitude, __tempStream, __streamContainer, __tempPotential, __potentialContainer;

void Field::Clear()
{
	updateField = true;
	utilParams.clear = false;
	points.clear();
	pointsColors.clear();

	streamColors.clear();
	potentialColors.clear();

	origin.clear();
	originColors.clear();

	background.clear();

	__velocity.clear();
	__velocityContainer.clear();
	__velocityMagnitude.clear();
	__streamContainer.clear();
	__potentialContainer.clear();

	uniform.velocity.clear();
	uniform.stream.clear();
	uniform.potential.clear();

	source.velocity.clear();
	source.stream.clear();
	source.potential.clear();

	vortex.velocity.clear();
	vortex.stream.clear();
	vortex.potential.clear();

	doublet.velocity.clear();
	doublet.stream.clear();
	doublet.potential.clear();

	null.velocity.clear();
	null.stream.clear();
	null.potential.clear();

	__tempVelocity.clear();
	__tempStream.clear();
	__tempPotential.clear();

	//flowType.clear();
}

void Field::InitializeField()
{
	this->Clear();
	//velocity lines
	for (float y = 0; y <= glutGet(GLUT_WINDOW_HEIGHT); y += 20)
	{
		for (float x = 0; x <= glutGet(GLUT_WINDOW_WIDTH); x += 20)
		{
			points.push_back(x);
			points.push_back(y);
			points.push_back(x + 10);
			points.push_back(y);
		}
	}
	
	//velocity lines and associated colors
	for (int i = 0; i < (int)(0.5f * points.size()); ++i)
	{
		pointsColors.push_back(1);
		pointsColors.push_back(1);
		pointsColors.push_back(1);

		__velocity.push_back(0);
		__velocityMagnitude.push_back(0);

		uniform.velocity.push_back(0);
		source.velocity.push_back(0);
		vortex.velocity.push_back(0);
		doublet.velocity.push_back(0);
		null.velocity.push_back(0);
	}

	for (auto i : points)
		__velocityContainer.push_back(i);

	for (int j = 0; j < glutGet(GLUT_WINDOW_HEIGHT); j += pixelSize)
	{
		for (int i = 0; i < glutGet(GLUT_WINDOW_WIDTH); i += pixelSize)
		{
			//background colors
			background.push_back(i);
			background.push_back(j);

			//streamlines
			uniform.stream.push_back(0);
			source.stream.push_back(0);
			vortex.stream.push_back(0);
			doublet.stream.push_back(0);
			null.stream.push_back(0);

			__tempStream.push_back(0);

			streamColors.push_back(0);
			streamColors.push_back(0);
			streamColors.push_back(0);

			//potential lines
			uniform.potential.push_back(0);
			source.potential.push_back(0);
			vortex.potential.push_back(0);
			doublet.potential.push_back(0);
			null.potential.push_back(0);

			__tempPotential.push_back(0);

			potentialColors.push_back(0);
			potentialColors.push_back(0);
			potentialColors.push_back(0);
		}
	}

	updateField = false;
}

void Field::ReinitializeField(std::vector<float> &points)
{
	for (int i = 0; i < (int)(0.25f * flowType.size()); ++i)
	{
		origin.push_back(flowType[4 * i + 1]);
		origin.push_back(flowType[4 * i + 2]);

		if (flowType[4 * i] == 1)
		{
			originColors.push_back(1);
			originColors.push_back(0);
			originColors.push_back(0);

			source = Source(points, flowType[4 * i + 1], flowType[4 * i + 2], flowType[4 * i + 3]);
			InitializeNewFlow(source, points);
		}

		else if (flowType[4 * i] == 2)
		{
			originColors.push_back(0);
			originColors.push_back(1);
			originColors.push_back(0);

			vortex = Vortex(points, flowType[4 * i + 1], flowType[4 * i + 2], flowType[4 * i + 3]);
			InitializeNewFlow(vortex, points);
		}

		else if (field.flowType[4 * i] == 3)
		{
			originColors.push_back(0);
			originColors.push_back(0);
			originColors.push_back(1);

			doublet = Doublet(points, flowType[4 * i + 1], flowType[4 * i + 2], flowType[4 * i + 3]);;
			InitializeNewFlow(doublet, points);
		}
	}
}

void Field::UpdateField(std::vector<float> &points)
{
	utility.SelectFlow();
	utility.MoveFlow();
	utility.AddFlow();
	utility.DeleteFlow();
}

Flow Field::Uniform(std::vector<float> &points, float xDis, float yDis, float vel, float alpha)
{
	float x, y;
	for (int i = 0; i < (int)(0.25f * points.size()); ++i)
	{
		x = __velocityContainer[4 * i + 2] - xDis; y = __velocityContainer[4 * i + 3] - yDis;
		uniform.velocity[2 * i] = vel * cos(alpha);
		uniform.velocity[2 * i + 1] = vel * sin(alpha);
	}

	int __count = -1;
	for (int j = 0; j < glutGet(GLUT_WINDOW_HEIGHT); j += pixelSize)
	{
		for (int i = 0; i < glutGet(GLUT_WINDOW_WIDTH); i += pixelSize)
		{
			++__count;
			uniform.stream[__count] = vel * (cos(alpha) * j - sin(alpha) * i);
			uniform.potential[__count] = vel * (cos(alpha) * i + sin(alpha) * j);
		}
	}

	return uniform;
}

Flow Field::Source(std::vector<float> &points, float xDis, float yDis, float Q)
{
	float x, y;
	for (int i = 0; i < (int)(0.25f * points.size()); ++i)
	{
		x = __velocityContainer[4 * i + 2] - xDis; y = __velocityContainer[4 * i + 3] - yDis;

		source.velocity[2 * i] = (Q / (2 * 3.1415926f)) * (x / (x * x + y * y));
		source.velocity[2 * i + 1] = (Q / (2 * 3.1415926f)) * (y / (x * x + y * y));
	}

	int __count = -1;
	for (int j = 0; j < glutGet(GLUT_WINDOW_HEIGHT); j += pixelSize)
	{
		for (int i = 0; i < glutGet(GLUT_WINDOW_WIDTH); i += pixelSize)
		{
			++__count;
			source.stream[__count] = (Q / (2 * 3.1415926f)) * abs(atan((j - yDis) / (i - xDis)));
			if ((i - xDis) * (i - xDis) + (j - yDis) * (j - yDis) != 0) 
				source.potential[__count] = (Q / (2 * 3.1415926f)) * log(sqrt(abs((i - xDis) * (i - xDis) + (j - yDis) * (j - yDis))));
		}
	}

	return source;
}

Flow Field::Vortex(std::vector<float> &points, float xDis, float yDis, float gamma)
{
	float x, y;
	for (int i = 0; i < (int)(0.25f * points.size()); ++i)
	{
		x = __velocityContainer[4 * i + 2] - xDis; y = __velocityContainer[4 * i + 3] - yDis;
		vortex.velocity[2 * i] = -(gamma / (2 * 3.1415926f)) * (y / (x * x + y * y));
		vortex.velocity[2 * i + 1] = (gamma / (2 * 3.1415926f)) * (x / (x * x + y * y));
	}

	int __count = -1;
	for (int j = 0; j < glutGet(GLUT_WINDOW_HEIGHT); j += pixelSize)
	{
		for (int i = 0; i < glutGet(GLUT_WINDOW_WIDTH); i += pixelSize)
		{
			++__count;
			if ((i - xDis) * (i - xDis) + (j - yDis) * (j - yDis) != 0)
				vortex.stream[__count] = (gamma / (2 * 3.1415926f)) * log(sqrt(abs((i - xDis) * (i - xDis) + (j - yDis) * (j - yDis))));
			vortex.potential[__count] = (gamma / (2 * 3.1415926f)) * abs(atan((j - yDis) / (i - xDis)));
		}
	}

	return vortex;
}

Flow Field::Doublet(std::vector<float> &points, float xDis, float yDis, float mu)
{
	float x, y;
	for (int i = 0; i < (int)(0.25f * points.size()); ++i)
	{
		x = __velocityContainer[4 * i + 2] - xDis; y = __velocityContainer[4 * i + 3] - yDis;
		doublet.velocity[2 * i] = -mu * (x * x - y * y) / ((x * x + y * y) * (x * x + y * y));
		doublet.velocity[2 * i + 1] = -mu * ((2 * x * y) / ((x * x + y * y) * (x * x + y * y)));
	}

	int __count = -1;
	for (int j = 0; j < glutGet(GLUT_WINDOW_HEIGHT); j += pixelSize)
	{
		for (int i = 0; i < glutGet(GLUT_WINDOW_WIDTH); i += pixelSize)
		{
			++__count;
			doublet.stream[__count] = mu * sin(abs(atan((j - yDis) / (i - xDis)))) / sqrt(((i - xDis) * (i - xDis) + (j - yDis) * (j - yDis)));
			doublet.potential[__count] = mu * cos(abs(atan((j - yDis) / (i - xDis)))) / sqrt((i - xDis) * (i - xDis) + (j - yDis) * (j - yDis));

			if (doublet.stream[__count] > 0.015f * mu) doublet.stream[__count] = 0.015f * mu;
			if (doublet.potential[__count] > 0.015f * mu) doublet.potential[__count] = 0.015f * mu;
		}
	}

	return doublet;
}

void Field::InitializeNewFlow(Flow &flow, std::vector<float> &points)
{
	//velocity
	for (int i = 0; i < (int)(0.5f * points.size()); ++i) __tempVelocity.push_back(flow.velocity[i]);

	for (int i = 0; i < (int)(0.25f * points.size()); ++i)
	{
		__velocity[2 * i] = __velocity[2 * i + 1] = 0;
		for (int j = 0; j < (int)__tempVelocity.size(); j += (int)(0.5f * points.size()))
		{
			__velocity[2 * i] += __tempVelocity[2 * i + j];
			__velocity[2 * i + 1] += __tempVelocity[2 * i + 1 + j];
		}

		if (sqrt(__velocity[2 * i] * __velocity[2 * i] + __velocity[2 * i + 1] * __velocity[2 * i + 1]) > 10.0f)
		{
			__velocity[2 * i] = 10.0f * __velocity[2 * i] / sqrt(__velocity[2 * i] * __velocity[2 * i] + __velocity[2 * i + 1] * __velocity[2 * i + 1]);
			__velocity[2 * i + 1] = 10.0f * __velocity[2 * i + 1] / sqrt(__velocity[2 * i] * __velocity[2 * i] + __velocity[2 * i + 1] * __velocity[2 * i + 1]);
		}

		points[4 * i + 2] = __velocityContainer[4 * i] + __velocity[2 * i];
		points[4 * i + 3] = __velocityContainer[4 * i + 1] + __velocity[2 * i + 1];
		__velocityContainer[4 * i + 2] = points[4 * i + 2];
		__velocityContainer[4 * i + 3] = points[4 * i + 3];
	}

	//velocity magnitude
	minVel = 10000.0f; maxVel = -10000.0f;

	for (int i = 0; i < (int)(0.25f * points.size()); ++i)
		__velocityMagnitude[2 * i] = __velocityMagnitude[2 * i + 1] = sqrt(__velocity[2 * i] * __velocity[2 * i] + __velocity[2 * i + 1] * __velocity[2 * i + 1]);

	for (int i = 0; i < (int)(__velocityMagnitude.size()); ++i)
	{
		if (maxVel < abs(__velocityMagnitude[i])) maxVel = __velocityMagnitude[i];
		if (minVel > __velocityMagnitude[i]) minVel = __velocityMagnitude[i];
	}

	float __velStep = abs(maxVel - minVel) / 4;
	utility.SetGradient(pointsColors, __velocityMagnitude, minVel, __velStep);

	//stream function
	minStream = 10000.0f; maxStream = -10000.0f;

	for (int i = 0; i < (int)flow.stream.size(); ++i)
		__streamContainer.push_back(flow.stream[i]);

	for (int i = 0; i < (int)__tempStream.size(); ++i) __tempStream[i] = 0;

	for (int j = 0; j < (int)__streamContainer.size(); j += flow.stream.size())
		for (int i = 0; i < (int)flow.stream.size(); ++i)
			__tempStream[i] += __streamContainer[i + j];

	for (int i = 0; i < (int)__tempStream.size(); ++i)
	{
		if (minStream > __tempStream[i]) minStream = __tempStream[i];
		if (maxStream < (__tempStream[i])) maxStream = __tempStream[i];
	}

	//modify streamlines color
	float __streamStep = abs(maxStream - minStream) / 4;
	utility.SetGradient(streamColors, __tempStream, minStream, __streamStep);

	//potential function
	minPotential = 10000.0f; maxPotential = -10000.0f;

	for (int i = 0; i < (int)flow.potential.size(); ++i)
		__potentialContainer.push_back(flow.potential[i]);

	for (int i = 0; i < (int)__tempPotential.size(); ++i) __tempPotential[i] = 0;

	for (int j = 0; j < (int)__potentialContainer.size(); j += flow.potential.size())
		for (int i = 0; i < (int)flow.potential.size(); ++i)
			__tempPotential[i] += __potentialContainer[i + j];

	for (int i = 0; i < (int)__tempPotential.size(); ++i)
	{
		if (minPotential > __tempPotential[i]) minPotential = __tempPotential[i];
		if (maxPotential < abs(__tempPotential[i])) maxPotential = __tempPotential[i];
	}

	//modify potential color
	float __potentialStep = abs(maxPotential - minPotential) / 4;
	utility.SetGradient(potentialColors, __tempPotential, minPotential, __potentialStep);
}

void Field::UpdateSelectedFlow(int c, Flow &flow, std::vector<float> &points, bool del)
{
	//velocity
	for (int i = (int)(c * 0.5f * points.size()); i < (int)((c + 1) * 0.5f * points.size()); ++i)
		__tempVelocity[i] = flow.velocity[i - (int)(c * 0.5f * points.size())];

	for (int i = (int)(c * flow.stream.size()); i < (int)((c + 1) * flow.stream.size()); ++i)
		__streamContainer[i] = flow.stream[i - (int)(c * flow.stream.size())];

	for (int i = (int)(c * flow.potential.size()); i < (int)((c + 1) * flow.potential.size()); ++i)
		__potentialContainer[i] = flow.potential[i - (int)(c * flow.potential.size())];
	
	for (int i = 0; i < (int)(0.25f * points.size()); ++i)
	{
		__velocity[2 * i] = __velocity[2 * i + 1] = 0;
		for (int j = 0; j < (int)__tempVelocity.size(); j += (int)(0.5f * points.size()))
		{
			__velocity[2 * i] += __tempVelocity[2 * i + j];
			__velocity[2 * i + 1] += __tempVelocity[2 * i + 1 + j];
		}

		if (sqrt(__velocity[2 * i] * __velocity[2 * i] + __velocity[2 * i + 1] * __velocity[2 * i + 1]) > 10.0f)
		{
			__velocity[2 * i] = 10.0f * __velocity[2 * i] / sqrt(__velocity[2 * i] * __velocity[2 * i] + __velocity[2 * i + 1] * __velocity[2 * i + 1]);
			__velocity[2 * i + 1] = 10.0f * __velocity[2 * i + 1] / sqrt(__velocity[2 * i] * __velocity[2 * i] + __velocity[2 * i + 1] * __velocity[2 * i + 1]);
		}

		points[4 * i + 2] = __velocityContainer[4 * i] + __velocity[2 * i];
		points[4 * i + 3] = __velocityContainer[4 * i + 1] + __velocity[2 * i + 1];
		__velocityContainer[4 * i + 2] = points[4 * i + 2];
		__velocityContainer[4 * i + 3] = points[4 * i + 3];
	}

	//velocity magnitude
	minVel = 10000.0f, maxVel = -10000.0f;

	for (int i = 0; i < (int)(0.25f * points.size()); ++i)
		__velocityMagnitude[2 * i] = __velocityMagnitude[2 * i + 1] = sqrt(__velocity[2 * i] * __velocity[2 * i] + __velocity[2 * i + 1] * __velocity[2 * i + 1]);

	for (int i = 0; i < (int)__velocityMagnitude.size(); ++i)
	{
		if (maxVel < abs(__velocityMagnitude[i])) maxVel = __velocityMagnitude[i];
		if (minVel > __velocityMagnitude[i]) minVel = __velocityMagnitude[i];
	}

	float __velStep = abs(maxVel - minVel) / 4;

	//create velocity color ramp/gradient
	utility.SetGradient(pointsColors, __velocityMagnitude, minVel, __velStep);

	//stream function
	for (int i = 0; i < (int)flow.stream.size(); ++i) __tempStream[i] = 0;

	for (int j = 0; j < (int)__streamContainer.size(); j += flow.stream.size())
		for (int i = 0; i < (int)flow.stream.size(); ++i)
			__tempStream[i] += __streamContainer[i + j];

	minStream = 10000.0f; maxStream = -10000.0f;

	for (int i = 0; i < (int)__tempStream.size(); ++i)
	{
		if (minStream > __tempStream[i]) minStream = __tempStream[i];
		if (maxStream < abs(__tempStream[i])) maxStream = __tempStream[i];
	}
	
	//modify streamlines color
	float __streamStep = abs(maxStream - minStream) / 4;
	utility.SetGradient(streamColors, __tempStream, minStream, __streamStep);

	//potential function
	for (int i = 0; i < (int)__tempPotential.size(); ++i) __tempPotential[i] = 0;

	for (int j = 0; j < (int)__potentialContainer.size(); j += flow.stream.size())
		for (int i = 0; i < (int)flow.stream.size(); ++i)
			__tempPotential[i] += __potentialContainer[i + j];

	minPotential = 10000.0f; maxPotential = -10000.0f;

	for (int i = 0; i < (int)__tempPotential.size(); ++i)
	{
		if (minPotential > __tempPotential[i]) minPotential = __tempPotential[i];
		if (maxPotential < abs(__tempPotential[i])) maxPotential = __tempPotential[i];
	}

	//modify potential colors
	float __potentialStep = abs(maxPotential - minPotential) / 4;
	utility.SetGradient(potentialColors, __tempPotential, minPotential, __potentialStep);
}
