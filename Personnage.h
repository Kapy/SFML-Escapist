#pragma once

#include "ObjInteractif.h"
#include "Niveau.h"

class Personnage : public ObjInteractif
{
	Niveau* pParent;
public:

	Personnage(Niveau* pParent) : pParent(pParent)
	{
		ObjInteractif(pParent, "datas/perso.png");
	}

	~Personnage();

private:
	 
};
