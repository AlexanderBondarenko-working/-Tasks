#pragma once

#include "attribute.h"

class Property : public Attribute {
public:
	Property(string valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() {
		return "property";
	}

};
