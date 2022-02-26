// Jacob Sánchez Pérez

/** @file
 * @date 2021-04-19
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
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

			if (!commentPrefix.empty() && line.length() >= commentPrefix.length())
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
vector<string> CTextFiles::Split(string str, char sep) {
	vector<string> pieces;
	string buffer = "";
	string suffix = " ";

	if (sep)
	{
		suffix = sep;
	}

	str = Strip(str);
	str.append(suffix);

	for (char c : str)
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

string CTextFiles::Strip(string str) {
	str.erase(str.begin(), find_if(str.begin(), str.end(), [](unsigned char ch) {
		return !isspace(ch);
	}));

	str.erase(find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
		return !isspace(ch);
	}).base(), str.end());
	return str;
}
