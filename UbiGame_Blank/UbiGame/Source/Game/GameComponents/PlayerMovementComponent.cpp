#include "PlayerMovementComponent.h"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/System/Vector2.hpp"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "../gravityComponent.h"


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

	static bool prevPress = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !prevPress)
	{
		wantedVel.y = -200;
		prevPress = 1;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		prevPress = 0;
	}

	gravityComponent* jumpPhys = GetEntity()->GetComponent<gravityComponent>();
	if (jumpPhys)
	{
		jumpPhys->SetVelocity(wantedVel);
	}

	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);

}