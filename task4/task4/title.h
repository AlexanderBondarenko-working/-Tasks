#pragma once
#include "subelement.h"

class Title : public SubElement {
public:
	Title(const string& valueOfSubElement) : SubElement(valueOfSubElement) {}
	Title() {}
	virtual string getNameOfSubelement() const {
		return "title";
	}
};