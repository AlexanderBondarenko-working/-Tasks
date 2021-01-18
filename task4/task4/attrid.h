#pragma once

#include "attribute.h"

class Id : public Attribute {
public:
	virtual string getNameOfAttribute() {
		return "id";
	}

};