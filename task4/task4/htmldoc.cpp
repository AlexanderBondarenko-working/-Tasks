#include "htmldoc.h"
#include <string>
#include <iostream>
#include <fstream>
#include "toolsforattributes.h"


HTMLDoc::HTMLDoc() : parser(nullptr) {}
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

void HTMLDoc::setDocType(const string& source) {
	this->docType = source;
}

void HTMLDoc::parseFromString(const string& source) {
	//input : <html .... attributes ... >
	selectAndAddInVectorAttributes(source, this->attributes);
}
