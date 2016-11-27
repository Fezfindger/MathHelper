#include "stdafx.h" 
#include <iostream> 
#include <cmath> 
#include <string> 
#include "Equation.h"
#include "HTMLtags.h" 
#include <windows.h>

#define UP_ARROW 72
#define LEFT_ARROW 75
#define DOWN_ARROW 80
#define RIGHT_ARROW 77

using namespace std;

HANDLE hConsole;

void gotoxy(int x, int y)
{
	COORD cursorLoc;
	cursorLoc.X = x;
	cursorLoc.Y = y;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, cursorLoc);
}

void MENU()
{
	system("CLS");
	gotoxy(10, 0);
	cout << "MathHelper";
	gotoxy(1, 1);
	cout << "Solve Equation";
	gotoxy(1, 2);
	cout << "MATRIX";
	gotoxy(1, 3);
	cout << "HTML-tags test";
	gotoxy(1, 4);
	cout << "EXIT";
	int i = 1;
	int KeyStroke;
	gotoxy(0, i);
	cout << '>';
	do
	{
		KeyStroke = _gettch();
		gotoxy(0, i);
		cout << ' ';
		switch (KeyStroke)
		{
		case UP_ARROW:
			if (i == 1)
				i = 4;
			else
				i--;
			break;
		case DOWN_ARROW:
			if (i == 4)
				i = 1;
			else
				i++;
			break;
		}
		gotoxy(0, i);
		cout << '>';
	} while (KeyStroke != VK_RETURN);
	string urov,adres;
	system("cls");
	switch (i)
	{
	case 1:
		setlocale(LC_ALL, "Russian");
		cout << "������� ��������� 1-3 �������\n� ������� f(x)=0 (���������� ��� ����� ��������� ����� ���� \"=\")\n";
		cin >> urov;
		CoofAndResh(urov);
		cout << endl << "������� ������ ��� ������� ���������� ���������." << endl;
		cout << "������� ����� ������ ������� ��� �������� � ����." << endl;
		while (_gettch() == ' ') {
			cout << "������� ���������:";
			cin >> urov;
			CoofAndResh(urov);
		}
		
		break;
	case 2:
		cout << "������� ����� ����� � �����: ";
		cin >> adres;
		TagsTest(adres);
		break;
	case 3:

		break;
	case 4:
		exit(0);
	}
	MENU();
}

int main()
{
	MENU();
	return 0;
}
