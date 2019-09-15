#pragma once
#include "GameEngine\EntitySystem\Component.h"

namespace Game
{
	class GenericItemComponent : public GameEngine::Component
	{
	public:
		GenericItemComponent();
		~GenericItemComponent();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

	private:

	};
}


