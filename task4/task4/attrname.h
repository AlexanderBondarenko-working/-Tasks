#pragma once

#include "attribute.h"

class Name : public Attribute {
public:
	virtual string getNameOfAttribute() {
		return "name";
	}

};