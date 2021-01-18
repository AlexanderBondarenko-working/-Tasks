#pragma once
#include "subelement.h"

class Script : public SubElement {
public:
	virtual string getTipe() const {
		return "script";
	}
};