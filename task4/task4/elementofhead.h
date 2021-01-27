#pragma once
#include <iostream> 
#include <vector> 
#include <string>
#include "attribute.h"
using namespace std;


class ElementOfHead {
	vector <pair<string, Attribute>> attributes;
	virtual string getTipe() const = 0;
	virtual string objToString() const = 0;
};
