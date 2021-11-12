#include "Console.hpp"
#include <conio.h>

void Console(string message)
{
	show "Console: " + message __;
}
void Console(string message, int n1)
{
	show "Console:" spc message spc n1 __;
}
void Console(string message, double d1)
{
	show "Console:" spc message spc d1 __;
}
void Console(string message, bool b1)
{
	show "Console:" spc message spc "is" spc b1 __;
}

void exitError(string message)
{

	show "Exiting:" spc message __;
	_getch();
	exit(-1);
}