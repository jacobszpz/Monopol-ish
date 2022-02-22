#ifndef MP_SQUARE_H
#define MP_SQUARE_H

#include <string>

namespace mp
{
	class CSquare
	{
	public:
		enum class EPropertyType
		{
			Property = 1,
			Start = 2,
			BusStation = 3,
			Bonus = 4,
			Penalty = 5,
			Jail = 6,
			GoToJail = 7,
			FreeParking = 8
		};
		CSquare(std::string);
	protected:
		std::string mName;
		EPropertyType mType;

	};
}

#endif
