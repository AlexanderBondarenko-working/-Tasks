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
	virtual string getNameOfSubelement() const = 0;
	virtual string objToString() const {
		string object = "<";
		object += getNameOfSubelement();
		for (auto iter = attributes.begin(); iter < attributes.end(); ++iter) {
			object += " ";
			object += (iter->second)->getNameOfAttribute();
			object += "=\"";
			object += (iter->second)->getValueOfAttribute();
			object += "\"";
		}
		object += ">";
		object += valueOfSubElement;
		object += "<\/";
		object += getNameOfSubelement();
		object += ">";
		return object;

	}
	void addAttribute(Attribute* atr) {
		attributes.push_back(make_pair(atr->getNameOfAttribute(), atr));
	}
	virtual ~SubElement() {
		for (auto iter = attributes.begin(); iter < attributes.end(); ++iter) {
			delete (iter->second);
		}
	}
};

