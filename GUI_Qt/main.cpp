#include "8playerApp.h"
#include <vld.h>

int main(int argc, char *argv[])
{
	eightPlayerApp app(argc, argv);

	int exec = app.exec();

	return exec;
}
