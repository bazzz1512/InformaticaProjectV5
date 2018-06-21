#include "Header.h"
#include "Inject\InjectHeader.h"
#include <urlmon.h>
#include <stdio.h>
#include <curl/curl.h>
#pragma comment(lib, "urlmon.lib")


static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
extern void eraseAllSubStr(std::string & mainStr, const std::string & toErase);
WNDCLASS CreateWindowClass(HINSTANCE hInstance);
ImGuiNeeds CImGuiNeeds;
Online COnline;


LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			g_d3dpp.BackBufferWidth = LOWORD(lParam);
			g_d3dpp.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
			if (hr == D3DERR_INVALIDCALL)
				IM_ASSERT(0);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wcWnd = CreateWindowClass(hInstance);
	if (!RegisterClass(&wcWnd)) // Improve MessageBox
	{
		MessageBox(NULL,
			"Call to RegisterClass failed!",
			"Informatica Error",
			MB_OK);

		return TRUE;
	}

	RECT screen_rect;
	GetWindowRect(GetDesktopWindow(), &screen_rect); // разрешение экрана
	int x = screen_rect.right / 2 - 200;
	int y = screen_rect.bottom / 2 - 200;
	
	HWND hWnd = CreateWindow("Informatica", "Informatica", WS_POPUP, x, y, 400, 400, NULL, NULL, hInstance, NULL);

	// Initialize Direct3D
	LPDIRECT3D9 pD3D;
	if ((pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
	{
		UnregisterClass(_T("Informatica"), hInstance);
		return 0;
	}
	ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
	g_d3dpp.Windowed = TRUE;
	g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	g_d3dpp.EnableAutoDepthStencil = TRUE;
	g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE; // Present with vsync
	//g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE; // Present without vsync, maximum unthrottled framerate

	// Create the D3DDevice
	if (pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
	{
		pD3D->Release();
		UnregisterClass(_T("Informatica"), hInstance);
		return 0;
	}

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
	ImGui_ImplDX9_Init(hWnd, g_pd3dDevice);

	ImGuiStyle& style = ImGui::GetStyle();
	ImFont* font = ImGui::GetFont();


	style.FramePadding = ImVec2(4, 2);
	style.ItemSpacing = ImVec2(6, 2);
	style.ItemInnerSpacing = ImVec2(6, 4);
	style.WindowRounding = 4.0f;
	style.WindowTitleAlign = ImVec2(0.5, 0.5);
	style.FrameRounding = 2.0f;
	style.IndentSpacing = 6.0f;
	style.ItemInnerSpacing = ImVec2(2, 4);
	style.ColumnsMinSpacing = 50.0f;
	style.GrabMinSize = 14.0f;
	style.GrabRounding = 16.0f;
	style.ScrollbarSize = 12.0f;
	style.ScrollbarRounding = 16.0f;
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f); 

	static int hue = 140;
	static float col_main_sat = 180.f / 255.f;
	static float col_main_val = 161.f / 255.f;
	static float col_area_sat = 124.f / 255.f;
	static float col_area_val = 100.f / 255.f;
	static float col_back_sat = 59.f / 255.f;
	static float col_back_val = 40.f / 255.f;

	ImVec4 col_text = ImColor::HSV(hue / 255.f, 20.f / 255.f, 235.f / 255.f);
	ImVec4 col_main = ImColor::HSV(hue / 255.f, col_main_sat, col_main_val);
	ImVec4 col_back = ImColor::HSV(hue / 255.f, col_back_sat, col_back_val);
	ImVec4 col_area = ImColor::HSV(hue / 255.f, col_area_sat, col_area_val);

	style.Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
//	style.Colors[ImGuiCol_ComboBg] = ImVec4(0.19f, 0.18f, 0.21f, 1.00f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.1f, 0.90f, 1.f, 0.31f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style.Colors[ImGuiCol_Column] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_ColumnActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
//	style.Colors[ImGuiCol_CloseButton] = ImVec4(0.40f, 0.39f, 0.38f, 0.16f);
//	style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.40f, 0.39f, 0.38f, 0.39f);
//	style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(0.40f, 0.39f, 0.38f, 1.00f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);

	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
	while (msg.message != WM_QUIT)
	{
		// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
		// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
		// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
		// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}
		ImGui_ImplDX9_NewFrame();

		DWORD dwFlag = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse;

		static bool open = true;

		if (!open)
			ExitProcess(0);

		ImGui::Begin("Informatica", &open, ImVec2(400, 400), 1.0f, dwFlag);
		{
			if (CImGuiNeeds.iPageNumber == 1) {
				ImGui::Text("Offline");
				static char Username[128] = "";
				static char Password[128] = "";
				ImGui::Text("Username:");
				ImGui::SameLine();
				ImGui::InputText(("##Username"), Username, 128);
				ImGui::Text("Password:");
				ImGui::SameLine();
				ImGui::InputText(("##Password"), Password, 128);

				if (ImGui::Button("Login")) {
					if (string(Username) == "Sebas" && string(Password) == "Dank") {
						CImGuiNeeds.iPageNumber = 2;
					}
				}

				// Online version
				ImGui::Text("\nOnline");
				static char OnlineUsername[128] = "";
				static char OnlinePassword[128] = "";
				ImGui::Text("Username:");
				ImGui::SameLine();
				ImGui::InputText(("##OnlineUsername"), OnlineUsername, 128);
				ImGui::Text("Password:");
				ImGui::SameLine();
				ImGui::InputText(("##OnlinePassword"), OnlinePassword, 128);

				if (ImGui::Button("OnlineLogin")) {
					string x = COnline.GetOutputServer((string)OnlineUsername, (string)OnlinePassword);
					eraseAllSubStr(x, "\r\n");
					eraseAllSubStr(x, "п»ї");
					if (x == "goed") {
						CImGuiNeeds.iPageNumber = 2;
					}
					
				}

			}

			if (CImGuiNeeds.iPageNumber == 2) {
				ImGui::PushItemWidth(-1.0f);
				char Path[MAX_PATH] = "";
				GetModuleFileName(NULL, Path, MAX_PATH);
				int iLength = strlen(Path);
				int iLength2;
				for (int i = strlen(Path); i >= 0; i--) {
					if (Path[i] == '\\') {
						iLength2 = i;
						break;
					}
				}
//				char PathTransfered[MAX_PATH] = "";
				string StringTest;
				for (int i = 0; i <= iLength2; i++) {
//					PathTransfered[i] = Path[i];
					StringTest += Path[i];
				}
				ImGui::Text(StringTest.c_str());
				CImGuiNeeds.DLLPath32 = StringTest + "exampledll32.dll";
				CImGuiNeeds.DLLPath64 = StringTest + "exampledll64.dll";
				
				if (ImGui::Button("Inject", ImVec2(ImGui::GetWindowWidth() / 2 - 11, ImGui::GetWindowHeight() / 2 - 50))) {
					CImGuiNeeds.iPageNumber = 3;
				}
				ImGui::SameLine();
				if (ImGui::Button("Download", ImVec2(ImGui::GetWindowWidth() / 2 - 11, ImGui::GetWindowHeight() / 2 - 50))) {
					const TCHAR url[] = _T("http://commendme.xyz/exampledll32.dll");
//					const TCHAR filePath[] = _T(StringTest + "cheat.dll");
						HRESULT hr = URLDownloadToFile(NULL,url, CImGuiNeeds.DLLPath32.c_str()  ,0, NULL);
					if (hr == 0) {
						MessageBox(0, "Done.", "\r", MB_OK | MB_ICONERROR);
					}
					else {
						MessageBox(0, "Fail.", "\r", MB_OK | MB_ICONERROR);
					}
					ImGui::Text("lol");
				}
				if (ImGui::Button("Remove", ImVec2(ImGui::GetWindowWidth() / 2 - 11, ImGui::GetWindowHeight() / 2 - 50))) {
					remove(CImGuiNeeds.DLLPath32.c_str());
				}
				ImGui::SameLine();
				if (ImGui::Button("Auto Inject", ImVec2(ImGui::GetWindowWidth() / 2 - 12, ImGui::GetWindowHeight() / 2 - 50))) {
					CImGuiNeeds.iPageNumber = 4;
				}
			}
			if (CImGuiNeeds.iPageNumber == 3) {
				static char ProcessName[128] = "";
				ImGui::Text("ProcessName:");
				ImGui::SameLine();
				ImGui::InputText(("##ProcessName"), ProcessName, 128);
				ImGui::PushItemWidth(50);
				if (ImGui::Button("Inject")) {
/*					if (!GPN.GetNameOfProcess()) {
						MessageBoxA(0, "Process name input failed.", "\r", MB_OK | MB_ICONERROR);
						return EXIT_FAILURE;
					}*/
					GPN.ProcessName = (string)ProcessName;
					cout << "Process name gotten \n" << endl;

					if (!GH.GetHandleFromName(GPN.ProcessName)) {
						MessageBoxA(0, "Process not running.", "\r", MB_OK | MB_ICONERROR);
						return EXIT_FAILURE;
					}

					cout << "Handle gotten from process name" << endl;;
					FD.DLLName = CImGuiNeeds.DLLPath64;

					if (!I.Inject(GH.hProcess, FD.DLLName)) {
						MessageBoxA(0, "Injection Failed", "\r", MB_OK | MB_ICONERROR);
						return EXIT_FAILURE;
					}
					else {
						MessageBoxA(0, "Injected", "\r", MB_OK | MB_ICONEXCLAMATION);
					}
					I.Close();
				}
				if (ImGui::Button("return")) {
					CImGuiNeeds.iPageNumber = 2;
				}
				ImGui::Separator();
			}

			if (CImGuiNeeds.iPageNumber == 4) {
				static char ProcessName[128] = "";
				ImGui::Text("ProcessName:");
				ImGui::SameLine();
				ImGui::InputText(("##ProcessName"), ProcessName, 128);
				ImGui::PushItemWidth(50);
				if (ImGui::Button("Auto Inject")) {
					GPN.ProcessName = (string)ProcessName;
					cout << "Process name gotten \n" << endl;

					const TCHAR url[] = _T("http://commendme.xyz/exampledll32.dll");
					//					const TCHAR filePath[] = _T(StringTest + "cheat.dll");
					HRESULT hr = URLDownloadToFile(NULL, url, CImGuiNeeds.DLLPath32.c_str(), 0, NULL);
					if (hr == 0) {
						MessageBox(0, "Downloaded.", "\r", MB_OK | MB_ICONERROR);
					}
					else {
						MessageBox(0, "Fail.", "\r", MB_OK | MB_ICONERROR);
					}

					if (!GH.GetHandleFromName(GPN.ProcessName)) {
						MessageBoxA(0, "Process not running.", "\r", MB_OK | MB_ICONERROR);
						return EXIT_FAILURE;
					}

					cout << "Handle gotten from process name" << endl;;
					FD.DLLName = CImGuiNeeds.DLLPath32;

					if (!I.Inject(GH.hProcess, FD.DLLName)) {
						MessageBoxA(0, "Injection Failed", "\r", MB_OK | MB_ICONERROR);
						return EXIT_FAILURE;
					}
					else {
						MessageBoxA(0, "Injected", "\r", MB_OK | MB_ICONEXCLAMATION);
					}
					I.Close();
					remove(CImGuiNeeds.DLLPath32.c_str());
				}
				if (ImGui::Button("return")) {
					CImGuiNeeds.iPageNumber = 2;
				}
				ImGui::Separator();
			}
		}
		ImGui::End();
		
		ImGui::EndFrame();
		g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, false);
		g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
		g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
		D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x*255.0f), (int)(clear_color.y*255.0f), (int)(clear_color.z*255.0f), (int)(clear_color.w*255.0f));
		g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
		if (g_pd3dDevice->BeginScene() >= 0)
		{
			ImGui::Render();
			ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
			g_pd3dDevice->EndScene();
		}
		HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

		// Handle loss of D3D9 device
		if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			g_pd3dDevice->Reset(&g_d3dpp);
			ImGui_ImplDX9_CreateDeviceObjects();
		}


	}

	ImGui_ImplDX9_Shutdown();
	ImGui::DestroyContext();

	if (g_pd3dDevice) g_pd3dDevice->Release();
	if (pD3D) pD3D->Release();
	DestroyWindow(hWnd);
	UnregisterClass(_T("Informatica"), hInstance);

	return 0;

}

WNDCLASS CreateWindowClass(HINSTANCE hInstance) {
	WNDCLASS wcWndC = { 0 };
	wcWndC.style = CS_HREDRAW | CS_VREDRAW;
	wcWndC.lpfnWndProc = (WNDPROC)WndProc;
	wcWndC.hInstance = hInstance;
	wcWndC.hCursor = LoadCursor(NULL, IDC_ARROW); // <-- Cursor
	wcWndC.hbrBackground = (HBRUSH)COLOR_APPWORKSPACE;
	wcWndC.lpszClassName = "Informatica";
	wcWndC.hbrBackground = (HBRUSH)COLOR_APPWORKSPACE;
	return wcWndC;

}