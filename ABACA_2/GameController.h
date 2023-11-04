#pragma once
#include "Grid.h"
#include "Dice.h"
#include "NewGameController.h"

class GameController
{
private:
	Grid grid;
	Dice dice[5];
	Dice dice1;
	NewGameController* newGames = new NewGameController();
	bool newGame = true;
	string nameP1 = "";
	string nameP2 = "";

	int scoreDice[6] = { 0, 0, 0, 0, 0, 0 };
	bool GreenStep = true;
	bool randomized = true;
	int hold = 0;

	const int maxStep = 4;
	int step = 0;
	int fillCells[2] = { 45, 45 };
	int fillShool[2] = { 30, 30 };

	char str[100] = "";
	string str1;

	int FillCells(int cell, int score, bool type = false);
	void WriteFillSquare(float r, float g, float b);
	void FillCell(Field* cell, int score, bool type = false);
	void WriteDices();
	bool SchoolLogic(int cell);
	bool ComboLogic(int cell);
	void CalulateScore(Field* cell, bool type);
	void SaveStep(GameController* other);
	void LoadStep(const GameController* other);
	void WriteStep();
	void WriteTeamStep();
	void WriteName();
	void WriteScore();
	void print_string(float x, float y, char* text, float r, float g, float b)
	{
		static char buffer[99999]; // ~500 chars
		int num_quads;

		num_quads = stb_easy_font_print(x, y, text, NULL, buffer, sizeof(buffer));

		glColor3f(r, g, b);
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(2, GL_FLOAT, 16, buffer);
		glDrawArrays(GL_QUADS, 0, num_quads * 4);
		glDisableClientState(GL_VERTEX_ARRAY);
	}

public:

	void Init();
	void Update();
	void Step();
	bool CheckStep() { return step != maxStep - 1 ? true : false; }

	void ToggleTeam();
	void ToggleRandom();
	bool CheckRandom() { return randomized; }
	bool CheckNewGame() { return newGame; }
	void ToggleSaveDice(bool status) { dice[hold].invisible = status; }
	void NextDice(int d);
	bool Buttons();
	void LoadStep();
	void Cheat();
	NewGameController* GetNewGameController() { return newGames; }
	void InitNewGame(string nameP1, string nameP2);
	bool CheckEndGame() { return (fillCells[0] == 0 && fillCells[1] == 0 && fillShool[0] == 0 && fillShool[1] == 0); }
};

