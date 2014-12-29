#include <SFML/Graphics.hpp>

#include <cmath>
#include <vector>

#include "Niveau.h"

#include "EasyDefines.h"

// fonction principale.
int main()
{

	// TODO lire le fichier xml et initialiser le Niveau.
	//Niveau lNiveau;
	//if (!lNiveau.chargerDepuisFichierXml("datas/Niveau.xml"))
	//{
	//	MWARNING( "Impossible de charger le fichier xml du Niveau." );
	//	return 1;
	//}


	// TODO chargement des textures dans le Niveau.



	// creer la fenetre avec la taille ici du Niveau et lue dans le xml
	sf::RenderWindow lWindow(sf::VideoMode(600, 600, 32), "SFML Escapist");
	sf::Clock lClock;

	while (lWindow.isOpen())
	{
		float lTimeSinceLastFrame = lClock.restart().asSeconds();

		// consommer les evenements windows.
		sf::Event Event;
		while (lWindow.pollEvent(Event))
		{
			// fenetre fermee
			if ((Event.type == sf::Event::Closed) ||
				((Event.type == sf::Event::KeyPressed)
				&& (Event.key.code == sf::Keyboard::Escape)))
			{
				lWindow.close();
				break;
			}
		}

		// TODO bouger le perso
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{

		}

		// TODO gerer les actions des bonus


		// TODO detection de la fin du niveau


		// Nettoyer la surface de rendu (back buffer devient noir)
		lWindow.clear();


		// TODO dessin du Niveau


		// le swap buffer (cf cours 3D "double buffering")
		lWindow.display();
	}

	return EXIT_SUCCESS;
}


