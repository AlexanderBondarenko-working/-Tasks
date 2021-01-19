#pragma once

#include "attribute.h"

class DataTemplateStyle : public Attribute {
public:
	DataTemplateStyle(string valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() {
		return "data-template-style";
	}

};