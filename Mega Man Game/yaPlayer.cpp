#include "yaPlayer.h"
#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaAnimator.h"

namespace ya
{
	Player::Player()
	{
	}
	Player::~Player()
	{
	}
	void Player::Initialize()
	{
	}
	void Player::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Animator* anim = GetComponent<Animator>();


		if (Input::GetKey(eKeyCode::W))
		{
			anim->PlayAnimation(L"Up", true);
			pos.y -= 1000.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			anim->PlayAnimation(L"Left_Run", true);
			pos.x -= 1500.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			anim->PlayAnimation(L"Down", true);
			pos.y += 800.0f * Time::DeltaTime();

		}
		if (Input::GetKey(eKeyCode::D))
		{
			anim->PlayAnimation(L"Right_Run", true);
			pos.x += 1500.0f * Time::DeltaTime();
		}
		tr->SetPosition(pos);

	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
