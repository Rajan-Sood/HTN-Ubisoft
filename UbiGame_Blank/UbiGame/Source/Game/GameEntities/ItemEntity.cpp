#include "ItemEntity.h"

#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/ParticleEmitterComponent.h"

using namespace Game;

ItemEntity::ItemEntity()
{
	
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
