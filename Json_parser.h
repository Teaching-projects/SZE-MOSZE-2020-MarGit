#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>

class Json_parser{
	public:
	static std::map<std::string, std::string> ParseContent (std::string& filecontent);
	static std::map<std::string, std::string> Parse (const std::string& filename);
	static std::map<std::string, std::string> Parse (const std::istream& datastream);
};

