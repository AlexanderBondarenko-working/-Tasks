#pragma once

#include "attribute.h"

class DataTemplateStyle : public Attribute {
public:
	virtual string getNameOfAttribute() {
		return "data-template-style";
	}

};