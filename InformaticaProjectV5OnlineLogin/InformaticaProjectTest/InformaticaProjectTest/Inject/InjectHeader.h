#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdio>
#include <tlhelp32.h>

//Don't show console
// #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace std;

class CFileDialog;
class CGetHandle;
class CInject;
class CGetProcessName;

class CFileDialog {
public:
	 bool GetDLLName();
	 string DLLName;
private:
	 bool OpenFileName();

};

class CGetProcessName {
public:
	bool GetNameOfProcess();
	string ProcessName;
private:

};

class CGetHandle {
public:
	bool GetHandleFromName(string name);
	HANDLE hProcess;
private:
	PROCESSENTRY32 entry;
	HANDLE snapshot;
	void EnableDebugPriv();
};

class CInject {
public:
	bool Inject(HANDLE process,string DLLName);
	void Close();
private:
	bool GetAdress();
	bool AllocateMem(HANDLE process, string DLLName);
	bool WriteArgument(HANDLE process, string DLLName);
	bool CreateThreadInProcess(HANDLE process);
	LPVOID addr;
	LPVOID arg;

};

extern CGetHandle GH;
extern CFileDialog FD;
extern CInject I;
extern CGetProcessName GPN;

