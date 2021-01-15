#pragma once

#include <iostream> 
#include <sstream> 
#include <map> 
#include <string>
#include "elementofhead.h"
using namespace std;

class Head {
	//attributs for teg head
	std::multimap <std::string, ElementOfHead> elementsOfHead;
	void parseFromString(string source);
};
