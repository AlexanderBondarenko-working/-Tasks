#pragma once

#include <string>

using namespace std;

class Attribute {
	string valueOfAttribute;
public:
	virtual string getNameOfAttribute() const = 0;
	virtual string getValueOfAttribute() const {
		return valueOfAttribute;
	}

};