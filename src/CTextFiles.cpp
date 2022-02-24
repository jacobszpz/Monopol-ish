// Jacob Sánchez Pérez

/** @file
 * @date 2021-04-19
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "CTextFiles.h"

using namespace std;
using namespace jsan;


// Retrieves contents from file in disk as a string
vector<string> CTextFiles::GetLinesFromFile(string filename, bool ignoreEmptyLines, string commentPrefix)
{
	string line;
	ifstream inputFile(filename);
	vector<string> lines;

	// Open text file and copy all lines that aren't comments
	if (inputFile.is_open())
	{
		while (getline(inputFile, line))
		{
			bool isComment = false;

			if (line.length() >= commentPrefix.length())
			{
				string prefix = line.substr(0, commentPrefix.length());
				isComment = (prefix.compare(commentPrefix) == 0);
			}

			if (!isComment && (!ignoreEmptyLines || line.empty()))
			{
				lines.push_back(line);
			}
    }
	}
	else
	{
		throw ios_base::failure("Could not open text file");
	}

		return lines;
}

// Split string into contiguous chunks
vector<string> CTextFiles::Split(string line, char sep) {
	vector<string> pieces;
	string buffer = "";
	line.append(" ");

	for (char c : line)
	{
		bool charIsSep = sep ? (sep == c) : isspace(c);

		if (charIsSep)
		{
			pieces.push_back(buffer);
			buffer = "";
		}
		else
		{
			buffer.append(1, c);
		}
	}

	return pieces;
}
