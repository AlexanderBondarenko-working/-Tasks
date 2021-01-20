#pragma once
#include "subelement.h"

class Link : public SubElement {
public:
	Link(const string& valueOfSubElement) : SubElement(valueOfSubElement) {}
	Link() {}
	virtual string getNameOfSubelement() const {
		return "link";
	}
};