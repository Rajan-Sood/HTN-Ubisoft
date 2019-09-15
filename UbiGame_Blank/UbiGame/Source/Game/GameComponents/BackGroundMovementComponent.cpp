#include "BackgroundMovementComponent.h"
#include "GameEngine\GameEngineMain.h"
#include <SFML/Window/Keyboard.hpp>

using namespace Game;

BackgroundMovementComponent::BackgroundMovementComponent()
{

}

BackgroundMovementComponent::~BackgroundMovementComponent()
{

}

void BackgroundMovementComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
}

void BackgroundMovementComponent::Update()
{
	__super::Update();

	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);
	float playerVel = 35.f;

	wantedVel.x -= playerVel * dt;

	if (GetEntity()->GetPos().x < 0)
	{
		GetEntity()->SetPos(sf::Vector2f(852, GetEntity()->GetPos().y));
	}
	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);
}