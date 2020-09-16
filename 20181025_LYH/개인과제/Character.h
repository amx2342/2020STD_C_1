#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Character
{
private:
	char* name;
	int hp;  // ü��
	int cp;  // ���ݷ�
protected:
	int ultimate;  // �ñر�
public:
	Character(const char* c_name, int h, int c) : hp(h), cp(c), ultimate(0)
	{
		name = new char[strlen(c_name) + 1];
		strcpy(name, c_name);
	}
	virtual int Get_ultimate(void)
	{
		return ultimate;
	}
	virtual int Get_hp(void)
	{
		return hp;
	}
	virtual bool Check_hp(void)
	{
		if (hp <= 0)
			return 0;
		else
			return 1;
	}
	virtual void Attack(Character& c)
	{
		cout << "[" << name << "] -> ";
		c.Hurt(cp);
		ultimate += 20;
	}
	virtual void Hurt(int n)
	{
		hp -= n;
		if (hp <= 0)
			cout << "[" << name << "] KILL!" << endl;
		else
			cout << "[" << name << "]" << endl;
	}
	virtual void Heal(Character& c)
	{
		c.Recovery(cp);
	}
	virtual void Recovery(int n)
	{
		hp += n;
		ultimate += 10;
	}
	virtual void Buff(int n)
	{
		cp += n;
	}
	virtual void Ultimate(Character& team) = 0; // ���� ���� �Լ�
};

class Diva : public Character
{
public:
	Diva() : Character("DIVA", 300, 50)
	{
		cout << "DIVA ����" << endl << "������ �ϸ� �̰ܾ���!" << endl;
	}
	virtual void Ultimate(Character& enemy)  // �Լ� �������̵�
	{
		cout << "[DIVA] �̰͵� �����غ�����! -> ";
		enemy.Hurt(200);
		ultimate = 0;
	}
};

class Orisa : public Character
{
public:
	Orisa() : Character("ORISA", 300, 50)
	{
		cout << "ORISA ����" << endl << "�������� �����̾߸��� �� �ǹ��Դϴ�." << endl;
	}
	virtual void Ultimate(Character& enemy)
	{
		cout << "[ORISA] ������ ���߽ʽÿ�! -> ";
		enemy.Hurt(200);
		ultimate = 0;
	}
};

class Genji : public Character
{
public:
	Genji() : Character("GENJI", 150, 80)
	{
		cout << "GENJI ����" << endl << "������ �Բ� �Ѵ�." << endl;
	}
	virtual void Ultimate(Character& enemy)
	{
		cout << "[GENJI] ���� ���� �ȴ�! -> ";
		enemy.Hurt(300);
		ultimate = 0;
	}
};

class Tracer : public Character
{
public:
	Tracer() : Character("TRACER", 120, 60)
	{
		cout << "TRACER ����" << endl << "�ȳ� ģ����? �ذ�簡 �Ծ�!" << endl;
	}
	virtual void Ultimate(Character& enemy)
	{
		cout << "[TRACER] ��ź ����! -> ";
		enemy.Hurt(250);
		ultimate = 0;
	}
};

class Ana : public Character
{
public:
	Ana() : Character("ANA", 150, 50)
	{
		cout << "ANA ����" << endl << "�ų��� ���� �ο��� ������ ����." << endl;
	}
	virtual void Ultimate(Character& team)
	{
		cout << "[ANA] �� ��������, ������!" << endl;
		team.Buff(50);
		ultimate = 0;
	}
};

class Mercy : public Character
{
public:
	Mercy() : Character("MERCY", 150, 40)
	{
		cout << "MERCY ����" << endl << "���� �������� �����ھ��. " << endl;
	}
	virtual void Ultimate(Character& team)
	{
		cout << "[MERCY] ������ ���� �ʾƿ�!" << endl;
		team.Recovery(100);
		ultimate = 0;
	}
};

class AI : public Character
{
public:
	AI(const char* name) : Character(name, 200, 50)
	{}
	virtual void Ultimate(Character& enemy)
	{
		cout << "�ΰ� �ô��� ���� �����ߴ�" << endl;
		enemy.Hurt(100);
		ultimate = 0;
	}
};