#pragma once
#include "subelement.h"

class Link : public SubElement {
public:
	virtual string getNameOfSubelement() const {
		return "link";
	}
};