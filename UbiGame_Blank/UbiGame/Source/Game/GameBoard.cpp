#include "GameBoard.h"

#include "GameEngine\GameEngineMain.h"
#include "Game\GameComponents\BackgroundMovementComponent.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"
#include "Game\GameComponents\PlayerMovementComponent.h"
#include "../../gravityComponent.h"


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
	player->AddComponent<GameEngine::AnimationComponent>();
	player->AddComponent<gravityComponent>();

}



void GameBoard::Update()
{

}