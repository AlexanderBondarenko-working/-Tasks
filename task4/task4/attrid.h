#pragma once

#include "attribute.h"

class Id : public Attribute {
public:
	Id(const string& valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "id";
	}

};