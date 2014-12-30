#include "Niveau.h"
/*
#include "Mur.h"
#include "Bonus.h"
#include "BonusAccelererPerso.h"
#include "BonusDetruireMur.h"

#include "SFML/Graphics/Texture.hpp"

#include "EasyDefines.h"
#include "tinyxml/tinyxml.h"
*/

Niveau::Niveau() :mGridSize(), mWindowSizePixels()
{

}

bool Niveau::chargerDepuisFichierXml(std::string pFichierXml)
{
	return false;
}

sf::Vector2i Niveau::sizeOneCell_pixel()
{
	sf::Vector2i sizeOneCell_pixel = mGridSize / 600;

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
	return false;
}

void Niveau::gererBonus()
{

}
