#pragma once

#include "attribute.h"

class Asynck : public Attribute {
public:
	Asynck(string valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() {
		return "asynck";
	}

};