#pragma once
#include "subelement.h"

class Meta : public SubElement {
public:
	virtual string getTipe() const {
		return "meta";
	}
};