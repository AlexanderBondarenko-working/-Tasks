#pragma once

#include "attribute.h"

class Media : public Attribute {
public:
	Media(string valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "media";
	}

};