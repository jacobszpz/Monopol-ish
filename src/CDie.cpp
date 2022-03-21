#include <iostream>
#include <ctime>
#include <string>
#include "CDie.h"

using namespace std;
using namespace mp;

// Returns a random number in the range 1 .. 6
// Note that I am using casting to convert one data type to another
int CDie::Throw()
{
	return static_cast<int>( static_cast<double> (rand()) / (RAND_MAX + 1u) * 6.0f + 1 );
}


int CDie::main_random()
{
	// A random number generator actually produces a pseudo-random sequence of numbers.
	// This means that the random number generator will always produce the same sequence of numbers.
	// The generator needs to be "seeded" with a value. You seed the generator with the function srand().
	// If you want to create a different sequence of numbers each time then seed it with the time as follows:
	srand( static_cast<unsigned int> (time(0)) );
	// The output of time() is time_t (which is actually an int).
	// static_cast<unsigned int> merely converts the output of time() into an unsigned integer.
	for( int i = 0; i < 10; i++ )
	{
		cout << Throw() << endl;
	}
	cout << endl;

	// However, if you seed the generator with the same value each time then it will always produce
	// the same sequence of numbers. You want this to occur with the Monopoly program.
	// The next bit of code does this:
	srand( 4 );
	for( int i = 0; i < 10; i++ )
	{
		cout << Throw() << endl;
	}
	system( "pause" );

	return 0;
}

void CDie::seed(unsigned seed) {
	srand(seed);
}
