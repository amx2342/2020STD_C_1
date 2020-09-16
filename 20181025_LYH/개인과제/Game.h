#pragma once
#include <iostream>
#include "Character.h"
using namespace std;


class Game
{
private:
	int round;
	int point_gauge;
	AI* ai;  // �ΰ����� , ��ü ������
	int cNum;
public:
	Game(): round(1), point_gauge(0), cNum(0)
	{}
	void Create_AI()
	{
		ai = new AI("AI");
	}
	
	// ����
	void Fight(Character& c)
	{
		if (c.Check_hp())
		{
			if (c.Get_ultimate() >= 100)
			{
				cout << "�ñر⸦ ����մϴ�." << endl;
				c.Ultimate(*ai); // �ѹ� ��
				point_gauge += 30;
			}
			else
			{
				c.Attack(*ai);
				point_gauge += 10;
			}
		}
		else
			cout << "ĳ���Ͱ� ����Ͽ� ����� �� �����ϴ�." << endl;
		if (ai->Get_hp() <= 0)
		{
			delete ai;
			Create_AI();
		}
	}

	// ���ݹ���
	void Suffer(Character& c)
	{
		if (c.Check_hp())
		{
			if (c.Get_ultimate() >= 100)
			{
				cout << "�ñر⸦ ����մϴ�." << endl;
				ai->Ultimate(c);
			}
			else
				ai->Attack(c);
		}
		else
			cout << "ĳ���Ͱ� ����Ͽ� ����� �� �����ϴ�." << endl;
	}

	// ������
	void Support(Character& c1, Character& c2)
	{
		if (c1.Check_hp())
		{
			if (c1.Get_ultimate() >= 100)
			{
				cout << "�ñر⸦ ����մϴ�." << endl;
				c1.Ultimate(c2);
				point_gauge += 30;
			}
			else
			{
				c1.Heal(c2);
				point_gauge += 10;
			}
		}
		else
			cout << "ĳ���Ͱ� ����Ͽ� ����� �� �����ϴ�." << endl;
	}

	void ShowData(void)
	{
		if (round < 4)
		{
			if (point_gauge < 100)
			{
				cout << "���� ���� �������� " << point_gauge << "%�Դϴ�." << endl << "���� ���带 �����մϴ�." << endl;
				round++;
			}
			else if (point_gauge >= 100)
				cout << "���� ���� ����! �¸��ϼ̽��ϴ�." << endl;
		}
		else
			cout << "���� ���� ����.. �й��Ͽ����ϴ�." << endl;
		
	}
};
