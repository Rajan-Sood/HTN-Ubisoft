#include "PlayerEntity.h"

#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/ParticleEmitterComponent.h"

using namespace Game;

PlayerEntity::PlayerEntity()
{
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetFillColor(sf::Color::Transparent);
	m_playerMovementComponent = static_cast<Game::PlayerMovementComponent*>(AddComponent<Game::PlayerMovementComponent>());
	//AddComponent<GameEngine::CollidablePhysicsComponent>();

	m_renderComponent->SetTexture(GameEngine::eTexture::Player);
	m_renderComponent->SetZLevel(2);
	m_animComponent = static_cast<GameEngine::AnimationComponent*>(AddComponent<GameEngine::AnimationComponent>());
	//AddComponent<GameEngine::ParticleEmitterComponent>();
}


PlayerEntity::~PlayerEntity()
{

}


void PlayerEntity::OnAddToWorld()
{
	__super::OnAddToWorld();

	if (m_animComponent)
	{
		m_animComponent->PlayAnim(GameEngine::EAnimationId::Run);
	}
}


void PlayerEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}
