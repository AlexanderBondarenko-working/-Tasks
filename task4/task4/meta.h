#pragma once
#include "subelement.h"

class Meta : public SubElement {
public:
	Meta(const string& valueOfSubElement) : SubElement(valueOfSubElement) {}
	Meta() {}
	virtual string getNameOfSubelement() const {
		return "meta";
	}
};