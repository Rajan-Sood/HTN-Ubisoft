#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,
			Player,
			Items,
			Background,
			Count,
		};
	}

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture)
		{
		case eTexture::Player:    return "multiplekeanu.png";
		case eTexture::Items:	return "items.png";
		case eTexture::Background:		  return "bg.jpg";
		default:       return "UnknownTexType";
		}
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	static sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture)
	{
		switch (texture)
		{

		case  GameEngine::eTexture::Player:  return sf::Vector2f(115.f, 118.f);
		//case  GameEngine::eTexture::Building: return sf::Vector2f(120.f, 130.f);
		//case  GameEngine::eTexture::Tileset: return sf::Vector2f(32.f, 32.f);
		case GameEngine::eTexture::Items: return sf::Vector2f(70.f, 70.f);
		//case  GameEngine::eTexture::BG:	     return sf::Vector2f(500.f, 500.f);
		//case  GameEngine::eTexture::Particles: return sf::Vector2f(31.f, 32.f);
		default:							 return sf::Vector2f(-1.f, -1.f);
		}
	}
}

