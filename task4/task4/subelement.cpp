#include "subelement.h"
#include "toolsforattributes.h"

SubElement::SubElement(const string& valueOfSubElement, nameOfSubelement::nameOfSubelement nameOfSubelement) : valueOfSubElement(valueOfSubElement), nameOfSubelement(nameOfSubelement) {}

SubElement::SubElement() {}

string SubElement::objToString() const {
	string object;
	if (nameOfSubelement == nameOfSubelement::COMMENT) {
		object += "<!--";
		object += valueOfSubElement;
		object += "-->";
		return object;
	}
	object = "<";
	object += getNameOfSubelement();
	for (auto iter = attributes.begin(); iter < attributes.end(); ++iter) {
		object += " ";
		object += (iter->second)->objToString();
	}
	object += ">";
	object += valueOfSubElement;
	object += "<\/";
	object += getNameOfSubelement();
	object += ">";
	return object;

}
void SubElement::parseAttributesFromString(const string& source) {
	toolsForAttributes::convertAttributesToVector(source, this->attributes);
}

void SubElement::parseElementFromString(const string& source) {
	valueOfSubElement = source;
}
//void SubElement::setValue(const string& sourse) {
//	valueOfSubElement = sourse;
//}

string SubElement::getNameOfSubelement() const {
	switch (this->nameOfSubelement) {
	case nameOfSubelement::COMMENT:
		return "comment";
		break;
	case nameOfSubelement::LINK:
		return "link";
		break;
	case nameOfSubelement::META:
		return "meta";
		break;
	case nameOfSubelement::SCRIPT:
		return "script";
		break;
	case nameOfSubelement::TITLE:
		return "title";
		break;
	}
	return "";
}
SubElement::~SubElement() {}