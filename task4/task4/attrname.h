#pragma once

#include "attribute.h"

class Name : public Attribute {
public:
	Name(string valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() {
		return "name";
	}

};