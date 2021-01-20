#pragma once

#include "attribute.h"

class Content : public Attribute {
public:
	Content(string valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "content";
	}

};
