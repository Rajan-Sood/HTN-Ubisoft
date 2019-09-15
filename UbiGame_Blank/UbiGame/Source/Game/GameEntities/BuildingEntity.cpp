#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include <SFML/Graphics.hpp>
#include "GameEngine\GameEngineMain.h"
#include "BuildingEntity.h"
using namespace Game;

BuildingEntity::BuildingEntity()
{
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetFillColor(sf::Color::Transparent);
	m_renderComponent->SetTexture(GameEngine::eTexture::Building);

	//float randTile = ((4 - 0) * ((float)rand() / RAND_MAX)) + 0;

	m_renderComponent->SetTileIndex(0, 0);
	AddComponent<GameEngine::CollidableComponent>();
}

BuildingEntity::~BuildingEntity()
{

}


void BuildingEntity::OnAddToWorld()
{
	__super::OnAddToWorld();
}


void BuildingEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}