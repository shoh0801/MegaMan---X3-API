#include "yaBossScene.h"
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
	BossScene::BossScene()
	{
	}
	BossScene::~BossScene()
	{
	}
	void BossScene::Initialize()
	{
		//Texture* BossText = Resources::Load<Texture>(L"PlayBackGroundImgae"
		//	, L"..\\Resource\\IntroMap\\IntroBossBackGround.png");

		//BackGround* BossBack = object::Instantiate<BackGround>(eLayerType::Background);
		//SpriteRenderer* BossSr = BossBack->AddComponent<SpriteRenderer>();
		//BossSr->SetImage(BossText);
		//BossSr->SetScale(Vector2(3.0f, 2.5f));
		////bgsr->SetAffectCamera(false);
		////bgsr->SetAlpha(0.2f);
		//BossBack->GetComponent<Transform>()->SetPosition(Vector2(0.0f, -500.0f));


		//Texture* PlayerImage = Resources::Load<Texture>(L"Zero"
		//	, L"..\\Resource\\Player\\TestZero.bmp");

		//Player* player2 = object::Instantiate<Player>(eLayerType::Player);
		//SpriteRenderer* sr = player2->AddComponent<SpriteRenderer>();
		//sr->SetImage(PlayerImage);
		//sr->SetScale(Vector2(3.70f, 3.0f));



		//Camera::SetTarget(player2);
		//mLayers[(int)eLayerType::Player].AddGameObject(player);

	}
	void BossScene::Update()
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
	void BossScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

	}
}