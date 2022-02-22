#ifndef MP_PROPERTY_H
#define MP_PROPERTY_H

#include "square.h"

namespace monopolish
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
