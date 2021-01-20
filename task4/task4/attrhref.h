#pragma once

#include "attribute.h"

class Href : public Attribute {
public:
	Href(string valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "href";
	}

};