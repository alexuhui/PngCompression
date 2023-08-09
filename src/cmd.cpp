#include "cmd.h"

void cmdSystem(const std::string& cmdLine) {
	cout << "cmd : " << cmdLine << endl;
	system(cmdLine.c_str());
}