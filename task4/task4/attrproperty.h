#pragma once

#include "attribute.h"

class Property : public Attribute {
public:
	virtual string getNameOfAttribute() {
		return "property";
	}

};
