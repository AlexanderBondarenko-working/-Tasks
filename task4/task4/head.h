#pragma once

#include <iostream> 
#include <map> 
#include <string>
#include "elementofhead.h"
#include "attribute.h"
#include <vector>
using namespace std;

class Head {
	vector <pair<string, ElementOfHead>> elementsOfHead;
	vector <pair<string, Attribute>> attributes;
public:
	void parseFromString(string source);
	string objectTostring() const;
    
};
