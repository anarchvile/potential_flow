#include "pch.h"
#include "field.h"
#include "utility.h"
#include "main.h"

#include <glut.h>
#include <iostream>

Utility utility;
UtilParams utilParams;
int __xPos, __yPos, __ID;

void Utility::InitializeKey()
{
	//red-yellow
	utilParams.keyPoints.push_back(utilParams.windowWidth - 50); utilParams.keyPoints.push_back(15);
	utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(0);
	utilParams.keyPoints.push_back(utilParams.windowWidth - 10); utilParams.keyPoints.push_back(15);
	utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(0);
	utilParams.keyPoints.push_back(utilParams.windowWidth - 10); utilParams.keyPoints.push_back(40);
	utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(0);

	utilParams.keyPoints.push_back(utilParams.windowWidth - 50); utilParams.keyPoints.push_back(15);
	utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(0);
	utilParams.keyPoints.push_back(utilParams.windowWidth - 50); utilParams.keyPoints.push_back(40);
	utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(0);
	utilParams.keyPoints.push_back(utilParams.windowWidth - 10); utilParams.keyPoints.push_back(40);
	utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(0);

	//yellow-green
	utilParams.keyPoints.push_back(utilParams.windowWidth - 50); utilParams.keyPoints.push_back(40);
	utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(0);
	utilParams.keyPoints.push_back(utilParams.windowWidth - 10); utilParams.keyPoints.push_back(40);
	utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(0);
	utilParams.keyPoints.push_back(utilParams.windowWidth - 10); utilParams.keyPoints.push_back(65);
	utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(0);

	utilParams.keyPoints.push_back(utilParams.windowWidth - 50); utilParams.keyPoints.push_back(40);
	utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(0);
	utilParams.keyPoints.push_back(utilParams.windowWidth - 50); utilParams.keyPoints.push_back(65);
	utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(0);
	utilParams.keyPoints.push_back(utilParams.windowWidth - 10); utilParams.keyPoints.push_back(65);
	utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(0);

	//green-blue
	utilParams.keyPoints.push_back(utilParams.windowWidth - 50); utilParams.keyPoints.push_back(65);
	utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(0);
	utilParams.keyPoints.push_back(utilParams.windowWidth - 10); utilParams.keyPoints.push_back(65);
	utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(0);
	utilParams.keyPoints.push_back(utilParams.windowWidth - 10); utilParams.keyPoints.push_back(90);
	utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(1);

	utilParams.keyPoints.push_back(utilParams.windowWidth - 50); utilParams.keyPoints.push_back(65);
	utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(1); utilParams.keyColors.push_back(0);
	utilParams.keyPoints.push_back(utilParams.windowWidth - 50); utilParams.keyPoints.push_back(90);
	utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(1);
	utilParams.keyPoints.push_back(utilParams.windowWidth - 10); utilParams.keyPoints.push_back(90);
	utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(1);

	//blue-black
	utilParams.keyPoints.push_back(utilParams.windowWidth - 50); utilParams.keyPoints.push_back(90);
	utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(1);
	utilParams.keyPoints.push_back(utilParams.windowWidth - 10); utilParams.keyPoints.push_back(90);
	utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(1);
	utilParams.keyPoints.push_back(utilParams.windowWidth - 10); utilParams.keyPoints.push_back(115);
	utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(0);

	utilParams.keyPoints.push_back(utilParams.windowWidth - 50); utilParams.keyPoints.push_back(90);
	utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(1);
	utilParams.keyPoints.push_back(utilParams.windowWidth - 50); utilParams.keyPoints.push_back(115);
	utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(0);
	utilParams.keyPoints.push_back(utilParams.windowWidth - 10); utilParams.keyPoints.push_back(115);
	utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(0); utilParams.keyColors.push_back(0);
}

