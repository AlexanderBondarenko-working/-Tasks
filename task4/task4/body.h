#pragma once

#include <iostream> 
#include <vector> 
#include <string>
#include "elementofBody.h"
#include "attribute.h"
using namespace std;

class Body {
	vector <pair<string, ElementOfBody>> elementsOfBody;
	vector <pair<string, Attribute>> attributes;
public:
	void parseFromString(string source);
	string objectTostring() const;

};