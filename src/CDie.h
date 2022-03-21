// Jacob Sánchez Pérez

/** @file
 *
 */

#ifndef RANDOM_H
#define RANDOM_H

#include <string>

/**
 * @brief Pseudo-random number generator.
 * The throw function was implemented as a static method
 * because srand() & rand() affect the global state anyway.
 */
class CDie
{
public:
	/**
	 * @brief Returns a random number in the range 1 .. 6.
	 */
	static int Throw();
	/**
	 * @brief Small demonstration of the Random() method.
	 */
	static int main_random();
	static void seed();
	static const std::string seedFile;
};


#endif
