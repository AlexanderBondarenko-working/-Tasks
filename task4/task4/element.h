#pragma once

#include <iostream> 
#include <vector> 
#include <string>
#include "subelement.h"
#include "attribute.h"
#include "namesofattributes.h"
#include "namesofelements.h"

using namespace std;

class Element {
protected:
	vector <pair<nameOfAttribute::nameOfAttribute, unique_ptr<Attribute>>> attributes;// name, value
	vector <pair<nameOfSubelement::nameOfSubelement, unique_ptr<SubElement>>> elements;//name, value
	nameOfElement::nameOfElement nameOfElement;
public:
	Element();
	Element(nameOfElement::nameOfElement nameOfElement);
	string getNameOfElement() const;
	void parseAttributesFromString(const string& source);
	void parseElementsFromString(const string& source);
	string objectTostring() const;
	//virtual void selectNameAndValueOfSubelement(string& nameOfElement, string& valueOfElement, const string& source, int& firstPos, int& lastPos);
	//etNameOfElement();
	//void addAttribute(const string& attributeName, const string& attrubuteValue);

	~Element();

};