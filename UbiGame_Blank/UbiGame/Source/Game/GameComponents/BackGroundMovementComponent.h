#pragma once
#include "GameEngine\EntitySystem\Component.h"

namespace Game
{
	class BackgroundMovementComponent : public GameEngine::Component
	{
	public:
		BackgroundMovementComponent();
		~BackgroundMovementComponent();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

	private:

	};
}