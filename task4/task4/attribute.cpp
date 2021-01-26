#include "attribute.h"

Attribute::Attribute() {}

Attribute::Attribute(const string& valueOfAttribute, nameOfAttribute::nameOfAttribute nameOfAttribute) : nameOfAttribute(nameOfAttribute), valueOfAttribute(valueOfAttribute) {}

//Attribute::Attribute(const Attribute& source) {
//	this->valueOfAttribute = source.valueOfAttribute;
//	this->nameOfAttribute = source.nameOfAttribute;
//}

string Attribute::getNameOfAttribute() const {
	switch (this->nameOfAttribute) {
	case nameOfAttribute::ASYNCK:
		return "asynck";
		break;
	case nameOfAttribute::CHARSET:
		return "charset";
		break;
	case nameOfAttribute::CLASS:
		return "class";
		break;
	case nameOfAttribute::CONTENT:
		return "content";
		break;
	case nameOfAttribute::DATA_TEMPLATE_STYLE:
		return "data-template-style";
		break;
	case nameOfAttribute::HREF:
		return "href";
		break;
	case nameOfAttribute::HTTP_EQUIV:
		return "http-equiv";
		break;
	case nameOfAttribute::ID:
		return "id";
		break;
	case nameOfAttribute::MEDIA:
		return "media";
		break;
	case nameOfAttribute::NAME:
		return "name";
		break;
	case nameOfAttribute::PROPERTY:
		return "property";
		break;
	case nameOfAttribute::REL:
		return "rel";
		break;
	case nameOfAttribute::SRC:
		return "src";
		break;
	case nameOfAttribute::TYPE:
		return "type";
		break;
	}
}
string Attribute::getValueOfAttribute() const {
	return valueOfAttribute;
}

nameOfAttribute::nameOfAttribute Attribute::getNumberOfName() {
	return nameOfAttribute;
}

string Attribute::objToString() const {
	string attribute = getNameOfAttribute();
	attribute += "=\"";
	attribute += valueOfAttribute;
	attribute += "\"";
	return attribute;
}