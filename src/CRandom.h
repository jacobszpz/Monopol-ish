// Jacob Sánchez Pérez

/** @file
 *
 */

#ifndef RANDOM_H
#define RANDOM_H

/**
 * @brief Pseudo-random number generator.
 */
class CRandom
{
public:
	/**
	 * @brief Returns a random number in the range 1 .. 6.
	 */
	static int Random();
	/**
	 * @brief Small demonstration of the Random() method.
	 */
	static int main_random();
};


#endif
