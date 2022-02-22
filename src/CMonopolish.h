#ifndef MP_MONOPOLISH_H
#define MP_MONOPOLISH_H

#include <vector>
#include "square.h"
#include "player.h"

namespace monopolish
{
	class CMonopolish
	{
	public:
		CMonopolish();
    void Round();
	protected:
	   const unsigned int mRounds = 20;
     std::vector<CPlayer> mPlayers;
	};
}

#endif
