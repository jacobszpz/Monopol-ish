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
		/**
		 * @brief Create a chance card, a card that holds a description and an amount.
		 * This amount could either be added or substracted from the player's balance.
		 */
		CChanceCard(std::string description, float amount);
		/**
		 * @brief Get the amount of the card.
		 */
		float GetAmount();
		/**
		 * @brief Get the description of the card.
		 */
		std::string GetDescription();
	protected:
		std::string mDescription;
		float mAmount;
	};
}

#endif
