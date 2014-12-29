#include "Niveau.h"
#include "vector2.h"
/*
#include "Mur.h"
#include "Bonus.h"
#include "BonusAccelererPerso.h"
#include "BonusDetruireMur.h"

#include "SFML/Graphics/Texture.hpp"

#include "EasyDefines.h"
#include "tinyxml/tinyxml.h"
*/

template<typename T >
Vector2< T > operator/ (const Vector2< T > & left, T right);

Niveau::Niveau() :mGridSize(), mWindowSizePixels()
{

}

bool Niveau::chargerDepuisFichierXml(std::string pFichierXml)
{

}

sf::Vector2i Niveau::sizeOneCell_pixel()
{
	sf::Vector2i sizeOneCell_pixel = mGridSize / mWindowSizePixels;

	return sizeOneCell_pixel;
}


void Niveau::drawContent(sf::RenderTarget& pSurfaceDeRendu)
{

}

void Niveau::bougerPerso(int dirX, int dirY, float dt_s)
{

}

bool Niveau::isFinished()
{

}

void Niveau::gererBonus()
{

}