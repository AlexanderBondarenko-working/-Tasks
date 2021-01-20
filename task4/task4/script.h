#pragma once
#include "subelement.h"

class Script : public SubElement {
public:
	Script(const string& valueOfSubElement) : SubElement(valueOfSubElement) {}
	Script() {}
	virtual string getNameOfSubelement() const {
		return "script";
	}
};