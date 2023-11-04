#include "Grid.h"

char sum[] = "SUM";
char sumin[] = "SUM in";
char school[] = "school";

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

void Grid::WriteGreenGrid()
{
	for (int i = 0; i < height; i++)
	{

		for (int j = 0; j < width; j++)
		{
			glPushMatrix();
			if (j != width - 1)
			{
				glScalef(0.0935, 0.101265, 1);
				glTranslatef(-9.285 + j, -i + 7.1, 0);
			}
			else
			{
				glScalef(0.124, 0.101265, 1);
				glTranslatef(-3.23, -i + 7.1, 0);
			}
			GreenTeam[i][j].Write();
			glPopMatrix();
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			glPushMatrix();
			if (j != width - 1)
			{
				glScalef(0.0935, 0.101265, 1);
				glTranslatef(-9.285 + j, -i + 7.1, 0);
			}
			else
			{
				glScalef(0.124, 0.101265, 1);
				glTranslatef(-3.23, -i + 7.1, 0);
			}
			GreenTeam[i][j].Write(true);
			glPopMatrix();
		}
	}
}

void Grid::WriteOrangeGrid()
{
	for (int i = 0; i < height; i++)
	{

		for (int j = 0; j < width; j++)
		{
			glPushMatrix();
			if (j != width - 1)
			{
				glScalef(0.0935, 0.101265, 1);
				glTranslatef(-2.95 + j, -i + 7.1, 0);
			}
			else
			{
				glScalef(0.124, 0.101265, 1);
				glTranslatef(1.545, -i + 7.1, 0);
			}
			OrangeTeam[i][j].Write();
			glPopMatrix();
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			glPushMatrix();
			if (j != width - 1)
			{
				glScalef(0.0935, 0.101265, 1);
				glTranslatef(-2.95 + j, -i + 7.1, 0);
			}
			else
			{
				glScalef(0.124, 0.101265, 1);
				glTranslatef(1.545, -i + 7.1, 0);
			}
			OrangeTeam[i][j].Write(true);
			glPopMatrix();
		}
	}
}

