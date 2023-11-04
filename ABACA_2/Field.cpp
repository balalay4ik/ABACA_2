#include "Field.h"
//#include "stb_easy_font.h"

const int width = 6;
const int height = 16;

void Field::Write(bool layer2)
{
	if (!layer2)
	{
		if (x != width - 1)
		{
			if (y == height - 1)
				WriteSquare(0.7, 0, 0);
			else
			{
				if (fraction == "Green")
					WriteSquare(0, 0.7, 0);
				else if (fraction == "Orange")
					WriteSquare(0.7, 0.45, 0);
			}
		}
		else
			WriteSquare(0.7, 0, 0);
	}
	else
		if (holdet)
		{
			if (fraction == "Green")
				WriteFillSquare(0, 0.7, 0);
			else if (fraction == "Orange")
				WriteFillSquare(0.7, 0.45, 0);

			WriteSquare(0.7, 0, 0);

			if (score == 0)
			{
				WriteCross();
			}
			else
			{
				str1 = to_string(score);
				strcpy_s(str, str1.c_str());
				if (x == 5)
				{
					glTranslatef(0.1, 0, 0);
					glScalef(8.0645161290322, 1, 1);
					glScalef(0.0935, 1, 1);
					glScalef(0.05, -0.1, 1);
				}
				else
				{
					glScalef(0.05, -0.1, 1);
				}

				switch (str1.length())
				{
				case 1:
					glTranslatef(7, 0, 0);
					break;
				case 2:
					glTranslatef(5, 0, 0);
					break;
				case 3:
					glTranslatef(2, 0, 0);
					break;
				default:
					break;
				}

				print_string(0, -8.4, str, 0, 0, 0);
			}
		}
}

void Field::WriteSquare(float r, float g, float b)
{
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glColor3f(r, g, b);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 1);
	glVertex2f(0, 1);
	glEnd();
}

void Field::WriteCross()
{
	glBegin(GL_LINES);
	glColor3f(0.7, 0, 0);
	glVertex2f(0, 0);
	glVertex2f(1, 1);
	glVertex2f(1, 0);
	glVertex2f(0, 1);
	glEnd();
}

void Field::WriteFillSquare(float r, float g, float b)
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(r, g, b);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 1);
	glVertex2f(0, 1);
	glEnd();
}