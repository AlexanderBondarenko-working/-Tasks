#pragma once
#include "attribute.h"
#include <string>
#include <vector>

class ElementOfBody {
	vector <pair<string, Attribute>> attributes;
	virtual string getTipe() const = 0;
	virtual string objToString() const = 0;
};
