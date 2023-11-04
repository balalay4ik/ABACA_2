#include "NewGameController.h"
#include "GameController.h"

void NewGameController::Init(GameController* game)
{
	gameController = game;

	for (int i = 0; i < 5; i++)
	{
		Player1[i].num = 6;
		Player2[i].num = 6;
	}
}

void NewGameController::WriteDices()
{
	glPushMatrix();
	glScalef(0.2, 0.2, 1);
	glTranslatef(-1.5, 0.05, 0);

	for (int i = 0; i < 5; i++)
	{
		if (!Player1[i].invisible)
			Player1[i].Write();
		glTranslatef(0.6, 0, 0);
	}

	glPopMatrix();

	glPushMatrix();
	glScalef(0.2, 0.2, 1);
	glTranslatef(-1.5, -2.5, 0);

	for (int i = 0; i < 5; i++)
	{
		if (!Player2[i].invisible)
			Player2[i].Write();
		glTranslatef(0.6, 0, 0);
	}

	glPopMatrix();
}

void NewGameController::WriteInfo()
{
	glPushMatrix();
	glScalef(0.8, 0.5, 1);
	glTranslatef(-0.5, 1, 0);

	WriteFillSquare(0.7, 0, 0);

	glPopMatrix();

	glPushMatrix();
	glScalef(0.76, 0.43, 1);
	glTranslatef(-0.5, 1.245, 0);

	WriteFillSquare(0, 0, 0);

	glPopMatrix();

	glPushMatrix();
	glScalef(0.71, 0.395, 1);
	glTranslatef(-0.5, 1.39, 0);

	WriteFillSquare(0.7, 0.35, 0);

	glPopMatrix();

	glPushMatrix();
	glScalef(0.695, 0.2895, 1);
	glTranslatef(-0.5, 2.22, 0);

	WriteFillSquare(0, 0.7, 0);

	glPopMatrix();

	glPushMatrix();
	glScalef(1, -1, 0);
	glScalef(0.022, 0.025, 0);
	glTranslatef(-14, -35, 0);

	print_string(0, 0, "ABACA", 0.7, 0, 0);

	glPopMatrix();

	glPushMatrix();
	glScalef(1, -1, 0);
	glScalef(0.009, 0.009, 0);
	glTranslatef(-25, -70, 0);

	print_string(0, 0, "REMASTER", 0.7, 0, 0);

	glPopMatrix();




	if (iteration > 2)
	{
		S1 = 0;
		for (int i = 0; i < 5; i++)
		{
			S1 += Player1[i].num;
		}
		glPushMatrix();
		str1 = "= " + to_string(S1);
		strcpy_s(str, str1.c_str());
		glTranslatef(0.4, 0.14, 0);
		glScalef(0.011, -0.011, 1);
		print_string(0, 0, str, 0.7, 0, 0);
		glPopMatrix();
	}

	if (iteration > 3)
	{
		S2 = 0;
		for (int i = 0; i < 5; i++)
		{
			S2 += Player2[i].num;
		}
		glPushMatrix();
		str1 = "= " + to_string(S2);
		strcpy_s(str, str1.c_str());
		glTranslatef(0.4, -0.36, 0);
		glScalef(0.011, -0.011, 1);
		print_string(0, 0, str, 0.7, 0, 0);
		glPopMatrix();
	}

	glPushMatrix();
	str1 = FirstName;
	strcpy_s(str, str1.c_str());
	glTranslatef(-0.95, 0.33, 0);
	glScalef(0.009, -0.009, 1);
	print_string(0, 0, str, 0, 0.7, 0);
	glPopMatrix();

	if(iteration > 0)
	{
		glPushMatrix();
		str1 = SecondName;
		strcpy_s(str, str1.c_str());
		glTranslatef(-0.95, -0.2, 0);
		glScalef(0.009, -0.009, 1);
		print_string(0, 0, str, 0.7, 0.3, 0);
		glPopMatrix();
	}

	glPushMatrix();
	str1 = nameP1;
	strcpy_s(str, str1.c_str());
	glTranslatef(-0.41, 0.33, 0);
	glScalef(0.009, -0.009, 1);
	print_string(0, 0, str, 0, 0.7, 0);
	glPopMatrix();

	glPushMatrix();
	str1 = nameP2;
	strcpy_s(str, str1.c_str());
	glTranslatef(-0.3, -0.2, 0);
	glScalef(0.009, -0.009, 1);
	print_string(0, 0, str, 0.7, 0.3, 0);
	glPopMatrix();
}

