#pragma once

#include "attribute.h"

class Src : public Attribute {
public:
	virtual string getNameOfAttribute() {
		return "src";
	}

};
