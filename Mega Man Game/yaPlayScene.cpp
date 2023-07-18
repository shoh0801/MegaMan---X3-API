#include "yaPlayScene.h"
#include "yaPlayer.h"
#include "yaSpriteRenderer.h"
#include "yaObject.h"
#include "yaInput.h"
#include "yaTexture.h"
#include "yaTransform.h"
#include "yaResources.h"
#include "yaBackGround.h"
#include "yaCamera.h"
#include "yaAnimation.h"
#include "yaAnimator.h"
#include "yaBoss.h"

namespace ya
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		Texture* Back = Resources::Load<Texture>(L"PlayBackGroundImgae"
			, L"..\\Resource\\IntroMap\\IntroBackGround.bmp");

		BackGround* Backbg = object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* bgsr = Backbg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(Back);
		bgsr->SetScale(Vector2(3.0f, 2.5f));
		//bgsr->SetAffectCamera(false);
		//bgsr->SetAlpha(0.2f);
		Backbg->GetComponent<Transform>()->SetPosition(Vector2(0.0f, -500.0f));

			//Texture* BossText = Resources::Load<Texture>(L"PlayBackGroundImgae"
			//	, L"..\\Resource\\IntroMap\\IntroBossBackGround.png");

			//BackGround* BossBack = object::Instantiate<BackGround>(eLayerType::Background);
			//SpriteRenderer* BossSr = BossBack->AddComponent<SpriteRenderer>();
			//BossSr->SetImage(BossText);
			//BossSr->SetScale(Vector2(13.0f, 12.5f));
			////bgsr->SetAffectCamera(false);
			////bgsr->SetAlpha(0.2f);
			//BossBack->GetComponent<Transform>()->SetPosition(Vector2(0.0f, -500.0f));
		
		Texture* Map = Resources::Load<Texture>(L"PlayMapImgae"
			, L"..\\Resource\\IntroMap\\IntroStage.png");
		BackGround* Mapbg = object::Instantiate<BackGround>(eLayerType::Map);
		SpriteRenderer* Rd = Mapbg->AddComponent<SpriteRenderer>();
		Rd->SetImage(Map);
		Rd->SetScale(Vector2(5.0f, 3.7f));
		//bgsr->SetAffectCamera(false);
		//bgsr->SetAlpha(0.2f);
		Mapbg->GetComponent<Transform>()->SetPosition(Vector2(10250.0f, -1400.0f));

		// 플레이어	 y128 x128
		//			x31 y50
		{
		Texture* Right_PlayerImage = Resources::Load<Texture>(L"R_Zero"
			, L"..\\Resource\\Zero\\Right_Player1.bmp");
		Texture* Right_PlayerImage2 = Resources::Load<Texture>(L"R_Zero2"
			, L"..\\Resource\\Zero\\Right_Player2.bmp");
			
		Texture* Left_PlayerImage = Resources::Load<Texture>(L"L_Zero"
				, L"..\\Resource\\Zero\\Left_Player1.bmp");
		Texture* Left_PlayerImage2 = Resources::Load<Texture>(L"L_Zero2"
			, L"..\\Resource\\Zero\\Left_Player2.bmp");
		Player* player = object::Instantiate<Player>(eLayerType::Player);
		Transform* tr = player->GetComponent<Transform>();
		SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		Animator* at = player->AddComponent<Animator>();
		
		// 오른쪽
		at->CreateAnimation(L"Right_Idle", Right_PlayerImage, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), 4);
		at->CreateAnimation(L"Right_IdleAttack", Right_PlayerImage, Vector2(512.0f, 0.0f), Vector2(128.0f, 128.0f), 1);
		at->CreateAnimation(L"Right_Run", Right_PlayerImage, Vector2(896.0f, 0.0f), Vector2(128.0f, 128.0f), 6);
		at->CreateAnimation(L"Right_RunAttack", Right_PlayerImage, Vector2(0.0f, 128.0f), Vector2(128.0f, 128.0f), 6);
		at->CreateAnimation(L"Right_Jump", Right_PlayerImage, Vector2(896.0f, 128.0f), Vector2(128.0f, 128.0f), 8);
		at->CreateAnimation(L"Right_Dash", Right_PlayerImage, Vector2(640.0f, 256.0f), Vector2(128.0f, 128.0f), 4);
		at->CreateAnimation(L"Right_DashAttack", Right_PlayerImage, Vector2(1280.0f, 256.0f), Vector2(128.0f, 128.0f), 4);
		at->CreateAnimation(L"Right_Sword", Right_PlayerImage2, Vector2(384.0f, 0.0f), Vector2(128.0f, 128.0f), 7);
		at->CreateAnimation(L"Right_JumpSword", Right_PlayerImage2, Vector2(384.0f, 128.0f), Vector2(128.0f, 128.0f), 7);
		at->CreateAnimation(L"Down", Right_PlayerImage2, Vector2(1408.0f, 256.0f), Vector2(128.0f, 128.0f), 3);


		// 왼쪽
		at->CreateAnimation(L"Left_Idle", Left_PlayerImage, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), 4);
		at->CreateAnimation(L"Left_IdleAttack", Left_PlayerImage, Vector2(512.0f, 0.0f), Vector2(128.0f, 128.0f), 1);
		at->CreateAnimation(L"Left_Run", Left_PlayerImage, Vector2(896.0f, 0.0f), Vector2(128.0f, 128.0f), 6);
		at->CreateAnimation(L"Left_RunAttack", Left_PlayerImage, Vector2(0.0f, 128.0f), Vector2(128.0f, 128.0f), 6);
		at->CreateAnimation(L"Left_Jump", Left_PlayerImage, Vector2(896.0f, 128.0f), Vector2(128.0f, 128.0f), 8);
		at->CreateAnimation(L"Left_Dash", Left_PlayerImage, Vector2(640.0f, 256.0f), Vector2(128.0f, 128.0f), 4);
		at->CreateAnimation(L"Left_DashAttack", Left_PlayerImage, Vector2(1280.0f, 256.0f), Vector2(128.0f, 128.0f), 4);
		at->CreateAnimation(L"Left_Sword", Left_PlayerImage2, Vector2(384.0f, 0.0f), Vector2(128.0f, 128.0f), 7);
		at->CreateAnimation(L"Left_JumpSword", Left_PlayerImage2, Vector2(384.0f, 128.0f), Vector2(128.0f, 128.0f), 7);
		at->CreateAnimation(L"Up", Left_PlayerImage2, Vector2(1408.0f, 256.0f), Vector2(128.0f, 128.0f), 3);


		at->PlayAnimation(L"Right_JumpSword", true);


		at->SetScale(Vector2(3.7f,3.0f));


		/*sr->SetImage(PlayerImage);
		sr->SetScale(Vector2(3.70f, 3.0f));*/ 
		Camera::SetTarget(player);



		}
		// 보스
		{
		Texture* PlayerImage2 = Resources::Load<Texture>(L"Mac"
			, L"..\\Resource\\Boss\\TestMac.bmp");

		BackGround* player2 = object::Instantiate<BackGround>(eLayerType::Player);
		SpriteRenderer* sr2 = player2->AddComponent<SpriteRenderer>();
		sr2->SetImage(PlayerImage2);
		player2->GetComponent<Transform>()->SetPosition(Vector2(18100.0f,-1930.0f));
		sr2->SetScale(Vector2(3.70f, 3.0f));
		}



		//mLayers[(int)eLayerType::Player].AddGameObject(player);

	}
	void PlayScene::Update()
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
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

	}
}
