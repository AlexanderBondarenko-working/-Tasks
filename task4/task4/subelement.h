#pragma once

#include <iostream> 
#include <vector> 
#include <string>
#include "attribute.h"
#include <iterator>
#include "namesofsubelements.h"
#include "namesofattributes.h"

using namespace std;

class SubElement {
protected:
	vector <pair<nameOfAttribute::nameOfAttribute, unique_ptr<Attribute>>> attributes;
	string valueOfSubElement;
	nameOfSubelement::nameOfSubelement nameOfSubelement;
public:
	SubElement(const string& valueOfSubElement, nameOfSubelement::nameOfSubelement nameOfSubelement);
	SubElement();
	SubElement(const SubElement& source);
	string getNameOfSubelement() const;
	string objToString() const;
	//void addAttribute(const string& attributeName, const string& attrubuteValue);
	void parseElementFromString(const string& source);
	void parseAttributesFromString(const string& source);
	//virtual void setValue(const string& source);
	~SubElement();
	void addAttribute(const nameOfAttribute::nameOfAttribute, const string& value);
	nameOfSubelement::nameOfSubelement getNumberOfName() const;
};

