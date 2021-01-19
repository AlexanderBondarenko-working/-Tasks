#pragma once
#include "subelement.h"

class Title : public SubElement {
public:
	virtual string getNameOfSubelement() const {
		return "title";
	}
};