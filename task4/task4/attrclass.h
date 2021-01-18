#pragma once
#include "attribute.h"

class Class : public Attribute {
public:
	virtual string getNameOfAttribute() {
		return "class";
	}

};
