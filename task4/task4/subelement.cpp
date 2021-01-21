#include "subelement.h"
#include "toolsforattributes.h"

SubElement::SubElement(const string& valueOfSubElement) : valueOfSubElement(valueOfSubElement) {}

SubElement::SubElement() {}

string SubElement::objToString() const {
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
void SubElement::parseAttributesFromString(const string& source) {
	selectAndAddInVectorAttributes(source, this->attributes);
}

void SubElement::parseElementFromString(const string& source) {
	valueOfSubElement = source;
}
//void SubElement::setValue(const string& sourse) {
//	valueOfSubElement = sourse;
//}
SubElement::~SubElement() {}