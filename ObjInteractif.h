#pragma once

#include "Niveau.h"

class ObjInteractif
{
	Niveau* pParent;
	std::string pTexturePath;

public:

	ObjInteractif();
	~ObjInteractif();

	ObjInteractif(Niveau* pParent, std::string pTexturePath) : pParent(pParent), pTexturePath(pTexturePath)
	{}

	/// position dans la grille (en indices).
	/// il s'agit d'une position flottante.
	/// il est donc possible d'avoir (4.3,6.7) => dessiné à la position (4,6)
	sf::Vector2f mPositionInGrid;

	sf::Vector2i getRoundedPositionInGrid();


private:

	/// c'est un pointeur de handle, PAS UNE AGGREGATION.
	/// celui-ci permet d'acceder à l'instance de Niveau qui contient l'ObjInteractif.
	Niveau* mParent;

	/// chemin du fichier de la texture utilisee par cet objet interactif
	std::string mTexturePath;

};


