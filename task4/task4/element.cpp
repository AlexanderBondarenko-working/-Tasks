#include "element.h"
#include "toolsforattributes.h"

string Element::objectTostring() const {
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

void Element::parseAttributesFromString(const string& source) {
	selectAndAddInVectorAttributes(source, this->attributes);
}

void Element::selectNameAndValueOfSubelement(string& nameOfElement, string& valueOfElement, const string& source, int& firstPos, int& lastPos) {
	if (source.find("<!--", firstPos) == firstPos) {
		lastPos = source.find("-->", firstPos);
		nameOfElement = "comment";
		//valueOfElement = source.substr
	}
	else {
		nameOfElement = source.substr(firstPos + 1, lastPos - firstPos - 1);
	}
	firstPos = lastPos;
}

Element::~Element() {
	for (auto iter = attributes.begin(); iter < attributes.end(); ++iter) {
		delete (iter->second);
	}
}