#pragma once

#include "ObjInteractif.h"
#include "Niveau.h"

class Mur : public ObjInteractif
{
	Niveau* pParent;
public:

	Mur(Niveau* pParent) : pParent(pParent)
	{}

	~Mur();

private:

};