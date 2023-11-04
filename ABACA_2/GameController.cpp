#include "GameController.h"

GameController save;

void GameController::WriteDices()
{
	glPushMatrix();
	glScalef(0.2, 0.2, 1);
	glTranslatef(3.1, 3, 0);
	dice1.invisible = false;
	dice1.num = 1;
	dice1.Write();
	glPopMatrix();


	glPushMatrix();
	glScalef(0.2, 0.2, 1);
	glTranslatef(1.9, -1.5, 0);

	for (int i = 0; i < 5; i++)
	{
		if (!dice[i].invisible)
			dice[i].Write();
		glTranslatef(0.6, 0, 0);
	}

	glTranslatef(-3, 3, 0);
	for (int i = 0; i < 5; i++)
	{
		if (dice[i].invisible)
			dice[i].Write();
		glTranslatef(0.6, 0, 0);
	}

	glPopMatrix();

	glPushMatrix();
	glScalef(0.64, 0.255, 1);

	glTranslatef(0.55, 1, 0);

	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.7, 0, 0);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 1);
	glVertex2f(0, 1);
	glEnd();

	glPopMatrix();
}

void GameController::WriteStep()
{
	glPushMatrix();
	str1 = to_string(step);
	strcpy_s(str, str1.c_str());
	glTranslatef(0.6, -0.35, 0);
	glScalef(0.03, -0.03, 1);
	print_string(0, 0, str, 0.7, 0, 0);
	glPopMatrix();
}

void GameController::Update()
{
	if (newGame == false)
	{
		if (!CheckEndGame())
		{
			if (randomized)
				for (int i = 0; i < 5; i++)
				{
					if (!dice[i].invisible)
					{
						dice[i].num = rand() % 6 + 1;
					}
				}
		}
		else
		{

		}

		grid.WriteGrid();
		WriteDices();
		WriteStep();

		if (!CheckEndGame())
			WriteTeamStep();
		else
			WriteScore();

		WriteName();
	}
	else
	{
		newGames->Update();
	}

}

void GameController::Init()
{
	newGames->Init(this);
}

void GameController::NextDice(int d)
{
	if (CheckEndGame()) return;

	dice[hold].holdet = false;

	hold += d;

	if (hold == -1) hold = 4;
	else if (hold == 5) hold = 0;

	dice[hold].holdet = true;
}

bool GameController::Buttons()
{
	if (newGame) return false;
	if (CheckEndGame()) return false;
	for (int i = 0; i < 6; i++) scoreDice[i] = 0;
	for (int i = 0; i < 5; i++)
	{
		if (dice[i].num == 0) continue;
		scoreDice[dice[i].num - 1]++;
	}

	bool f = false;

	if (GetKeyState('1') < 0) f = SchoolLogic(1);
	else if (GetKeyState('2') < 0) f = SchoolLogic(2);
	else if (GetKeyState('3') < 0) f = SchoolLogic(3);
	else if (GetKeyState('4') < 0) f = SchoolLogic(4);
	else if (GetKeyState('5') < 0) f = SchoolLogic(5);
	else if (GetKeyState('6') < 0) f = SchoolLogic(6);
	else if (GetKeyState('P') < 0) f = ComboLogic(7);
	else if (GetKeyState('D') < 0) f = ComboLogic(8);
	else if (GetKeyState('T') < 0) f = ComboLogic(9);
	else if (GetKeyState('F') < 0) f = ComboLogic(10);
	else if (GetKeyState('E') < 0) f = ComboLogic(11);
	else if (GetKeyState('S') < 0) f = ComboLogic(12);
	else if (GetKeyState('C') < 0) f = ComboLogic(13);
	else if (GetKeyState('A') < 0) f = ComboLogic(14);
	else if (GetKeyState(VK_ADD) < 0) f = ComboLogic(15);
	else if (GetKeyState('J') < 0) Cheat();
	else return f;

	if (f) dice[hold].holdet = !dice[hold].holdet;

	return f;
}

