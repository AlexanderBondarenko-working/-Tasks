#pragma once
#include <iostream>
#include <string>
#include "htmldoc.h"

class HTMLDoc;

class Parser {
public:
	virtual void parse(HTMLDoc& targetHTMLDoc, Body& bodyTarget, Head& headTarget) const = 0;
	//enum class NamesOfAttributes;

	//NamesOfAttributes getNumberOfAttribute(const string& nameOfAttribute);

	//void addAttributeInVector(const string& attributeName, const string& attrubuteValue, vector <pair<string, Attribute*>>& attributes);
};
