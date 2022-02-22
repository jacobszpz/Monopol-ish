#ifndef MP_SQUARE_FACTORY_H
#define MP_SQUARE_FACTORY_H

#include <string>
#include "CSquare.h"

namespace monopolish
{
	class CSquareFactory
	{
	public:
		static CSquare parseString(std::string propertyLine);
	};
}

#endif
