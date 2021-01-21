#pragma once

#include "attribute.h"

class Content : public Attribute {
public:
	Content(const string& valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "content";
	}

};
