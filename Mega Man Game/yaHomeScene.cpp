#include "yaHomeScene.h"
#include "yaPlayer.h"
#include "yaSpriteRenderer.h"
#include "yaObject.h"
#include "yaInput.h"
#include "yaTexture.h"
#include "yaTransform.h"
#include "yaResources.h"
#include "yaBackGround.h"
#include "yaCamera.h"

namespace ya
{
	HomeScene::HomeScene()
	{
	}
	HomeScene::~HomeScene()
	{
	}
	void HomeScene::Initialize()
	{
		Texture* Back = Resources::Load<Texture>(L"HomeBackGroundImgae"
			, L"..\\Resource\\Map\\Intro.bmp");

		BackGround* bg = object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(Back);
		bgsr->SetScale(Vector2(2.0f, 1.5f));
		bgsr->SetAffectCamera(false);
		//bgsr->SetAlpha(0.2f);
		bg->GetComponent<Transform>()->SetPosition(Vector2(0.0f, -200.0f));


		/*Texture* PlayerImage = Resources::Load<Texture>(L"Zero"
			, L"..\\Resource\\Player\\TestZero.bmp");

		Player* player = object::Instantiate<Player>(eLayerType::Player);
		SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		sr->SetImage(PlayerImage);
		sr->SetScale(Vector2(2.00f, 2.0f));


		Camera::SetTarget(player);*/
		//mLayers[(int)eLayerType::Player].AddGameObject(player);
	}
	void HomeScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeyCode::H))
		{
			SceneManager::LoadScene(L"HomeScene");
		}
		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"PlayScene");
		}

		if (Input::GetKeyDown(eKeyCode::B))
		{
			SceneManager::LoadScene(L"BossScene");
		}
		if (Input::GetKeyDown(eKeyCode::E))
		{
			SceneManager::LoadScene(L"EndingScene");
		}
	}
	void HomeScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
