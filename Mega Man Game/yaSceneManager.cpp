#include "yaSceneManager.h"
#include "yaTitleScene.h"
#include "yaHomeScene.h"
#include "yaEndingScene.h"
#include "yaPlayScene.h"
#include "yaBossScene.h"

namespace ya
{
	std::map<std::wstring, Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
		//CreateScene<TitleScene>(L"TitleScene");
		CreateScene<HomeScene>(L"HomeScene");
		CreateScene<PlayScene>(L"PlayScene");
		CreateScene<EndingScene>(L"EndingScene");
		CreateScene<BossScene>(L"BossScene");

		LoadScene(L"HomeScene");
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		std::map<std::wstring, Scene*>::iterator iter
			= mScenes.find(name);

		if (iter == mScenes.end())
			return nullptr;

		mActiveScene = iter->second;
		return iter->second;
	}
}
