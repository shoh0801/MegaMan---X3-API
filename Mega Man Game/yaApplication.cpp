#include "yaApplication.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaTitleScene.h"
#include "yaSceneManager.h"
#include "yaCamera.h"

namespace ya
{
	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
		, mWidth(0)
		, mHeight(0)
		, mBackBuffer(NULL)
		, mBackHdc(NULL)
	{

	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		mWidth = 1280;		// *0.5  하면 원래 해상도
		mHeight = 720;		// * 0.667 


		RECT rect = { 0, 0, mWidth, mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mHwnd
			, nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		ShowWindow(mHwnd, true);

		// 윈도우 해상도 동일한 비트맵 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);

		// 새로 생성한 비트맵을 가리키는 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		// 새로 생성한 비트맵과 DC를 서로 연결
		HBITMAP defaultBitmap 
			= (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(defaultBitmap);

		Time::Initailize();
		Input::Initailize();
		Camera::Initalize();

		SceneManager::Initialize();
		
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		Camera::Update();

		SceneManager::Update();

		//if (Input::GetKey(eKeyCode::W))
		//{
		//	mPlayerPos.y -= 300.0f * Time::DeltaTime();
		//}
		//if (Input::GetKey(eKeyCode::A))
		//{
		//	mPlayerPos.x -= 300.0f * Time::DeltaTime();
		//}
		//if (Input::GetKey(eKeyCode::S))
		//{
		//	mPlayerPos.y += 300.0f * Time::DeltaTime();
		//}
		//if (Input::GetKey(eKeyCode::D))
		//{
		//	mPlayerPos.x += 300.0f * Time::DeltaTime();
		//}
	}

	void Application::Render()
	{
		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);
		Time::Render(mBackHdc);


		SceneManager::Render(mBackHdc);
		//Rectangle(mHdc, 100, 100, 200, 200);
		//Ellipse(mBackHdc, 100 + mPlayerPos.x, 100 + mPlayerPos.y
		//	, 200 + mPlayerPos.x, 200 + mPlayerPos.y);

		BitBlt(mHdc, 0, 0, mWidth, mHeight
			,mBackHdc , 0, 0, SRCCOPY);
	}
}
