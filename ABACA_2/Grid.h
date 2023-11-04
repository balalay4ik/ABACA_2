#pragma once
#include "Field.h"
#include "stb_easy_font.h"

const int width = 6;
const int height = 16;

class Grid
{
private:

	char str[10] = "";
	string str1;

	Field GreenTeam[height][width];
	Field OrangeTeam[height][width];

	Vector2 ScoreP1 = Vector2();
	Vector2 ScoreP2 = Vector2();

	void WriteGreenGrid();
	void WriteOrangeGrid();
	void WriteSystemGrid();
	void Print_Sum_symbol();


public:

	Grid()
	{
		for (int i = 0; i < height; i++)
		{

			for (int j = 0; j < width; j++)
			{
				GreenTeam[i][j] = Field("Green");
				GreenTeam[i][j].SetCoord(i, j);
				OrangeTeam[i][j] = Field("Orange");
				OrangeTeam[i][j].SetCoord(i, j);
			}
		}
	}

	void WriteGrid();
	Field* GetCell(int i, int j, bool team);

	Vector2* GetScorePlayer(bool team) { return team ? &ScoreP1 : &ScoreP2; }
};

