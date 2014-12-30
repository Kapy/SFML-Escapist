#pragma once

#include "ObjInteractif.h"
#include "Niveau.h"

class Bonus : public ObjInteractif
{
	Niveau* pParent;
public:

	Bonus(Niveau* pParent) : pParent(pParent)
	{
		ObjInteractif(pParent, "datas/bonus.png");
	}

	~Bonus();

private:

};