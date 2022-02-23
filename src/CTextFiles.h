// Jacob Sánchez Pérez

/** @file
 * @date 2021-04-19
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef JSAN_FILES_H
#define JSAN_FILES_H

#include <string>
#include <vector>

namespace jsan
{
	/**
	 * @brief Helper class for handling contents of text files.
	 */
	class CFiles
	{
	public:
		/**
		 * @brief Retrieve contents of file as lines
		 * @param filename Filename of text file to read.
		 * @param ignoreEmptyLines Whether empty lines should be skipped.
		 * @param commentPrefix Lines starting with this will be skipped.
		 *   Leave empty to disable comments.
		 */
		static std::vector<std::string> GetLinesFromFile(std::string filename,
			bool ignoreEmptyLines, std::string commentPrefix = "//");
		/**
		 * @brief Split a string
		 */
		static std::vector<std::string> Split(std::string line, char sep = '\0');
	};
}

#endif