bool GameController::SchoolLogic(int cell)
{

	int col = 5;
	if (scoreDice[cell - 1] >= 3) col = FillCells(cell - 1, (scoreDice[cell - 1] - 3) * cell);
	else
	{
		int y = grid.GetScorePlayer(GreenStep)->y;
		if (y != 0 && scoreDice[cell - 1] >= 1 && abs(scoreDice[cell - 1] - 3) * cell <= y)
		{
			col = FillCells(cell - 1, (scoreDice[cell - 1] - 3) * cell);
			FillCell(grid.GetCell(cell - 1, 5, GreenStep), 0);
		}
		else if (GreenStep ? (fillCells[0] <= 0) : (fillCells[1] <= 0))
		{
			int score = 0;
			score = (scoreDice[cell - 1] - 3) * cell;

			col = FillCells(cell - 1, score, true);
			FillCell(grid.GetCell(cell - 1, 5, GreenStep), 0);
		}
		else return false;
	}
	if (col == 5) return false;

	GreenStep ? fillShool[0]-- : fillShool[1]--;


	if (grid.GetCell(cell - 1, 4, GreenStep)->GetHoldet())
	{
		//if (!grid.GetCell(cell - 1, 5, GreenStep)->GetHoldet())
		//{
		FillCell(grid.GetCell(cell - 1, 5, GreenStep), cell * 5);
		FillCell(grid.GetCell(cell - 1, 5, !GreenStep), 0);
		//}
	}

	int score = 0;
	for (int i = 0; i < 15; i++)
	{
		Field* Cell = grid.GetCell(i, col, GreenStep);
		if (!Cell->GetHoldet()) return true;
		if (i >= 7)
			if (Cell->GetScore() > score) score = Cell->GetScore();
	}

	//if (!grid.GetCell(15, col, GreenStep)->GetHoldet())
	//{
	FillCell(grid.GetCell(15, col, GreenStep), score);
	FillCell(grid.GetCell(15, col, !GreenStep), 0);
	//}

	return true;
}

