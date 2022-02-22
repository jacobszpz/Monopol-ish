#ifndef MP_PROPERTY_H
#define MP_PROPERTY_H

#include "CSquare.h"

namespace mp
{
	class CProperty : CSquare
	{
	public:
		CProperty();
	protected:
		float mCost;
		float mRent;
	};
}

#endif
