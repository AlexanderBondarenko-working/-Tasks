#pragma once

#pragma once
#include <iostream> 
#include <vector> 
#include <string>
#include "attribute.h"
#include <iterator>
using namespace std;


class SubElement {
	vector <pair<string, Attribute>> attributes;
	string valueOfSubElement;
public:
	virtual string getTipe() const = 0;
	virtual string objToString() const {
		string object = "<";
		object += getTipe();
		for (auto iter = attributes.begin(); iter < attributes.end(); ++iter) {
			object += " ";
			object += (iter->second).getNameOfAttribute();
			object += "=\"";
			object += (iter->second).getValueOfAttribute();
			object += "\"";
		}
		object += ">";
		object += valueOfSubElement;
		object += "</";
		object += getTipe();
		object += ">";
		return object;

	}
};