void NewGameController::NewScore()
{
	iteration = 2;
}

void NewGameController::WriteAuthor()
{
	glPushMatrix();
	str1 = "by Sobolev Tymur";
	strcpy_s(str, str1.c_str());
	glTranslatef(0.5, -0.9, 0);
	glScalef(0.004, -0.004, 1);
	print_string(0, 0, str, 0.7, 0, 0);
	glPopMatrix();
}

void NewGameController::Button(WPARAM wParam)
{
	SHORT shiftState = GetKeyState(VK_SHIFT);
	SHORT capsLockState = GetKeyState(VK_CAPITAL);

	if (wParam == VK_RETURN)
	{
		iteration++;
		if (iteration > 4)
			if (S1 == S2) { NewScore(); }
			else
			{
				if (S1 > S2)
					gameController->InitNewGame(nameP1, nameP2);
				else
					gameController->InitNewGame(nameP2, nameP1);
			}
	}
	if (wParam == VK_SPACE)
	{
		if (iteration > 1)
		{
			iteration++;
			if (iteration > 4)
				if (S1 == S2) { NewScore(); }
				else
				{
					if (S1 > S2)
						gameController->InitNewGame(nameP1, nameP2);
					else
						gameController->InitNewGame(nameP2, nameP1);
				}
		}
	}

	if (GetKeyState(wParam) < 0)
	{

		if (wParam == VK_BACK)
		{
			if (iteration == 0)
			{
				if (nameP1.length() > 0)
					nameP1.pop_back();
			}
			else if (iteration == 1)
			{
				if (nameP2.length() > 0)
					nameP2.pop_back();
			}
		}
		else if (wParam >= 'A' && wParam <= 'Z') 
		{
			if ((shiftState & 0x8000) || (capsLockState & 1))
			{
				if (iteration == 0)
				{
					if (nameP1.length() < limitSymbol)
						nameP1 += wParam;
				}
				else if (iteration == 1)
				{
					if (nameP2.length() < limitSymbol)
						nameP2 += wParam;
				}
			}
			else
			{
				if (iteration == 0)
				{
					if (nameP1.length() < limitSymbol)
						nameP1 += std::tolower(static_cast<char>(wParam));
				}
				else if (iteration == 1)
				{
					if (nameP2.length() < limitSymbol)
						nameP2 += std::tolower(static_cast<char>(wParam));
				}
			}
		}
		else if (wParam != VK_RETURN && wParam != VK_SHIFT && wParam != VK_CAPITAL)
		{
			if (iteration == 0)
			{
				if (nameP1.length() < limitSymbol)
					nameP1 += wParam;
			}
			else if (iteration == 1)
			{
				if (nameP2.length() < limitSymbol)
					nameP2 += wParam;
			}
		}


	}

}

void NewGameController::Update()
{
	if (iteration > 1)
		for (int i = 0; i < 5; i++)
		{
			if (iteration == 2)
				Player1[i].num = rand() % 6 + 1;
			else if (iteration == 3)
				Player2[i].num = rand() % 6 + 1;
		}

	WriteDices();
	WriteInfo();
	WriteAuthor();

}

void NewGameController::WriteFillSquare(float r, float g, float b)
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(r, g, b);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 1);
	glVertex2f(0, 1);
	glEnd();
}