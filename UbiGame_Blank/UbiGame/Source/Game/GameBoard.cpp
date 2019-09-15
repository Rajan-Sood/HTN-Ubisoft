#include "GameBoard.h"

#include "GameEngine\GameEngineMain.h"
#include "Game\GameComponents\BackgroundMovementComponent.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"
#include <Game\GameEntities\ItemEntity.h>
#include <GameEngine\EntitySystem\Components\ParticleEmitterComponent.h>
#include "Game\GameComponents\PlayerMovementComponent.h"
using namespace Game;

GameBoard::GameBoard()
	:player(nullptr)
	,background(nullptr)
{
	CreateBackGround();
	CreatePlayer();
}


GameBoard::~GameBoard()
{

}

void GameBoard::CreatePlayer()
{
	player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player);

	player->SetPos(sf::Vector2f(400.f, 250.f));
	player->SetSize(sf::Vector2f(40.f, 40.f));

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


void GameBoard::CreatePlayer()
{
	player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player);

	player->SetPos(sf::Vector2f(200.f, 250.f));
	player->SetSize(sf::Vector2f(115.f, 118.f));

	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(player->AddComponent<GameEngine::SpriteRenderComponent>());
	spriteRender->SetFillColor(sf::Color::Transparent);

	spriteRender->SetTexture(GameEngine::eTexture::Player);

	player->AddComponent<PlayerMovementComponent>();


}



void GameBoard::Update()
{
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();

	i_lastObstacleSpawnTimer -= dt;

	if (i_lastObstacleSpawnTimer <= 0.f)
	{
		SpawnNewRandomItems();
	}

	UpdateItems(dt);
}

void GameBoard::UpdateItems(float dt)
{
	static float obstacleSpeed = 100.f;

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

	static float minNextSpawnTime = 0.3f;
	static float maxNextSpawnTime = 0.7f;

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