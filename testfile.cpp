#include "logfile.h"

int main()
{
	LOG_E("hi error");
	LOG_R("hi run");
	LOG_I("hi info");
	LOG("hi log");
	LOG_D("hi debug");
	LOG_E("last");
	return 0;
}
