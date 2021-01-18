#pragma once

#include "attribute.h"

class HttpEquiv : public Attribute {
public:
	virtual string getNameOfAttribute() {
		return "http-equiv";
	}

};