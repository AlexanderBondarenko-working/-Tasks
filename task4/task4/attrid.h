#pragma once

#include "attribute.h"

class Id : public Attribute {
public:
	Id(string valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() {
		return "id";
	}

};