#include "GameBoard.h"

#include "GameEngine\GameEngineMain.h"
#include "Game\GameComponents\BackgroundMovementComponent.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"

using namespace Game;

GameBoard::GameBoard()
	:background(nullptr)
{
	CreateBackGround();
}


GameBoard::~GameBoard()
{

}

void GameBoard::CreatPlayer()
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

void GameBoard::Update()
{

}