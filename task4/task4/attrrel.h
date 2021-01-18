#pragma once

#include "attribute.h"

class Rel : public Attribute {
public:
	virtual string getNameOfAttribute() {
		return "rel";
	}

};