#pragma once

#include <glm/glm.hpp>
#include "EntityComponents/Entity.h"

class Grid
{
public:
	Grid()
	{
		for (int y = cols; y > -cols; y--)
		{
			for (int x = -rows; x < rows; x++)
			{
				glm::vec2 iso = GetIsoCoordinates(glm::vec2(x * width, y * width));
				positions.push_back(iso + origin);
			}
		}
	}

	glm::vec2 GetIsoCoordinates(const glm::vec2& coord)
	{
		glm::vec2 result;
		result.x = coord.x + coord.y;
		result.y = (-coord.x * 0.5f) + (0.5f * coord.y);
		return result;
	}

	glm::vec2 GetWorldCoordinates(const glm::vec2& coord)
	{
		glm::vec2 result;
		result.x = 0.5f * coord.x - coord.y;
		result.y = 0.5f * coord.x + coord.y;
		return result;
	}

	int Collide(int x, int y)
	{
		for (auto& position : positions)
		{

		}
	}

public:
	glm::vec2 size = { 64, 32 };
	float scale = 1.0f;
	float width = size.x * scale / 2;
	float height = size.y * scale / 2;
	glm::vec2 origin = { 1280.0f / 2.0f, 720.0f / 2.0f };

	int cols = 5;
	int rows = 5;

	std::vector<glm::vec2> positions;
};