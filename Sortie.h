#pragma once

#include "ObjInteractif.h"
#include "Niveau.h"

class Sortie : public ObjInteractif
{
	Niveau* pParent;
public:

	Sortie(Niveau* pParent) : pParent(pParent)
	{
		ObjInteractif(pParent, "datas/sortie.png");
	}

	~Sortie();

private:

};