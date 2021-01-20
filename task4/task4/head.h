#pragma once

#include "element.h" 

using namespace std;

class Head : public Element {
public:
	//virtual void parseAttributesFromString(const string& source);

	//virtual void parseElementsFromString(const string& source);

	virtual string getNameOfElement() const;
    
};
