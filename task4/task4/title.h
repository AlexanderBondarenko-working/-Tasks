#pragma once
#include "subelement.h"

class Title : public SubElement {
public:
	virtual string getTipe() const {
		return "title";
	}
};