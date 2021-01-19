#pragma once

#include "element.h" 

using namespace std;

class Head : public Element {
public:
	virtual void parseAttributesFromString(string source) {
		//none
	}

	virtual void parseElementsFromString(string source) {
		//none
	}
	virtual string getNameOfElement() const {
		return "head";
	}
    
};