void Utility::UpdateKey()
{
	utilParams.keyPoints[0] = utilParams.windowWidth - 50;
	utilParams.keyPoints[2] = utilParams.windowWidth - 10;
	utilParams.keyPoints[4] = utilParams.windowWidth - 10;
	utilParams.keyPoints[6] = utilParams.windowWidth - 50;
	utilParams.keyPoints[8] = utilParams.windowWidth - 50;
	utilParams.keyPoints[10] = utilParams.windowWidth - 10;

	utilParams.keyPoints[12] = utilParams.windowWidth - 50;
	utilParams.keyPoints[14] = utilParams.windowWidth - 10;
	utilParams.keyPoints[16] = utilParams.windowWidth - 10;
	utilParams.keyPoints[18] = utilParams.windowWidth - 50;
	utilParams.keyPoints[20] = utilParams.windowWidth - 50;
	utilParams.keyPoints[22] = utilParams.windowWidth - 10;

	utilParams.keyPoints[24] = utilParams.windowWidth - 50;
	utilParams.keyPoints[26] = utilParams.windowWidth - 10;
	utilParams.keyPoints[28] = utilParams.windowWidth - 10;
	utilParams.keyPoints[30] = utilParams.windowWidth - 50;
	utilParams.keyPoints[32] = utilParams.windowWidth - 50;
	utilParams.keyPoints[34] = utilParams.windowWidth - 10;

	utilParams.keyPoints[36] = utilParams.windowWidth - 50;
	utilParams.keyPoints[38] = utilParams.windowWidth - 10;
	utilParams.keyPoints[40] = utilParams.windowWidth - 10;
	utilParams.keyPoints[42] = utilParams.windowWidth - 50;
	utilParams.keyPoints[44] = utilParams.windowWidth - 50;
	utilParams.keyPoints[46] = utilParams.windowWidth - 10;

	if (utilParams.windowHeight < (2 * utilParams.keyPoints[utilParams.keyPoints.size() - 1]))
		for (int i = 0; i < (int)(0.5f * utilParams.keyPoints.size()); ++i)
			utilParams.keyPoints[2 * i + 1] /= 2;

	else if (utilParams.windowHeight > 5 * utilParams.keyPoints[utilParams.keyPoints.size() - 1])
		for (int i = 0; i < (int)(0.5f * utilParams.keyPoints.size()); ++i)
			utilParams.keyPoints[2 * i + 1] *= 2;
}

void Utility::AddFlow()
{
	if (input.rightMouseButtonPressed)
	{
		field.origin.push_back(input.initialRightMousePosition.x);
		field.origin.push_back(input.initialRightMousePosition.y);

		if (field.uniformBool)
		{
			field.originColors.push_back(1);
			field.originColors.push_back(1);
			field.originColors.push_back(1);

			field.flowType.push_back(0);
			field.flowType.push_back(input.initialRightMousePosition.x);
			field.flowType.push_back(input.initialRightMousePosition.y);
			field.flowType.push_back(5);

			uniform = field.Uniform(field.points, input.initialRightMousePosition.x, input.initialRightMousePosition.y, 5, 3.1415926f / 6.0f);
			field.InitializeNewFlow(uniform, field.points);
		}

		else if (field.sourceBool)
		{
			field.originColors.push_back(1);
			field.originColors.push_back(0);
			field.originColors.push_back(0);

			field.flowType.push_back(1);
			field.flowType.push_back(input.initialRightMousePosition.x);
			field.flowType.push_back(input.initialRightMousePosition.y);
			field.flowType.push_back(2500);

			source = field.Source(field.points, input.initialRightMousePosition.x, input.initialRightMousePosition.y, 2500);
			field.InitializeNewFlow(source, field.points);
		}

		else if (field.vortexBool)
		{
			field.originColors.push_back(0);
			field.originColors.push_back(1);
			field.originColors.push_back(0);

			field.flowType.push_back(2);
			field.flowType.push_back(input.initialRightMousePosition.x);
			field.flowType.push_back(input.initialRightMousePosition.y);
			field.flowType.push_back(2500);

			vortex = field.Vortex(field.points, input.initialRightMousePosition.x, input.initialRightMousePosition.y, 2500);
			field.InitializeNewFlow(vortex, field.points);
		}

		else if (field.doubletBool)
		{
			field.originColors.push_back(0);
			field.originColors.push_back(0);
			field.originColors.push_back(1);

			field.flowType.push_back(3);
			field.flowType.push_back(input.initialRightMousePosition.x);
			field.flowType.push_back(input.initialRightMousePosition.y);
			field.flowType.push_back(62500);

			doublet = field.Doublet(field.points, input.initialRightMousePosition.x, input.initialRightMousePosition.y, 62500);
			field.InitializeNewFlow(doublet, field.points);
		}

		input.rightMouseButtonPressed = false;
		field.updateField = true;
	}

	else field.updateField = false;
}

