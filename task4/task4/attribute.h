#pragma once

#include <string>

using namespace std;

class Attribute {
	string valueOfAttribute;
	virtual string getNameOfAttribute() const = 0;
	virtual string getValueOfAttribute() const = 0;

};