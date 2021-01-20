#pragma once

#include <string>

using namespace std;

class Attribute {
protected:
	string valueOfAttribute;
public:
	Attribute(string valueOfAttribute) : valueOfAttribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const = 0;
	virtual string getValueOfAttribute() const {
		return valueOfAttribute;
	}
	virtual ~Attribute() {}
};