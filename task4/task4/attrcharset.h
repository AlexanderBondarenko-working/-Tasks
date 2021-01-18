#pragma once

#include "attribute.h"

class Charset : public Attribute {
public:
	virtual string getNameOfAttribute() {
		return "charset";
	}

};
