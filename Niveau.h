#pragma once

// forward declaration (cf cours)
class Mur;
class Bonus;
namespace sf
{
	class Texture;
	class RenderTarget;
}

// includes
/*
#include "Personnage.h"
#include "Sortie.h"
*/

#include "SFML/System/Vector2.hpp"

#include <vector>
#include <map>

/// classe qui contient le perso, la sortie, les murs et les bonus.
/// Elle represente un niveau.
/// Elle permet de faire se deplacer le personnage, de lancer les bonus.
/// elle aggrege aussi les textures.
class Niveau
{
public: // nos methodes, fonctions publiques

	/// constructeur. initialise toutes les valeurs a 0,0.
	/// cree des tableaux vides, a l'aide de la liste d'initialisation.
	Niveau();

	/// destructeur. libere les aggregations de la memoire.
	~Niveau();

	/// cette fonction charge un fichier Xml depuis le disque 
	///
	/// le fichier xml indique : 
	///		la taille de la fenetre en pixel
	///		la taille de la grille
	///		les murs, les bonus, la position de depart du personnage, la position de la sortie
	///		
	/// Pour le lire le fichier, utiliser tinyxml.
	/// - inspirez vous de l'exemple du cours cpp : dans prog10_ExemplesCodesVaries/ExempleLectureXml.h et .cpp 
	/// - ou regardez http://www.dinomage.com/2012/01/tutorial-using-tinyxml-part-1/ pour un bon tutorial/exemple d'usage 
	///
	/// Si c'est trop dur, remplissez ces informations dans la fonction a la main sans lire de fichier xml.
	///  (par contre vous n'aurez pas les points de l'exercice).
	///
	/// renvoie false en cas d'erreur
	bool chargerDepuisFichierXml(std::string pFichierXml);
	
	/// taille d'une "case" (ou "cellule") a l'ecran en pixels
	sf::Vector2i sizeOneCell_pixel();

	/// dessine le perso, la sortie, les bonus et les murs dans la surface de rendu
	/// note : RenderWindow herite de RenderTarget, donc on peut passer la fenetre en parametre
	void drawContent(sf::RenderTarget& pSurfaceDeRendu);

	/// deplace le personnage en prenant en compte les murs,
	///		ainsi que les limites de l'ecran (empeche de sortir)
	///		ne gere pas le fait de marcher sur un bonus
	/// 
	/// parametres : 
	/// dirX : 1,0,-1 selon X (colonnes)
	/// dirY : 1,0,-1 selon Y (lignes)
	/// dt_s : delta de temps ecoule, en secondes, depuis la derniere frame
	///
	/// conseil : comparez les valeurs en int, pas en float, pour determiner si le personnage arrive sur un mur.
	void bougerPerso(int dirX, int dirY, float dt_s);

	/// renvoie true si la position arrondie du Personnage est la meme que la position arrondie de la Sortie
	bool isFinished();

	/// si le Personnage se trouve sur un bonus, declenche l'action du bonus, puis supprime le bonus correspondant
	/// de la liste des bonus
	void gererBonus();

	
public: // nos attributs publiques

	
	/// taille de la grille de jeu
	/// les elements ne se deplacent pas pixels par pixels, mais ils se déplacent
	/// et se positionnent dans des "cases" qui correspondent a cette grille.
	/// 
	/// note : il faut effectuer une division flottante pour mWindowSize/mSize pour trouver la taille 
	///			que fait 1 case a l'ecran.
	///
	/// tous les objets font la meme taille et tiennent dans une case. Faites une regle de 3 pour retailler les textures.
	sf::Vector2i mGridSize;

	/// taille de la fenetre de rendu en pixels
	sf::Vector2i mWindowSizePixels;

	/// notre personnage
	//Personnage mPersonnage;

	/// la sortie du niveau
	//Sortie mSortie;
	
	/// les murs qui empechent le personnage d'avancer.
	/// aggregation.
	//std::vector<Mur*> mMurs;

	/// les bonus que le personnage peut prendre.
	/// aggregation.
	//std::vector<Bonus*> mBonus;
	
	/// aggregation des textures deja chargee : [pathTexture, pointeurVersTexture]
	/// 
	/// on peut retrouver une texture depuis son nom avec la methode find().
	/// on peut le parcourir avec un iterator et begin() et end().
	/// on peut ajouter une pair avec insert().
	///
	/// Si vous ne voyez pas comment l'utiliser ou le faire, utilisez directement 
	///  des textures dans vos ObjInteractifs (mais vous n'aurez pas les points correspondant pas a la question naturellement)
	/// (et jetez un oeil sur les exemples du cours, prog10_ExemplesCodesVaries/ExempleMap)
	//std::map<std::string, sf::Texture*> mTextures;
	
};

