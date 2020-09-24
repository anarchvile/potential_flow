#ifndef CHARACTER_H
#define CHARACTER_H

#include <gl/glew.h>
#include <vector>
#include <map>
#include <iostream>

struct Character
{
	std::vector<std::vector<int>> null =
	{
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 }
	};

	std::vector<std::vector<int>> negative = 
	{
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 }
	};

	std::vector<std::vector<int>> decimal =
	{
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0 }
	};

	std::vector<std::vector<int>> zero =
	{
		{ 0, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 1 },
		{ 1, 1, 0, 0, 1 },
		{ 1, 0, 1, 0, 1 },
		{ 1, 0, 0, 1, 1 },
		{ 1, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 0 }
	};

	std::vector<std::vector<int>> one =
	{
		{ 0, 0, 1, 0, 0 },
		{ 0, 1, 1, 0, 0 },
		{ 0, 0, 1, 0, 0 },
		{ 0, 0, 1, 0, 0 },
		{ 0, 0, 1, 0, 0 },
		{ 0, 0, 1, 0, 0 },
		{ 0, 1, 1, 1, 0 }
	};

	std::vector<std::vector<int>> two =
	{
		{ 0, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 1, 0 },
		{ 0, 0, 1, 0, 0 },
		{ 0, 1, 0, 0, 0 },
		{ 1, 1, 1, 1, 1 }
	};

	std::vector<std::vector<int>> three =
	{
		{ 0, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 1 },
		{ 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 0 }
	};

	std::vector<std::vector<int>> four =
	{
		{ 0, 0, 0, 1, 0 },
		{ 0, 0, 1, 1, 0 },
		{ 0, 1, 0, 1, 0 },
		{ 1, 0, 0, 1, 0 },
		{ 1, 1, 1, 1, 1 },
		{ 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 1, 0 }
	};

	std::vector<std::vector<int>> five =
	{
		{ 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0 },
		{ 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 0 }
	};

	std::vector<std::vector<int>> six =
	{
		{ 0, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 0 }
	};

	std::vector<std::vector<int>> seven =
	{
		{ 1, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 1, 0 },
		{ 0, 0, 1, 0, 0 },
		{ 0, 0, 1, 0, 0 },
		{ 0, 0, 1, 0, 0 },
		{ 0, 0, 1, 0, 0 }
	};

	std::vector<std::vector<int>> eight =
	{
		{ 0, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 0 }
	};

	std::vector<std::vector<int>> nine =
	{
		{ 0, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 0 }
	};
};

Character character;

class CharacterGeneration
{
public:
	CharacterGeneration() { std::cout << "num constructed\n"; }

	static std::vector<float> charPos;
	static std::vector<float> charColor;
	static std::map<int, std::vector<std::vector<int>>> charValuePair;
	static int num;

	std::vector<float> emptyVectorFloat;
	std::map<int, std::vector<std::vector<int>>> emptyMap;

	static void InitRenderData(GLuint *VAO, GLuint VBO[2], std::vector<float> &charPos, std::vector<float> &charColor, std::map<int, std::vector<std::vector<int>>> &charValuePair)
	{
		charValuePair = //keys correspond to characters' ascii decimal values
		{
			{ 0,  character.null },
			{ 45, character.negative },
			{ 46, character.decimal },
			{ 48, character.zero },
			{ 49, character.one },
			{ 50, character.two },
			{ 51, character.three },
			{ 52, character.four },
			{ 53, character.five },
			{ 54, character.six },
			{ 55, character.seven },
			{ 56, character.eight },
			{ 57, character.nine }
		};

		glGenVertexArrays(1, VAO);
		glBindVertexArray(*VAO);
		glGenBuffers(2, VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * charPos.size(), &charPos[0], GL_DYNAMIC_DRAW);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (void*)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * charColor.size(), &charColor[0], GL_DYNAMIC_DRAW);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);
		glEnableVertexAttribArray(1);
	}

	static void InitChar(int key, int xOffset, int yOffset, std::vector<float> &charPos, std::vector<float> &charColor, std::map<int, std::vector<std::vector<int>>> &charValuePair)
	{
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 7; ++j)
			{
				charPos.push_back(i + xOffset);
				charPos.push_back(j + yOffset);

				if (charValuePair.at(key)[j][i] == 1)
				{
					charColor.push_back(1);
					charColor.push_back(1);
					charColor.push_back(1);
				}

				else
				{
					charColor.push_back(0);
					charColor.push_back(0);
					charColor.push_back(0);
				}
			}
		}
	}

	/*static void UpdateChar(int key, int xOffset, int yOffset)
	{
		int idx = -1;
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 7; ++j)
			{
				++idx;
				//std::cout << 2 * idx << ',' << 2 * idx + 1 << std::endl;
				//Character::charPos[2 * idx] = i + xOffset;
				//Character::charPos[2 * idx + 1] = j + yOffset;

				if (character.charValuePair.at(key)[j][i] == 1)
					character.charColor[3 * idx] = character.charColor[3 * idx + 1] = character.charColor[3 * idx + 2] = 1;
				else character.charColor[3 * idx] = character.charColor[3 * idx + 1] = character.charColor[3 * idx + 2] = 0;
			}
		}
	}*/

	static void UpdateRenderData(GLuint *VAO, GLuint VBO[2], std::vector<float> &charPos, std::vector<float> &charColor)
	{
		glBindVertexArray(*VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * charPos.size(), NULL, GL_DYNAMIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_FLOAT) * charPos.size(), &charPos[0]);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * charColor.size(), NULL, GL_DYNAMIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_FLOAT) * charColor.size(), &charColor[0]);
		glEnableVertexAttribArray(1);

		charPos.clear(); charColor.clear();
	}

	static void LoadChar(std::string text, int xOffset, int yOffset, bool clear, std::vector<float> &charPos, std::vector<float> &charColor, std::map<int, std::vector<std::vector<int>>> &charValuePair)
	{
		int __charOffset = -6;
		for (char& c : text)
		{
			__charOffset += 6;
			InitChar((int)c, xOffset + __charOffset, yOffset, charPos, charColor, charValuePair);

			if (__charOffset >= 32) break;
		}
	}

	static void Draw(GLuint *VAO, std::vector<float> &charPos)
	{
		glBindVertexArray(*VAO);
		glDrawArrays(GL_POINTS, 0, charPos.size());
		glBindVertexArray(0);
	}
};

CharacterGeneration charGen;

std::vector<float> CharacterGeneration::charPos = charGen.emptyVectorFloat;
std::vector<float> CharacterGeneration::charColor = charGen.emptyVectorFloat;
std::map<int, std::vector<std::vector<int>>> CharacterGeneration::charValuePair = charGen.emptyMap;

#endif