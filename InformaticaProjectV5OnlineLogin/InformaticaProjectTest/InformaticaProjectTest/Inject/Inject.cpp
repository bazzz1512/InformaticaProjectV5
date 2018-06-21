#include "InjectHeader.h"

CInject I;

bool CInject::GetAdress() {
	addr = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");
	if (addr == NULL) {
		return false;
	}
	return true;
}

bool CInject::AllocateMem(HANDLE process, string DLLName) {
	arg = (LPVOID)VirtualAllocEx(process, NULL, strlen(DLLName.c_str()) + 1, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (arg == NULL) {
		return false;
	}
	return true;
}

bool CInject::WriteArgument(HANDLE process, string DLLName) {
	int n = WriteProcessMemory(process, I.arg, DLLName.c_str(), strlen(DLLName.c_str()), NULL);
	if (n == false) {
		return false;
	}
	return true;
}

bool CInject::CreateThreadInProcess(HANDLE process) {
	HANDLE threadID = CreateRemoteThread(process, NULL, 0, (LPTHREAD_START_ROUTINE)I.addr, I.arg, NULL, NULL);
	if (threadID == NULL) {
		return false;
	}
	return true;
}

void CInject::Close() {
	CloseHandle(GH.hProcess);
	VirtualFreeEx(GH.hProcess, (LPVOID)I.arg, 0, MEM_RELEASE);
}

bool CInject::Inject(HANDLE process, string DLLName) {
	if (!(I.GetAdress())) {
		MessageBoxA(0, "LoadLibraryA not found inside kernel32.dll", "Error", MB_OK | MB_ICONERROR);
		return false;
	}
	if (!(I.AllocateMem(process,DLLName))) {
		MessageBoxA(0, "Memory can't be allocated", "Error", MB_OK | MB_ICONERROR);
		return false;
	}
	if (!(I.WriteArgument(process,DLLName))) {
		MessageBoxA(0, "Nothing written in LoadLibraryA", "Error", MB_OK | MB_ICONERROR);
		return false;
	}
	if (!(I.CreateThreadInProcess(process))) {
		MessageBoxA(0, "Failed to Create Remote Thread in the Process", "Error", MB_OK | MB_ICONERROR);
		return false;
	}
	return true;
}