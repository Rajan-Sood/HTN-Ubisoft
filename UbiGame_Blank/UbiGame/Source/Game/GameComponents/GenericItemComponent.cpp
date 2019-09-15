#include "GenericItemComponent.h"
#include "GameEngine\GameEngineMain.h"
#include <SFML/Window/Keyboard.hpp>

using namespace Game;

GenericItemComponent::GenericItemComponent()
{

}

GenericItemComponent::~GenericItemComponent()
{

}

void GenericItemComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
}

void GenericItemComponent::Update()
{
	__super::Update();

	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	GetEntity()->SetPos(GetEntity()->GetPos());

}
