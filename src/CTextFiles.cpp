// Jacob Sánchez Pérez

/** @file
 * @date 2021-04-19
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "CTextFiles.h"

using namespace std;
using namespace jsan;


// Retrieves contents from file in disk as a string
vector<string> CFiles::GetLinesFromFile(string filename, bool ignoreEmptyLines, string commentPrefix)
{
	string line;
	ifstream inputFile(filename);
	vector<string> lines;

	// Open text file and copy all lines that aren't comments
	if (inputFile.is_open())
	{
		while (getline(inputFile, line))
		{
			if ((line[0] != '/' || line[1] != '/') && line != "") { lines.push_back(line); }
        }
		}
		else
		{
			cout << "File IO error when opening " << filename << endl;
		}

		return lines;
}

// Split string into contiguous chunks
vector<string> CFiles::Split(string line, char sep) {
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
