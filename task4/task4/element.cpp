#include "element.h"
#include "toolsforattributes.h"
#include "toolsforsubelements.h"

Element::Element(nameOfElement::nameOfElement nameOfElement) : nameOfElement(nameOfElement) {}

Element::Element() {}

string Element::objectTostring() const {
	string object = "<";
	object += getNameOfElement();
	for (auto iter = attributes.begin(); iter < attributes.end(); ++iter) {
		object += " "; //in atr
		object += (iter->second)->objToString(); //in atr
	}
	object += ">"; //in atr
	object += "\n"; 
	for (auto iter = elements.begin(); iter < elements.end(); ++iter) {
		object += (iter->second)->objToString();
		object += "\n";
	}
	object += "\n";
	object += "<\/";
	object += getNameOfElement();
	object += ">";
	object += ">\n";
	return object;
}

void Element::parseAttributesFromString(const string& source) {
	toolsForAttributes::convertAttributesToVector(source, this->attributes);//name? convert attributes to vector
}

void Element::parseElementsFromString(const string& source) {
	toolsForSubelements::convertSubelementsToVector(source, elements);//name?
}

string Element::getNameOfElement() const {
	switch (this->nameOfElement) {
	case nameOfElement::BODY:
		return "body";
		break;
	case nameOfElement::HEAD:
		return "head";
		break;
	}
}


Element::~Element() {}