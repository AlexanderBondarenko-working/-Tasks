#pragma once
#include "subelement.h"

class Link : public SubElement {
public:
	virtual string getTipe() const {
		return "link";
	}
};