#include "Console.hpp"
#include "ezdef.hpp"
#include <string>

console ConsoleMessage(std::string message)
{
	show "Console:" spc message fin;
}