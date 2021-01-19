#pragma once

#include "attribute.h"

class Charset : public Attribute {
public:
	Charset(string valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() {
		return "charset";
	}

};
