#pragma once

#include "attribute.h"

class Name : public Attribute {
public:
	Name(const string& valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "name";
	}

};