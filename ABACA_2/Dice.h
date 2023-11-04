#pragma once
#include <windows.h>
#include <gl/gl.h>

class Dice
{
private:
	void WriteSquare();
	void WriteCross();

public:
	int num;
	bool holdet = false;
	bool invisible = false;
	void Write();
};

