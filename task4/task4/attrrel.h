#pragma once

#include "attribute.h"

class Rel : public Attribute {
public:
	Rel(string valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "rel";
	}

};