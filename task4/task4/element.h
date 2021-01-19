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
	virtual void parseAttributesFromString(string source) = 0;
	virtual void parseElementsFromString(string source) = 0;
	virtual string objectTostring() const {
		string object = "<";
		object += getNameOfElement();
		for (auto iter = attributes.begin(); iter < attributes.end(); ++iter) {
			object += " ";
			object += (iter->second)->getNameOfAttribute();
			object += "=\"";
			object += (iter->second)->getValueOfAttribute();
			object += "\"";
		}
		object += ">";
		object += "\n";
		for (auto iter = elements.begin(); iter < elements.end(); ++iter) {
			object += (iter->second)->objToString();
			object += "\n";
		}
		object += "\n";
		object += "<\/";
		object += getNameOfElement();
		object += ">";
		return object;
	}

	void addAttribute(Attribute* atr) {
		attributes.push_back(make_pair(atr->getNameOfAttribute(), atr));
	}

	virtual ~Element(){
		for (auto iter = attributes.begin(); iter < attributes.end(); ++iter) {
			delete (iter->second);
		}
	}

};