bool GameController::ComboLogic(int cell)
{
	int score = 0;
	if (cell == 7)
	{
		for (int i = 5; i >= 0; i--)
		{
			if (scoreDice[i] >= 2)
			{
				score = (i + 1) * 2;
				break;
			}
		}
	}
	else if (cell == 8)
	{
		int Double = 0;
		for (int i = 0; i < 6; i++)
		{
			if (scoreDice[i] >= 2)
			{
				Double++;
				if (scoreDice[i] >= 4)
				{
					Double++;
					score += (i + 1) * 4;
				}
				else score += (i + 1) * 2;
			}
		}

		if (Double != 2)
		{
			score = 0;
		}
	}
	else if (cell == 9)
		for (int i = 0; i < 6; i++)
		{
			if (scoreDice[i] >= 3)
				score += (i + 1) * 3;
		}
	else if (cell == 10)
	{
		bool F = false;
		bool F1 = false;
		for (int i = 0; i < 6; i++)
		{
			if (scoreDice[i] >= 5)
			{
				F1 = true;
				F = true;
				score += (i + 1) * 5;
			}
			else if (scoreDice[i] >= 3)
			{
				F = true;
				score += (i + 1) * 3;
			}
			else if (scoreDice[i] >= 2)
			{
				F1 = true;
				score += (i + 1) * 2;
			}

		}

		if (!F || !F1)
		{
			score = 0;
		}
	}
	else if (cell == 11)
	{
		bool E = true;;
		for (int i = 0; i < 5; i++)
		{
			if (scoreDice[i] < 1)
			{
				E = false;
				break;
			}
		}

		if (E)
		{
			score = 15;
		}
	}
	else if (cell == 12)
	{
		bool S = true;;
		for (int i = 1; i < 6; i++)
		{
			if (scoreDice[i] < 1)
			{
				S = false;
				break;
			}
		}

		if (S)
		{
			score = 20;
		}
	}
	else if (cell == 13)
		for (int i = 0; i < 6; i++)
		{
			if (scoreDice[i] >= 4)
				score = 20 + (i + 1) * 4;
		}
	else if (cell == 14)
		for (int i = 0; i < 6; i++)
		{
			if (scoreDice[i] == 5)
				score = 50 + (i + 1) * 5;
		}
	else if (cell == 15)
	{
		for (int i = 0; i < 5; i++)
		{
			score += dice[i].num;
		}
	}

	if (step == 1) { score *= 2; }

	int col = FillCells(cell - 1, score);

	if (col == 5) return false;

	GreenStep ? fillCells[0]-- : fillCells[1]--;

	if (score == 0)
	{
		FillCell(grid.GetCell(cell - 1, 5, GreenStep), score);
		FillCell(grid.GetCell(15, col, GreenStep), score);
	}

	score = 0;
	if (grid.GetCell(cell - 1, 4, GreenStep)->GetHoldet())
	{
		for (int i = 0; i < 5; i++)
		{
			int CellScore = grid.GetCell(cell - 1, i, GreenStep)->GetScore();
			if (CellScore > score) score = CellScore;
		}

		FillCell(grid.GetCell(cell - 1, 5, GreenStep), score);
		FillCell(grid.GetCell(cell - 1, 5, !GreenStep), 0);
	}

	score = 0;

	for (int i = 0; i < 15; i++)
	{
		Field* Cell = grid.GetCell(i, col, GreenStep);
		if (!Cell->GetHoldet()) return true;
		if (i >= 7)
			if (Cell->GetScore() > score) score = Cell->GetScore();
	}

	//if (!grid.GetCell(15, col, GreenStep)->GetHoldet())
	//{
	FillCell(grid.GetCell(15, col, GreenStep), score);
	FillCell(grid.GetCell(15, col, !GreenStep), 0);
	//}

	return true;
}

int GameController::FillCells(int cell, int score, bool type)
{
	//if (grid.GetCell(cell, 5, GreenStep)->GetHoldet())
	//	return 5;

	for (int i = 0; i < 6; i++)
	{
		Field* Cell = grid.GetCell(cell, i, GreenStep);
		if (!Cell->GetHoldet())
		{
			FillCell(Cell, score, type);
			return i;
		}
		if (i == 5 && Cell->GetHoldet()) return i;
	}
}

void GameController::FillCell(Field* cell, int score, bool type)
{
	if (!cell->GetHoldet())
	{
		cell->SetScore(score);
		CalulateScore(cell, type);
	}
}

void GameController::CalulateScore(Field* cell, bool type)
{
	Vector2* PlayerScore = grid.GetScorePlayer(GreenStep);
	int score = cell->GetScore();
	Vector2 coord = cell->GetCoord();

	if (coord.y <= 5 && coord.x <= 4)
	{
		if (GreenStep ? (fillCells[0] <= 0) : (fillCells[1] <= 0))
		{
			if (score < 0 && PlayerScore->y >= 0 && PlayerScore->y + score < 0) PlayerScore->x += (PlayerScore->y + score) * 100;
			else if (score < 0 && PlayerScore->y < 0 && PlayerScore->y + score < 0) PlayerScore->x += score * 100;
			else if (score > 0 && PlayerScore->y < 0 && PlayerScore->y + score < 0) PlayerScore->x += score * 100;
			else if (score > 0 && PlayerScore->y < 0 && PlayerScore->y + score >= 0) PlayerScore->x += abs(PlayerScore->y) * 100;

		}

		PlayerScore->y += score;

		if (score > 0) PlayerScore->x += score;
	}
	else
		PlayerScore->x += score;
}

void GameController::ToggleTeam()
{
	GreenStep = !GreenStep;
	randomized = !randomized;
	for (int i = 0; i < 5; i++) dice[i].invisible = false;
	step = 0;
	hold = 0;
}

