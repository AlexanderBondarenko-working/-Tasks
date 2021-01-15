#pragma once

#include <iostream> 
#include <map> 
#include <string>
#include "elementofhead.h"
#include "attribute.h"
using namespace std;

class Head {
	map<string, Attribute> attributes;
	multimap <string, ElementOfHead> elementsOfHead;
public:
	void parseFromString(string source);
	string objectTostring() const;
    
};
