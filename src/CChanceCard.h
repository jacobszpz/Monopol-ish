#ifndef MP_CHANCE_CARD_H
#define MP_CHANCE_CARD_H

#include <string>

namespace mp
{
	/**
	 * @brief Represents either a Bonus or a Penalty at an appropiate square.
	 */
	class CChanceCard
	{
	public:
		CChanceCard();
		CChanceCard(std::string description, float amount);
	protected:
		std::string mDescription;
		float mAmount;
	};
}

#endif
