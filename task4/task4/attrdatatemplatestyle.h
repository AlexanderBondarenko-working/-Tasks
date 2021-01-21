#pragma once

#include "attribute.h"

class DataTemplateStyle : public Attribute {
public:
	DataTemplateStyle(const string& valueOfAttribute) : Attribute(valueOfAttribute) {}
	virtual string getNameOfAttribute() const {
		return "data-template-style";
	}

};