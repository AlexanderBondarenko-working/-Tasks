#pragma once

#pragma once
#include "subelement.h"

class Comment : public SubElement {
public:
	virtual string getNameOfSubelement() const {
		return "comment";
	}
	virtual string objToString() const {
		string object = "<!--";
		object += valueOfSubElement;
		object += "-->";
		return object;

	}
};