void GameController::SaveStep(GameController* other)
{
	other->grid = this->grid;
	for (int i = 0; i < 5; i++) other->dice[i] = this->dice[i];
	other->GreenStep = this->GreenStep;
	other->randomized = this->randomized;
	other->step = this->step;
	other->hold = this->hold;
	other->fillCells[0] = this->fillCells[0];
	other->fillShool[0] = this->fillShool[0];
	other->fillCells[1] = this->fillCells[1];
	other->fillShool[1] = this->fillShool[1];
}

void GameController::LoadStep()
{
	if (!save.CheckRandom())
		LoadStep(&save);
}

void GameController::LoadStep(const GameController* other)
{
	this->grid = other->grid;
	for (int i = 0; i < 5; i++) this->dice[i] = other->dice[i];
	this->GreenStep = other->GreenStep;
	this->randomized = other->randomized;
	this->step = other->step;
	this->hold = other->hold;
	this->fillCells[0] = other->fillCells[0];
	this->fillShool[0] = other->fillShool[0];
	this->fillCells[1] = other->fillCells[1];
	this->fillShool[1] = other->fillShool[1];
}

void GameController::ToggleRandom()
{
	randomized = !randomized;
	dice[hold].holdet = !dice[hold].holdet;

}

void GameController::Step()
{
	step++;
	if (step == maxStep) step = 0;

	if (!randomized) SaveStep(&save);
}

void GameController::WriteTeamStep()
{
	glPushMatrix();
	glScalef(0.465, 0.1, 1);
	glTranslatef(-1.86, -9.4, 0);

	if (!GreenStep)
		glTranslatef(1.265, 0, 0);

	WriteFillSquare(0.7, 0, 0);

	glPopMatrix();
}

void GameController::WriteName()
{
	glPushMatrix();
	glTranslatef(-0.865, 0.84, 0);
	glScalef(0.06, 0.085, 1);
	glScalef(nameP1.length(), 1, 1);
	WriteFillSquare(0, 0.7, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.265, 0.84, 0);
	glScalef(0.06, 0.085, 1);
	glScalef(nameP2.length(), 1, 1);
	WriteFillSquare(0.7, 0.3, 0);
	glPopMatrix();

	glPushMatrix();
	str1 = nameP1;
	strcpy_s(str, str1.c_str());
	glTranslatef(-0.86, 0.92, 0);
	glScalef(0.009, -0.009, 1);
	print_string(0, 0, str, 0.7, 0, 0);
	glPopMatrix();

	glPushMatrix();
	str1 = nameP2;
	strcpy_s(str, str1.c_str());
	glTranslatef(-0.26, 0.92, 0);
	glScalef(0.009, -0.009, 1);
	print_string(0, 0, str, 0.7, 0, 0);
	glPopMatrix();
}

void GameController::WriteScore()
{
	glPushMatrix();
	int sp1 = grid.GetScorePlayer(true)->x;
	int sp2 = grid.GetScorePlayer(false)->x;
	int SumScore = abs(sp1 - sp2);

	str1 = "Score:" + to_string(sp1 > sp2 ? sp1 : sp2) + "-" + to_string(sp1 > sp2 ? sp2 : sp1) + "=" + to_string(SumScore);
	strcpy_s(str, str1.c_str());
	glTranslatef(-0.9, -0.87, 0);
	glScalef(0.01, -0.01, 1);
	print_string(0, 0, str, 0.7, 0, 0);
	glPopMatrix();
}

void GameController::Cheat()
{

}

void GameController::InitNewGame(string nameP1, string nameP2)
{
	this->nameP1 = nameP1;
	this->nameP2 = nameP2;
	this->newGame = false;
}

void GameController::WriteFillSquare(float r, float g, float b)
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(r, g, b);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 1);
	glVertex2f(0, 1);
	glEnd();
}