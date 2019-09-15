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
		float RandomFloatRange(float a, float b)
		{
			return ((b - a) * ((float)rand() / RAND_MAX)) + a;
		}
		void Update();		
		bool IsGameOver() { return false; }

	private:
		void CreatePlayer();
		void CreateBackGround();

		float i_lastObstacleSpawnTimer;
		std::vector<GameEngine::Entity*> BuildingList;


		void CreateObstacle();
		GameEngine::Entity* player;
		GameEngine::Entity* background;

	};
}

