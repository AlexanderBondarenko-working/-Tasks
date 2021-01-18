#pragma once

#include "attribute.h"

class Type : public Attribute {
public:
	virtual string getNameOfAttribute() {
		return "type";
	}

};
