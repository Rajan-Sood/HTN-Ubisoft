#include "FbiEntity.h"

#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/ParticleEmitterComponent.h"

using namespace Game;

FbiEntity::FbiEntity()
{
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetFillColor(sf::Color::Transparent);
	AddComponent<GameEngine::CollidablePhysicsComponent>();
	m_fbiMovementComponent = static_cast<Game::FbiMovementComponent*>(AddComponent<Game::FbiMovementComponent>());

	//m_playerMovementComponent = static_cast<Game::PlayerMovementComponent*>(AddComponent<Game::PlayerMovementComponent>());


	m_renderComponent->SetTexture(GameEngine::eTexture::FBI);
}


FbiEntity::~FbiEntity()
{

}


void FbiEntity::OnAddToWorld()
{
	__super::OnAddToWorld();

}


void FbiEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}
