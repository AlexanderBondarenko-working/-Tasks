#pragma once

#include "attribute.h"

class Asynck : public Attribute {
public:
	Asynck(const string& valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "asynck";
	}
 

};