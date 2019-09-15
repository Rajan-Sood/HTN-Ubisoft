#include "FbiMovementComponent.h"


#include "GameEngine\GameEngineMain.h"
#include <SFML/Window/Keyboard.hpp>

using namespace Game;

FbiMovementComponent::FbiMovementComponent()
{

}

FbiMovementComponent::~FbiMovementComponent()
{

}

void FbiMovementComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
}

void FbiMovementComponent::Update()
{
	__super::Update();

	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);
	float playerVel = 100.f;

	wantedVel.x -= 200 * dt;
	

	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);

}