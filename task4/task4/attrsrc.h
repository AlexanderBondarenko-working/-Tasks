#pragma once

#include "attribute.h"

class Src : public Attribute {
public:
	Src(const string& valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "src";
	}

};
