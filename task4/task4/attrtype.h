#pragma once

#include "attribute.h"

class Type : public Attribute {
public:
	Type(string valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "type";
	}

};
