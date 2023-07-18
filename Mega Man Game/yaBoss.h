#pragma once
#include "yaGameObject.h"


namespace ya
{
	class Boss : public GameObject
	{
	public:
		Boss();
		virtual ~Boss();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:

	};
}
