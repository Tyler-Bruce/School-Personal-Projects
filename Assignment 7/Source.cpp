#include "account.h"
#include "manager.h"

int main() try
{
	Manager manager;
	manager.process();
	return 0;
}
catch (std::runtime_error& e)
{
	std::cerr << e.what();
	return 1;
}
