#pragma once

#include "attribute.h"

class Href : public Attribute {
public:
	Href(const string& valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "href";
	}

};