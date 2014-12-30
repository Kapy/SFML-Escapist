#pragma once

#include "ObjInteractif.h"
#include "Niveau.h"

class Personnage : public ObjInteractif
{

public:

	Personnage();
	~Personnage();

	Personnage(Niveau* pParent);

private:
	 
};
