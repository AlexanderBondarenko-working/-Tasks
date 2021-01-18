#pragma once

#include "attribute.h"

class Media : public Attribute {
public:
	virtual string getNameOfAttribute() {
		return "media";
	}

};