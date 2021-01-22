#include "htmldoc.h"
#include <string>
#include <iostream>
#include <fstream>
#include "toolsforattributes.h"


HTMLDoc::HTMLDoc() : parser(nullptr), head(nameOfElement::HEAD), body(nameOfElement::BODY) {}
HTMLDoc::HTMLDoc(Parser* parser) : head(nameOfElement::HEAD), body(nameOfElement::BODY) {
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
		object += (iter->second)->objToString();
	}
	object += ">\n";
	//body and head
	object += head.objectTostring();
	object += body.objectTostring();
	object += "<\/html>";
	object += ">\n";
	return object;
}
HTMLDoc::~HTMLDoc() {}

void HTMLDoc::setDocType(const string& source) {
	this->docType = source;
}

void HTMLDoc::parseFromString(const string& source) {
	//input : <html .... attributes ... >
	toolsForAttributes::convertAttributesToVector(source, this->attributes);
}
