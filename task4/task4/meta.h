#pragma once
#include "subelement.h"

class Meta : public SubElement {
public:
	virtual string getNameOfSubelement() const {
		return "meta";
	}
};