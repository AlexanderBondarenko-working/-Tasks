#pragma once

#include "attribute.h"

class Href : public Attribute {
public:
	virtual string getNameOfAttribute() {
		return "href";
	}

};