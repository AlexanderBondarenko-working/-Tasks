#pragma once

#include <iostream> 
#include <vector> 
#include <string>
#include "subelement.h"
#include "attribute.h"
using namespace std;

class Element {
protected:
	vector <pair<string, Attribute *>> attributes;// name, value
	vector <pair<string, SubElement *>> elements;//name, value
public:
	virtual string getNameOfElement() const = 0;
	virtual void parseAttributesFromString(const string& source);
	virtual void parseElementsFromString(const string& source) = 0;
	virtual string objectTostring() const;
	virtual void selectNameAndValueOfSubelement(string& nameOfElement, string& valueOfElement, const string& source, int& firstPos, int& lastPos);

	//void addAttribute(const string& attributeName, const string& attrubuteValue);

	virtual ~Element();

};