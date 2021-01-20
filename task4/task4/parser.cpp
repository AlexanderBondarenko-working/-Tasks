#include "parser.h"

//enum class Parser::NamesOfAttributes
//{
//	ASYNCK,
//	CHARSET,
//	CLASS,
//	CONTENT,
//	DATA_TEMPLATE_STYLE,
//	HREF,
//	HTTP_EQUIV,
//	ID,
//	MEDIA,
//	NAME,
//	PROPERTY,
//	REL,
//	SRC,
//	TYPE,
//	DEFOULT
//};
//
//Parser::NamesOfAttributes Parser::getNumberOfAttribute(const string& nameOfAttribute) {
//	if (nameOfAttribute == "asynck") {
//		return NamesOfAttributes::ASYNCK;
//	}
//
//	if (nameOfAttribute == "charset") {
//		return NamesOfAttributes::CHARSET;
//	}
//
//	if (nameOfAttribute == "class") {
//		return NamesOfAttributes::CLASS;
//	}
//
//	if (nameOfAttribute == "content") {
//		return NamesOfAttributes::CONTENT;
//	}
//
//	if (nameOfAttribute == "data-template-style") {
//		return NamesOfAttributes::DATA_TEMPLATE_STYLE;
//	}
//
//	if (nameOfAttribute == "href") {
//		return NamesOfAttributes::HREF;
//	}
//
//	if (nameOfAttribute == "http-equiv") {
//		return NamesOfAttributes::HTTP_EQUIV;
//	}
//
//	if (nameOfAttribute == "id") {
//		return NamesOfAttributes::ID;
//	}
//
//	if (nameOfAttribute == "media") {
//		return NamesOfAttributes::MEDIA;
//	}
//
//	if (nameOfAttribute == "property") {
//		return NamesOfAttributes::PROPERTY;
//	}
//
//	if (nameOfAttribute == "rel") {
//		return NamesOfAttributes::REL;
//	}
//
//	if (nameOfAttribute == "src") {
//		return NamesOfAttributes::SRC;
//	}
//
//	if (nameOfAttribute == "type") {
//		return NamesOfAttributes::TYPE;
//	}
//	return NamesOfAttributes::DEFOULT;
//}
////"asynck" "charset" "class" "content" "data-template-style" "href" "http-equiv" "id" "media" "name" "property" "rel" "src" "type"
//
//void Parser::addAttributeInVector(const string& attributeName, const string& attrubuteValue, vector <pair<string, Attribute*>>& attributes) {
//	switch (getNumberOfAttribute(attributeName)) {
//	case NamesOfAttributes::ASYNCK:
//		attributes.push_back(make_pair(attributeName, (new Asynck(attrubuteValue))));
//		break;
//	case NamesOfAttributes::CHARSET:
//		attributes.push_back(make_pair(attributeName, (new Charset(attrubuteValue))));
//		break;
//	case NamesOfAttributes::CLASS:
//		attributes.push_back(make_pair(attributeName, (new Class(attrubuteValue))));
//		break;
//	case NamesOfAttributes::CONTENT:
//		attributes.push_back(make_pair(attributeName, (new Content(attrubuteValue))));
//		break;
//	case NamesOfAttributes::DATA_TEMPLATE_STYLE:
//		attributes.push_back(make_pair(attributeName, (new DataTemplateStyle(attrubuteValue))));
//		break;
//	case NamesOfAttributes::HREF:
//		attributes.push_back(make_pair(attributeName, (new Href(attrubuteValue))));
//		break;
//	case NamesOfAttributes::HTTP_EQUIV:
//		attributes.push_back(make_pair(attributeName, (new HttpEquiv(attrubuteValue))));
//		break;
//	case NamesOfAttributes::ID:
//		attributes.push_back(make_pair(attributeName, (new Id(attrubuteValue))));
//		break;
//	case NamesOfAttributes::MEDIA:
//		attributes.push_back(make_pair(attributeName, (new Media(attrubuteValue))));
//		break;
//	case NamesOfAttributes::PROPERTY:
//		attributes.push_back(make_pair(attributeName, (new Property(attrubuteValue))));
//		break;
//	case NamesOfAttributes::REL:
//		attributes.push_back(make_pair(attributeName, (new Rel(attrubuteValue))));
//		break;
//	case NamesOfAttributes::SRC:
//		attributes.push_back(make_pair(attributeName, (new Src(attrubuteValue))));
//		break;
//	case NamesOfAttributes::TYPE:
//		attributes.push_back(make_pair(attributeName, (new Type(attrubuteValue))));
//		break;
//	}
//}