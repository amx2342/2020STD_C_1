#include <iostream>
#include "Game.h"
using namespace std;

int main(void)
{
	Game game;

	// ���� ����
	Diva diva;
	Tracer tracer;
	Ana ana;

	// �ΰ����� ����
	game.Create_AI();
	cout << endl;
	
	// 1����
	game.Fight(diva);
	game.Suffer(diva);
	game.Support(ana, diva);
	game.ShowData(); // ���� ����
	cout << endl;

	// 2����
	game.Fight(tracer);
	game.Fight(diva);
	game.Suffer(tracer);
	game.Support(ana, tracer);
	game.Fight(diva);
	game.ShowData();
	cout << endl;

	// 3����
	game.Fight(diva);
	game.Fight(tracer);
	game.Suffer(tracer);
	game.Suffer(diva);
	game.Support(ana, diva);
	game.Support(ana, tracer);
	game.Fight(diva);
	game.ShowData();

	return 0;
}