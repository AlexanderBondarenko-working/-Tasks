#include "htmldoc.h"
#include <string>
#include <iostream>
#include <fstream>

HTMLDoc::HTMLDoc() {}
HTMLDoc::HTMLDoc(Parser* parser) {
	this->parser = parser;
}
void HTMLDoc::parse() {
	parser->parse(*this, body, head);
}
string HTMLDoc::objectToString() const {
	string object = docType;
	object += "\n<html ";
	for (auto iter = attributes.begin(); iter < attributes.end(); ++iter) {
		object += " ";
		object += (iter->second)->getNameOfAttribute();
		object += "=\"";
		object += (iter->second)->getValueOfAttribute();
		object += "\"";
	}
	object += ">\n";
	//body and head
	object += head.objectTostring();
	object += body.objectTostring();
	object += "<\/html>";
	return object;
}
HTMLDoc::~HTMLDoc() {
	for (auto iter = attributes.begin(); iter < attributes.end(); ++iter) {
		delete (iter->second);
	}
}

void HTMLDoc::addAttribute(Attribute* atr) {
	attributes.push_back(make_pair(atr->getNameOfAttribute(), atr));
}

void HTMLDoc::setDocType(string& source) {
	this->docType = source;
}

void HTMLDoc::parseFromString(string& source) {
	//input : <html .... attributes ... >
	//<html class="js svg svgfilters svgclippaths svgforeignobject smil inlinesvg svgasimg formattribute flexbox csstransforms">
	//none
	//teg and attributes
}
