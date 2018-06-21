#pragma once

#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include "ImGui\imgui.h"
#include "ImGui\imgui_impl_dx9.h"
#include <d3d9.h>
#include <string>
#include "Online.h"
#include "md5.h"
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "dwmapi.lib")

using namespace std;

class ImGuiNeeds {
public:
	int iPageNumber = 1;
	string DLLPath32;
	string DLLPath64;
};

void eraseAllSubStr(std::string & mainStr, const std::string & toErase)
{
	size_t pos = std::string::npos;

	// Search for the substring in string in a loop untill nothing is found
	while ((pos = mainStr.find(toErase)) != std::string::npos)
	{
		// If found then erase it from string
		mainStr.erase(pos, toErase.length());
	}
}

extern ImGuiNeeds CImGuiNeeds;
