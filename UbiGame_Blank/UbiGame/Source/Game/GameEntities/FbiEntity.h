#pragma once
#include "GameEngine\EntitySystem\Entity.h"
#include "GameEngine\EntitySystem\Components\AnimationComponent.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"
#include "Game\GameComponents\FbiMovementComponent.h"

namespace Game
{

	class FbiEntity : public GameEngine::Entity
	{
	public:
		FbiEntity();
		~FbiEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;
		FbiMovementComponent* m_fbiMovementComponent;
		GameEngine::AnimationComponent* m_animComponent;
	};
}

