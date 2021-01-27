#pragma once

#include "attribute.h"

class Media : public Attribute {
public:
	Media(const string& valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "media";
	}

};