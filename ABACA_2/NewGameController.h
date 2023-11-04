#pragma once
#include "Dice.h"
#include "Grid.h"

class NewGameController
{
private:
	Dice Player1[5];
	Dice Player2[5];
	int iteration = 0;
	int S1 = 0;
	int S2 = 0;
	class GameController* gameController;
	string nameP1 = "";
	string nameP2 = "";
	string FirstName = "First name:";
	string SecondName = "Second name:";
	int limitSymbol = 9;

	char str[20] = "";
	string str1;

	void WriteFillSquare(float r, float g, float b);
	void WriteDices();
	void WriteInfo();

	void print_string(float x, float y, string str, float r, float g, float b)
	{
		char text[100] = "";
		strcpy_s(text, str.c_str());

		static char buffer[99999]; // ~500 chars
		int num_quads;

		num_quads = stb_easy_font_print(x, y, text, NULL, buffer, sizeof(buffer));

		glColor3f(r, g, b);
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(2, GL_FLOAT, 16, buffer);
		glDrawArrays(GL_QUADS, 0, num_quads * 4);
		glDisableClientState(GL_VERTEX_ARRAY);
	}

	void NewScore();
	void WriteAuthor();

public:
	void Button(WPARAM wParam);
	void Update();
	void Init(GameController* game);

};

