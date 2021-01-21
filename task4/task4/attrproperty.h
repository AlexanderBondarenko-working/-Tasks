#pragma once

#include "attribute.h"

class Property : public Attribute {
public:
	Property(const string& valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "property";
	}

};
