#include "Dice.h"

void Dice::WriteSquare()
{
	glPushMatrix();
	glScalef(0.025, 0.025, 1);
	glScalef(0.6125, 1, 1);

	if (!holdet)
		glColor3f(0, 0.7, 0);
	else
		glColor3f(0.7, 0.3, 0);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(4, 0);
	glVertex2f(30, 0);
	glVertex2f(30, 2);
	glVertex2f(4, 2);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(4, 32);
	glVertex2f(30, 32);
	glVertex2f(30, 34);
	glVertex2f(4, 34);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0, 4);
	glVertex2f(0, 30);
	glVertex2f(2, 30);
	glVertex2f(2, 4);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(32, 4);
	glVertex2f(32, 30);
	glVertex2f(34, 30);
	glVertex2f(34, 4);
	glEnd();

	if (!holdet)
		glColor3f(0.7, 0.3, 0);
	else
		glColor3f(0, 0.7, 0);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(2, 2);
	glVertex2f(32, 2);
	glVertex2f(32, 32);
	glVertex2f(2, 32);
	glEnd();


	if (!holdet)
		glColor3f(0, 0.7, 0);
	else
		glColor3f(0.7, 0.3, 0);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(2, 2);
	glVertex2f(4, 2);
	glVertex2f(4, 4);
	glVertex2f(2, 4);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(32, 32);
	glVertex2f(30, 32);
	glVertex2f(30, 30);
	glVertex2f(32, 30);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(2, 32);
	glVertex2f(4, 32);
	glVertex2f(4, 30);
	glVertex2f(2, 30);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(32, 2);
	glVertex2f(32, 4);
	glVertex2f(30, 4);
	glVertex2f(30, 2);
	glEnd();

	glPopMatrix();
}

void Dice::WriteCross()
{
	glPushMatrix();
	glScalef(0.025, 0.025, 1);
	glScalef(0.6125, 1, 1);
	glColor3f(0.6, 0, 0);

	switch (num)
	{
	case 1:
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		break;

	case 2:
		glPushMatrix();
		glTranslatef(8, 8, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-8, -8, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();
		break;

	case 3:
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();

		glPushMatrix();
		glTranslatef(8, 8, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-8, -8, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();
		break;

	case 4:
		glPushMatrix();
		glTranslatef(8, 8, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-8, -8, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-8, 8, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(8, -8, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();
		break;

	case 5:
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();

		glPushMatrix();
		glTranslatef(8, 8, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-8, -8, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-8, 8, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(8, -8, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();
		break;

	case 6:
		glPushMatrix();
		glTranslatef(8, 8, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-8, -8, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-8, 8, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(8, -8, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-8, 0, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(8, 0, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(16, 14);
		glVertex2f(18, 14);
		glVertex2f(18, 20);
		glVertex2f(16, 20);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(14, 16);
		glVertex2f(14, 18);
		glVertex2f(20, 18);
		glVertex2f(20, 16);
		glEnd();
		glPopMatrix();
		break;

	}

	glPopMatrix();
}

void Dice::Write()
{
	WriteSquare();
	WriteCross();
}