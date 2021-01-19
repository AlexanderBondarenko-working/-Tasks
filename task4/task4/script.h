#pragma once
#include "subelement.h"

class Script : public SubElement {
public:
	virtual string getNameOfSubelement() const {
		return "script";
	}
};