void Utility::SelectFlow()
{
	if (input.leftMouseButtonPressed)
	{
		field.pointSelected = false;
		for (int i = 0; i < (int)(0.5f * field.origin.size()); ++i)
		{
			if (input.initialLeftMousePosition.x >= field.origin[2 * i] - 15.0f && input.initialLeftMousePosition.x <= field.origin[2 * i] + 15.0f && input.initialLeftMousePosition.y >= field.origin[2 * i + 1] - 15.0f && input.initialLeftMousePosition.y <= field.origin[2 * i + 1] + 15.0f)
			{
				__xPos = 2 * i; //selected simple flow origin point (x-value)
				__yPos = 2 * i + 1; //selected simple flow origin point (y-value)
				field.ID = i; //selected simple flow ID
				field.pointSelected = true;
			}
		}

		input.leftMouseButtonPressed = false;
		field.updateField = true;
	}
}

void Utility::MoveFlow()
{
	if (input.leftMouseButtonDown)
	{
		if (field.pointSelected)
		{
			field.origin[__xPos] = input.leftMousePosition.x;
			field.origin[__yPos] = input.leftMousePosition.y;

			if (field.flowType[4 * field.ID] == 0)
			{
				uniform = field.Uniform(field.points, input.leftMousePosition.x, input.leftMousePosition.y, field.flowType[4 * field.ID + 3], 3.1415926f / 6.0f);
				field.UpdateSelectedFlow(field.ID, uniform, field.points, false);
			}

			if (field.flowType[4 * field.ID] == 1)
			{
				source = field.Source(field.points, input.leftMousePosition.x, input.leftMousePosition.y, field.flowType[4 * field.ID + 3]);
				field.UpdateSelectedFlow(field.ID, source, field.points, false);
			}

			else if (field.flowType[4 * field.ID] == 2)
			{
				vortex = field.Vortex(field.points, input.leftMousePosition.x, input.leftMousePosition.y, field.flowType[4 * field.ID + 3]);
				field.UpdateSelectedFlow(field.ID, vortex, field.points, false);
			}

			else if (field.flowType[4 * field.ID] == 3)
			{
				doublet = field.Doublet(field.points, input.leftMousePosition.x, input.leftMousePosition.y, field.flowType[4 * field.ID + 3]);
				field.UpdateSelectedFlow(field.ID, doublet, field.points, false);
			}

			field.flowType[4 * field.ID + 1] = input.leftMousePosition.x;
			field.flowType[4 * field.ID + 2] = input.leftMousePosition.y;

			field.updateField = true;
		}		
	}
}

void Utility::DeleteFlow()
{
	if (field.del)
	{
		field.updateField = true;

		field.origin.erase(field.origin.begin() + 2 * field.ID);
		field.origin.erase(field.origin.begin() + 2 * field.ID);

		field.originColors.erase(field.originColors.begin() + 3 * field.ID);
		field.originColors.erase(field.originColors.begin() + 3 * field.ID);
		field.originColors.erase(field.originColors.begin() + 3 * field.ID);

		field.flowType.erase(field.flowType.begin() + 4 * field.ID);
		field.flowType.erase(field.flowType.begin() + 4 * field.ID);
		field.flowType.erase(field.flowType.begin() + 4 * field.ID);
		field.flowType.erase(field.flowType.begin() + 4 * field.ID);

		field.InitializeField();
		field.ReinitializeField(field.points);
		//field.del = false;
	}
}

void Utility::SetGradient(std::vector<float> &colors, std::vector<float> &values, float &min, float &step)
{
	for (int i = 0; i < (int)(values.size()); ++i)
	{
		if (values[i] < min + step)
		{
			colors[3 * i] = 0;
			colors[3 * i + 1] = 0;
			colors[3 * i + 2] = (values[i] - min) / step;
		}

		else if (values[i] < min + 2 * step)
		{
			colors[3 * i] = 0;
			colors[3 * i + 1] = (values[i] - (min + step)) / step;
			colors[3 * i + 2] = 1 - (values[i] - (min + step)) / step;
		}

		else if (values[i] < min + 3 * step)
		{
			colors[3 * i] = (values[i] - (min + 2 * step)) / step;
			colors[3 * i + 1] = 1;
			colors[3 * i + 2] = 0;
		}

		else
		{
			colors[3 * i] = 1;
			colors[3 * i + 1] = 1 - (values[i] - (min + 3 * step)) / step;
			colors[3 * i + 2] = 0;
		}
	}
}