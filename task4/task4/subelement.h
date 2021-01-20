#pragma once

#pragma once
#include <iostream> 
#include <vector> 
#include <string>
#include "attribute.h"
#include <iterator>
using namespace std;


class SubElement {
protected:
	vector <pair<string, Attribute *>> attributes;
	string valueOfSubElement;
public:
	SubElement(const string& valueOfSubElement);
	SubElement();
	virtual string getNameOfSubelement() const = 0;
	virtual string objToString() const;
	//void addAttribute(const string& attributeName, const string& attrubuteValue);
	virtual void parseAttributesFromString(const string& source);
	virtual void setValue(const string& source);
	virtual ~SubElement();
};

