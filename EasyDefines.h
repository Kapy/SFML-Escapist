//auteur : Pierre Morcello

#ifndef EASYDEFINES_H
#define EASYDEFINES_H

#include <sstream>
#include <iostream>

// affiche une message box
// exemple d'usage : 
// MBOX("value of x "<< x <<" and things ");
#define MBOX(X) {std::stringstream box__ss; box__ss << X ; EasyDefines::showMessageBox(box__ss.str());}

// exemple d'usage:
// MWARNING("there is something wrong with "<< element.getName() );
// remarque : si __FUNCTION__ n'est pas portable, dans <boost/current_function.hpp>, BOOST_CURRENT_FUNCTION par contre l'est plus.
#ifndef MWARNING
	#define MWARNING(X) {													\
		MBOX('['<<__FILE__<<':'<<__LINE__<<']'<< X);						\
		std::cout<< '['<<__FILE__<<':'<<__LINE__<< ']' << '('<<__FUNCTION__<<')'<< X << std::endl;	\
	}
#endif

// usage :
// dans une fonction, on assert X sans envoyer d'exception :
//	Si X est faux on affiche un warning, logue, et return Y.
// exemple : 
// int division(int n, int d)
//{
//	MTEST(n!=0, 1); // si le test echoue, cela renvoie 1.
//	return n/d;
//}
#ifndef MTEST
#define MTEST(X,Y){ if(!(X)){ MWARNING( "assert echoue : " << #X ); return Y;} }
#endif

// pour avoir un message de todo affichable dans visual studio.
// exemple d'usage : 
// MTODO("ajouter les asserts");
#ifndef MTODO
	#define MTODO(X) message(__FILE__ ", TODO : " X )
#endif

// pour logguer des informations
// exemple d'usage : 
// MLOG( "test des resources "<<nomResourceA<<" et "<<3.0f );
#ifndef MLOG
	#define MLOG(X) { std::stringstream log__ss; log__ss<<X; EasyDefines::LogHlp::log( log__ss.str() );}
#endif

/// pour loguer uniquement en debug.
#ifndef MDEBUGLOG
	#ifdef _DEBUG
		#define MDEBUGLOG MLOG
	#else
		#define MDEBUGLOG(X) ;
	#endif
#endif

// met a 0 le pointeur, puis detruit ce vers quoi il pointe.
// ne pas l'utiliser sur des tableaux, juste sur des pointeurs simples.
#ifndef MSAFEDELETE
	#define MSAFEDELETE(X) { auto ttemp4del = X; X = NULL; delete ttemp4del; ttemp4del = NULL; }
#endif

// anti-copy et anti-assignation.
#ifndef MANTICOPYCONSTRUCTOR
	#define MANTICOPYCONSTRUCTOR(X)		\
		X(const X&) = delete;			\
		X& operator=(const X&) = delete;
#endif


namespace EasyDefines
{
	/// affiche une box avec le message et attend l'utilisateur.
	void showMessageBox(std::string pText);
	
	/// attend l'utilisateur (appuyer sur entrée..).
	void waitForUser();

	/// classe permettant d'ecrire du texte dans un fichier (principe de log)
	/// note : aucune fonction avancee de log, c'est tres basique.
	class LogHlp
	{
	public:
		/// nom du log (selectionnable uniquement au tout debut)
		static std::string sLogName;

		/// pour ajouter dans un fichier de log les informations
		static void log(const std::string pString);
	};
}

#endif
