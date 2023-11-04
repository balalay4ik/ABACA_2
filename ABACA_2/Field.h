#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <string>
#include "stb_easy_font.h"
#include "Vector2.h"

using namespace std;

class Field
{
private:
	int score;
	bool holdet = false;
	int x;
	int y;
	string fraction;

	char str[10] = "";
	string str1;

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
	Field() {};
	Field(string fraction) { this->fraction = fraction; }

	void SetCoord(int i, int j) { x = j; y = i; }
	Vector2 GetCoord() { return Vector2(x, y); }
	void SetScore(int score) { if (!holdet) { this->score = score; holdet = true; } }
	int GetScore() { return score; }
	bool GetHoldet() { return holdet; }

	void Write(bool layer2 = false);
	void WriteSquare(float r, float g, float b);
	void WriteCross();
	void WriteFillSquare(float r, float g, float b);
};

