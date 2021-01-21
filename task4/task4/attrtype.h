#pragma once

#include "attribute.h"

class Type : public Attribute {
public:
	Type(const string& valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "type";
	}

};
