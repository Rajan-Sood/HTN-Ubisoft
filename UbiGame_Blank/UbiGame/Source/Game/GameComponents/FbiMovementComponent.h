#pragma once
#include "GameEngine\EntitySystem\Component.h"

namespace Game
{
	class FbiMovementComponent : public GameEngine::Component
	{
	public:
		FbiMovementComponent();
		~FbiMovementComponent();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

	private:

	};
}
