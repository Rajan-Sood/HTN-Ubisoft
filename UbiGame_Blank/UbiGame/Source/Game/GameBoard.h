#pragma once
#include "GameEngine\EntitySystem\Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;	

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();


		void SpawnNewBuildings(const sf::Vector2f& pos, const sf::Vector2f& size);
		void SpawnNewRandomBuildings();
		void UpdateBuildings(float dt);
		void SpawnNewItem(const sf::Vector2f& pos, const sf::Vector2f& size);
		void SpawnNewRandomItems();
		void UpdateItems(float dt);

		float RandomFloatRange(float a, float b)
		{
			return ((b - a) * ((float)rand() / RAND_MAX)) + a;
		}
		void Update();		
		bool IsGameOver() { return false; }

	private:
		void CreatePlayer();
		void CreateEnemy();
		void CreateBackGround();
		void UpdatePlayerDying();

		

		float i_lastObstacleSpawnTimer;
		float i_lastFbiSpawnTimer;

		void CreateObstacle();
		std::vector<GameEngine::Entity*> itemList;
		GameEngine::Entity* player;
		GameEngine::Entity* background;
		GameEngine::Entity* enemy;
		bool  m_isGameOver;


	};
}

