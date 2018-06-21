#include "InjectHeader.h"

CGetProcessName GPN;

bool CGetProcessName::GetNameOfProcess() {
	cout << "Input process name: ";
	cin >> /*this->*/ProcessName;
	return true;
}

