#include "yaBoss.h"
#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"

namespace ya
{
	Boss::Boss()
	{
	}
	Boss::~Boss()
	{
	}
	void Boss::Initialize()
	{
	}
	void Boss::Update()
	{
		GameObject::Update();
	}

	void Boss::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
