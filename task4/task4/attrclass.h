#pragma once
#include "attribute.h"

class Class : public Attribute {
public:
	Class(string valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() {
		return "class";
	}

};
