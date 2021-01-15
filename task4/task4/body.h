#pragma once

#include <iostream> 
#include <map> 
#include <string>
#include "elementofBody.h"
#include "attribute.h"
using namespace std;

class Body {
	map<string, Attribute> attributes;
	std::multimap <std::string, ElementOfBody> elementsOfBody;
public:
	void parseFromString(string source);
	string objectTostring() const;

};