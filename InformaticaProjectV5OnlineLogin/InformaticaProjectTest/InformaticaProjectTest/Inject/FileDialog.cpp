#include "InjectHeader.h"

CFileDialog FD;

bool CFileDialog::OpenFileName() {
	OPENFILENAME ofn;
	char fileName[MAX_PATH] = "";
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
	ofn.lpstrFile = fileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = "";
	if (GetOpenFileName(&ofn)) {
		DLLName = fileName;
		return true;
	}
	else {
		return false;
	}
}

bool CFileDialog::GetDLLName() {
	if (!OpenFileName()) {
		return false;
	}
	return true;
}