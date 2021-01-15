#pragma once
#include <iostream> 
#include <map> 
#include <string>
#include "attribute.h"
using namespace std;


class ElementOfHead {
	map<string, Attribute> attributes;
	virtual string getTipe() const = 0;
	virtual string objToString() const = 0;
};