void Grid::WriteSystemGrid()
{
	for (int i = 0; i < height; i++)
	{
		glPushMatrix();
		glScalef(0.124, 0.101265, 1);
		glTranslatef(-8, 7.1 - i, 0);
		OrangeTeam[0][0].WriteSquare(0.7, 0, 0);
		glPopMatrix();
	}

	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(0.7, 0, 0);
	glVertex2f(0.4, -0.6);
	glVertex2f(0.4, -1);
	glVertex2f(0.65, -0.6);
	glVertex2f(0.65, -1);
	glVertex2f(0.35, -0.8);
	glVertex2f(1, -0.8);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(0.7, 0, 0);
	glVertex2f(-0.992, 0.2125);
	glVertex2f(0.317, 0.2125);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.45, -0.61, 0);
	glScalef(0.01, -0.01, 1);
	print_string(0, 0, sum, 0.7, 0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.67, -0.61, 0);
	glScalef(0.01, -0.01, 1);
	print_string(0, 0, sumin, 0.7, 0, 0);
	print_string(0, 10, school, 0.7, 0, 0);
	glPopMatrix();

	glPushMatrix();
	str1 = "1";
	strcpy_s(str, str1.c_str());
	glTranslatef(0.35, -0.83, 0);
	glScalef(0.009, -0.009, 1);
	print_string(0, 0, str, 0.7, 0, 0);
	glPopMatrix();

	glPushMatrix();
	str1 = "2";
	strcpy_s(str, str1.c_str());
	glTranslatef(0.35, -0.92, 0);
	glScalef(0.009, -0.009, 1);
	print_string(0, 0, str, 0.7, 0, 0);
	glPopMatrix();

	glPushMatrix();
	str1 = to_string(ScoreP1.x);
	strcpy_s(str, str1.c_str());
	glTranslatef(0.63, -0.83, 0);
	glScalef(0.009, -0.009, 1);
	for (int i = 0; i < str1.length(); i++)
	{
		glTranslatef(-6, 0, 0);
	}
	if (str1.length() >= 5)
	{
		glScalef(0.9, 0.9, 1);
		glTranslatef(7, 1, 0);
	}
	print_string(0, 0, str, 0.7, 0, 0);
	glPopMatrix();

	glPushMatrix();
	str1 = to_string(ScoreP1.y);
	strcpy_s(str, str1.c_str());
	glTranslatef(0.8, -0.83, 0);
	glScalef(0.009, -0.009, 1);
	for (int i = 0; i < str1.length(); i++)
	{
		glTranslatef(-3, 0, 0);
	}
	print_string(0, 0, str, 0.7, 0, 0);
	glPopMatrix();

	glPushMatrix();
	str1 = to_string(ScoreP2.x);
	strcpy_s(str, str1.c_str());
	glTranslatef(0.63, -0.92, 0);
	glScalef(0.009, -0.009, 1);
	for (int i = 0; i < str1.length(); i++)
	{
		glTranslatef(-6, 0, 0);
	}
	if (str1.length() >= 5)
	{
		glScalef(0.9, 0.9, 1);
		glTranslatef(7, 1, 0);
	}
	print_string(0, 0, str, 0.7, 0, 0);
	glPopMatrix();

	glPushMatrix();
	str1 = to_string(ScoreP2.y);
	strcpy_s(str, str1.c_str());
	glTranslatef(0.8, -0.92, 0);
	glScalef(0.009, -0.009, 1);
	for (int i = 0; i < str1.length(); i++)
	{
		glTranslatef(-3, 0, 0);
	}
	print_string(0, 0, str, 0.7, 0, 0);
	glPopMatrix();

	glPushMatrix();

	glTranslatef(-0.95, 0.8, 0);
	glScalef(0.009, -0.009, 1);
	for (int i = 1; i <= 6; i++)
	{
		str1 = to_string(i);
		strcpy_s(str, str1.c_str());
		print_string(0, 0, str, 0.7, 0, 0);
		glTranslatef(0, 11.3, 0);
	}

	str1 = "P";
	strcpy_s(str, str1.c_str());
	print_string(0, 0, str, 0.7, 0, 0);
	glTranslatef(0, 11.3, 0);

	str1 = "D";
	strcpy_s(str, str1.c_str());
	print_string(0, 0, str, 0.7, 0, 0);
	glTranslatef(0, 11.3, 0);

	str1 = "T";
	strcpy_s(str, str1.c_str());
	print_string(0, 0, str, 0.7, 0, 0);
	glTranslatef(0, 11.3, 0);

	str1 = "F";
	strcpy_s(str, str1.c_str());
	print_string(0, 0, str, 0.7, 0, 0);
	glTranslatef(0, 11.3, 0);

	str1 = "e";
	strcpy_s(str, str1.c_str());
	print_string(0, 0, str, 0.7, 0, 0);
	glTranslatef(0, 11.3, 0);

	str1 = "S";
	strcpy_s(str, str1.c_str());
	print_string(0, 0, str, 0.7, 0, 0);
	glTranslatef(0, 11.3, 0);

	str1 = "C";
	strcpy_s(str, str1.c_str());
	print_string(0, 0, str, 0.7, 0, 0);
	glTranslatef(0, 11.3, 0);

	str1 = "A";
	strcpy_s(str, str1.c_str());
	print_string(0, 0, str, 0.7, 0, 0);
	glTranslatef(-2, 11.3, 0);

	Print_Sum_symbol();
	glPushMatrix();
	glTranslatef(5, 0.4, 0);
	glScalef(0.4, 0.9, 1);
	str1 = "(+)";
	strcpy_s(str, str1.c_str());
	print_string(0, 0, str, 0.7, 0, 0);
	glPopMatrix();
	glTranslatef(0, 11.3, 0);

	str1 = "Pr";
	strcpy_s(str, str1.c_str());
	print_string(0, 0, str, 0.7, 0, 0);

	glPopMatrix();

	//glPushMatrix();
	//str1 = to_string(imove);
	//strcpy_s(str, str1.c_str());
	//glTranslatef(0.6, -0.35, 0);
	//glScalef(0.03, -0.03, 1);
	//print_string(0, 0, str, 0.7, 0, 0);
	//glPopMatrix();
}

void Grid::Print_Sum_symbol()
{
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0, 0);
	glVertex2f(4, 0);
	glVertex2f(4, 1);
	glVertex2f(0, 1);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0, 1);
	glVertex2f(1, 1);
	glVertex2f(3, 3);
	glVertex2f(3, 4);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(3, 3);
	glVertex2f(3, 4);
	glVertex2f(1, 6);
	glVertex2f(0, 6);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0, 6);
	glVertex2f(4, 6);
	glVertex2f(4, 7);
	glVertex2f(0, 7);
	glEnd();

	glPopMatrix();
}

void Grid::WriteGrid()
{
	WriteGreenGrid();
	WriteOrangeGrid();
	WriteSystemGrid();
}

Field* Grid::GetCell(int i, int j, bool team)
{
	return team ? &GreenTeam[i][j] : &OrangeTeam[i][j];
}