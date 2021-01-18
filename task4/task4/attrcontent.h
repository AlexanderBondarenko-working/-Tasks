#pragma once

#include "attribute.h"

class Content : public Attribute {
public:
	virtual string getNameOfAttribute() {
		return "content";
	}

};
