// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 * "Have your cake and eat it too"
 */

#ifndef MP_CONSTANTS
#define MP_CONSTANTS

#include <string>

// Define pound for WIN32 systems
#ifdef _WIN32
const char POUND = 156;
#endif

// Define pound for other systems
// Since streams works for both char and string,
// there is no problem with the variable type inconsistency
#ifndef _WIN32
const std::string POUND = "£";
#endif

#endif
