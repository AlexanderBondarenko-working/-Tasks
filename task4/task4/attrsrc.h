#pragma once

#include "attribute.h"

class Src : public Attribute {
public:
	Src(string valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() {
		return "src";
	}

};
