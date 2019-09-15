#include "GameBoard.h"
#include<iostream>

#include "GameEngine\GameEngineMain.h"
#include "Game\GameComponents\BackgroundMovementComponent.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"
#include <Game\GameEntities\ItemEntity.h>
#include <GameEngine\EntitySystem\Components\ParticleEmitterComponent.h>
#include "Game\GameComponents\PlayerMovementComponent.h"
#include"Game/GameComponents/gravityComponent.h"
#include "Game\GameEntities\PlayerEntity.h"
#include "Game\GameEntities\FbiEntity.h"

#include"Game/GameComponents/gravityComponent.h"


using namespace Game;

GameBoard::GameBoard()
	:player(nullptr)
	,enemy(nullptr)
	,background(nullptr)
	, m_isGameOver(false)
{
	CreateBackGround();
	CreatePlayer();
}


GameBoard::~GameBoard()
{
	GameEngine::GameEngineMain::GetInstance()->~GameEngineMain();

}

void GameBoard::CreatePlayer()
{
	
	player = new PlayerEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player);
	
	player->SetPos(sf::Vector2f(220.f, 300.f));
	player->SetSize(sf::Vector2f(100.f, 100.f));


}

void GameBoard::CreateEnemy()
{
	enemy = new FbiEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(enemy);

	enemy->SetPos(sf::Vector2f(420.f, 290.f));
	enemy->SetSize(sf::Vector2f(100.f, 100.f));
}


void GameBoard::CreateBackGround()
{
	background = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

	background->SetPos(sf::Vector2f(852.f, 220.f));
	background->SetSize(sf::Vector2f(1704.f, 441.f));

	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(background->AddComponent<GameEngine::SpriteRenderComponent>());
	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Background);

	background->AddComponent<BackgroundMovementComponent>();
}



void GameBoard::Update()
{
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();

	if (!m_isGameOver)
	{
		i_lastObstacleSpawnTimer -= dt;
		i_lastFbiSpawnTimer -= dt;

		if (i_lastObstacleSpawnTimer <= 0.f)
		{
			SpawnNewRandomItems();

		}
		


		UpdateItems(dt);
	}
	
}

void GameBoard::UpdatePlayerDying()
{
	static float xToPlayerDie = 0.f;
	if (player->GetPos().x < xToPlayerDie)
	{
		m_isGameOver = true;
	}
}


	
void GameBoard::UpdateItems(float dt)
{
	static float obstacleSpeed = 130.f;

	for (std::vector<GameEngine::Entity*>::iterator it = itemList.begin(); it != itemList.end(); ++it)
	{
		GameEngine::Entity* item = (*it);
		sf::Vector2f currPos = item->GetPos();
		currPos.x -= obstacleSpeed * dt;
		item->SetPos(currPos);
		//If we are to remove ourselves
		if (currPos.x < -50.f)
		{
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(item);
			it = itemList.erase(it);
		}
	}
}

void GameBoard::SpawnNewRandomItems()
{
	static int minObstacleCount = 2;
	static int maxObstacleCount = 7;


	static float minNextSpawnTime = 1.5f;
	static float maxNextSpawnTime = 2.3f;
	

	static float minObstacleXPos = 350.f;
	static float maxObstacleXPos = 450.f;
	static float minObstacleYPos = 50.f;
	static float maxObstacleYPos = 310.f;

	sf::Vector2f pos = sf::Vector2f(RandomFloatRange(minObstacleXPos, maxObstacleXPos), RandomFloatRange(minObstacleYPos, maxObstacleYPos));
	sf::Vector2f size = sf::Vector2f(32.f, 32.f);

	int obstacleCount = (int)RandomFloatRange((float)minObstacleCount, (float)maxObstacleCount);

	SpawnNewItem(pos, size);
	pos.y += size.y;


	i_lastObstacleSpawnTimer = RandomFloatRange(minNextSpawnTime, maxNextSpawnTime);

}

void GameBoard::SpawnNewItem(const sf::Vector2f& pos, const sf::Vector2f& size)
{
	ItemEntity* item = new ItemEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(item);
	item->SetPos(pos);
	item->SetSize(sf::Vector2f(size.x, size.y));
	itemList.push_back(item);
}