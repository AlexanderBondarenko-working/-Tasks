#pragma once

#include "attribute.h"

class Charset : public Attribute {
public:
	Charset(const string& valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "charset";
	}

};
