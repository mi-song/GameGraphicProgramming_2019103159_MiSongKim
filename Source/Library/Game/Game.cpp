#include "Game/Game.h"

namespace library
{
	/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
	  Method:   Game::Game

	  Summary:  Constructor

	  Args:     PCWSTR pszGameName
				  Name of the game

	  Modifies: [m_pszGameName, m_mainWindow, m_renderer].
	M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
	/*--------------------------------------------------------------------
	  TODO: Game::Game definition (remove the comment)
	--------------------------------------------------------------------*/

	Game::Game(_In_ PCWSTR pszGameName)
	{

	}

	/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
	  Method:   Game::Initialize

	  Summary:  Initializes the components of the game

	  Args:     HINSTANCE hInstance
				  Handle to the instance
				INT nCmdShow
				  Is a flag that says whether the main application window
				  will be minimized, maximized, or shown normally

	  Modifies: [m_mainWindow, m_renderer].

	  Returns:  HRESULT
				Status code
	M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
	/*--------------------------------------------------------------------
	  TODO: Game::Initialize definition (remove the comment)
	--------------------------------------------------------------------*/

	HRESULT Game::Initialize(_In_ HINSTANCE hInstance, _In_ INT nCmdShow)
	{
		// Register class
		WNDCLASSEX wcex;
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = DefWindowProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = hInstance;
		wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_TUTORIAL1);
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = nullptr;
		wcex.lpszClassName = L"Game Graphics Programming";
		wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_TUTORIAL1);
		if (!RegisterClassEx(&wcex))
			return E_FAIL;

		// Create window
		hInst = hInstance;
		RECT rc = { 0, 0, 800, 600 };
		AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
		hWnd = CreateWindow(L"Game Graphics Programming", L"Game Graphics Programming Lab 01:Direct3D 11 Basics",
			WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
			CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, hInstance,
			nullptr);
		if (!hWnd)
			return E_FAIL;

		ShowWindow(hWnd, nCmdShow);

	}

	/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
	  Method:   Game::Run

	  Summary:  Runs the game loop

	  Returns:  INT
				  Status code to return to the operating system
	M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
	/*--------------------------------------------------------------------
	  TODO: Game::Run definition (remove the comment)
	--------------------------------------------------------------------*/

	INT Game::Run()
	{
		MSG msg = { 0 };
		while (WM_QUIT != msg.message)
		{
			if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				Renderer render; // 
				render.Render();
			}
		}

		return static_cast<INT>(msg.wParam);
	}

	/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
	  Method:   Game::GetGameName

	  Summary:  Returns the name of the game

	  Returns:  PCWSTR
				  Name of the game
	M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
	/*--------------------------------------------------------------------
	  TODO: Game::GetGameName definition (remove the comment)
	--------------------------------------------------------------------*/

	PCWSTR Game::GetGameName() const
	{
		return L"Sample window Class";
	}
}