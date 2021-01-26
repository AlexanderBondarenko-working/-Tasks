#pragma once

#include <string>
#include "namesofattributes.h"

using namespace std;

class Attribute {
protected:
	string valueOfAttribute;
	nameOfAttribute::nameOfAttribute nameOfAttribute;
public:
	Attribute(const string& valueOfAttribute, nameOfAttribute::nameOfAttribute nameOfAttribute);
	Attribute();
	//Attribute(const Attribute& source);
	nameOfAttribute::nameOfAttribute getNumberOfName();
	string getNameOfAttribute() const;
	string getValueOfAttribute() const;
	string objToString() const;
	~Attribute() {}
};