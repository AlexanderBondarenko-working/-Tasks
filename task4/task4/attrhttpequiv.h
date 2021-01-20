#pragma once

#include "attribute.h"

class HttpEquiv : public Attribute {
public:
	HttpEquiv(string valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "http-equiv";
	}

};