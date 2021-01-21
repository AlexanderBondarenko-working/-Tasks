#pragma once

#include <string>

using namespace std;

class Attribute {
protected:
	string valueOfAttribute;
public:
	Attribute(const string& valueOfAttribute) : valueOfAttribute(valueOfAttribute) {}
	Attribute() {}
	virtual string getNameOfAttribute() const = 0;
	virtual string getValueOfAttribute() const {
		return valueOfAttribute;
	}
	virtual ~Attribute() {}
};