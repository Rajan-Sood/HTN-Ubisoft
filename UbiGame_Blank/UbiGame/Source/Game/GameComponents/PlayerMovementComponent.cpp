#include "PlayerMovementComponent.h"


#include "GameEngine\GameEngineMain.h"
#include <SFML/Window/Keyboard.hpp>

using namespace Game;

PlayerMovementComponent::PlayerMovementComponent()
{

}

PlayerMovementComponent::~PlayerMovementComponent()
{

}

void PlayerMovementComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
}

void PlayerMovementComponent::Update()
{
	__super::Update();

	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);
	float playerVel = 100.f;

	wantedVel.x = 2 * dt;
	static bool isDown = 1;

	bool temp = false;
	temp = GetEntity()->GetCol();
	
	if (temp)
	{
		wantedVel.x += 1;

	}
	//GetEntity()->coll = 


	if (GetEntity()->GetPos().y < 60)
	{
		isDown = 0;
	}
	if (GetEntity()->GetPos().y > 300)
	{
		GetEntity()->SetPos(sf::Vector2f(220.f, 300.f));
		isDown = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isDown)
	{
		wantedVel.y = -0.15;
	}
	else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || !isDown)
	{
		wantedVel.y = 0.1;
		isDown = 0;
	}
	

	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		wantedVel.y -= playerVel * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		wantedVel.y += playerVel * dt;
	}*/

	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);

}