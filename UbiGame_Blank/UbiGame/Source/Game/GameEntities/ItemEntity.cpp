#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include <SFML/Graphics.hpp>
#include "GameEngine\GameEngineMain.h"
#include "ItemEntity.h"
using namespace Game;

ItemEntity::ItemEntity()
{
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetFillColor(sf::Color::Transparent);
	m_renderComponent->SetTexture(GameEngine::eTexture::Items);

	float randTile = ((4 - 0) * ((float)rand() / RAND_MAX)) + 0;

	m_renderComponent->SetTileIndex(randTile, 0);
	AddComponent<GameEngine::CollidableComponent>();
}

ItemEntity::~ItemEntity()
{

}


void ItemEntity::OnAddToWorld()
{
	__super::OnAddToWorld();
}


void ItemEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}
