#include "gravityComponent.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

gravityComponent::gravityComponent()
	: m_velocity(sf::Vector2f(0.f, 0.f))
	, m_lastPos(sf::Vector2f(0.f, 0.f))
	, m_wantedVelocity(sf::Vector2f(0.f, 0.f))
{

}


gravityComponent::~gravityComponent()
{

}

void gravityComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
	m_lastPos = GetEntity()->GetPos();
}


void gravityComponent::Update()
{
	float dt = GameEngine::GameEngineMain::GetTimeDelta();
	float gForce = 1000.f;

	m_velocity += m_wantedVelocity * dt;
	m_velocity.y += gForce * dt;

	sf::Vector2f deltaVelocity = dt * m_velocity;


	GetEntity()->SetPos(GetEntity()->GetPos() + deltaVelocity);

	__super::Update();



	if (GetEntity()->GetPos().y > 300)
	{
		m_velocity.y = 0;
		GetEntity()->SetPos(GetEntity()->GetPos() - deltaVelocity);
	}
}
