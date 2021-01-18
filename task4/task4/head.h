#pragma once

#include "element.h" 

using namespace std;

class Head : public Element {
public:
	virtual void parseFromString(string source);
	virtual string getTipe() const {
		return "head";
	}
    
};
