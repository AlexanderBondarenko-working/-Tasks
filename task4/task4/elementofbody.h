#pragma once
#include "attribute.h"
#include <string>
#include <map>

class ElementOfBody {
	map<string, Attribute> attributes;
	virtual string getTipe() const = 0;
	virtual string objToString() const = 0;
};
