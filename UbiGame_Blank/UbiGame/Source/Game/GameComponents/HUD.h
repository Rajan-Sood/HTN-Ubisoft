#pragma once
#include "GameEngine\EntitySystem\Component.h"

namespace Game
{
	class HUD : public GameEngine::Component
	{
	public:
		HUD();
		~HUD();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

	private:

	};
}
