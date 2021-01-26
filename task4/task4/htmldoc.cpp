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
	//attributes
	for (auto iter = attributes.begin(); iter < attributes.end(); ++iter) {
		object += " ";
		object += (iter->second)->objToString();
	}
	object += ">\n";
	//comments
	for (auto iter = comments.begin(); iter < comments.end(); ++iter) {
		object += (iter->second)->objToString();
	}
	object += "\n";
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

void HTMLDoc::addHTMLAttribute(const nameOfAttribute::nameOfAttribute name, const string& value) {
	attributes.push_back(make_pair(name, make_unique<Attribute>(value, name)));
	string message;
	message += "added attribute ";
	message += (attributes.end() - 1)->second->getNameOfAttribute();
	comments.push_back(make_pair(nameOfSubelement::COMMENT, make_unique<SubElement>(message, nameOfSubelement::COMMENT)));
}

void HTMLDoc::addHeadAttribute(const nameOfAttribute::nameOfAttribute name, const string& value) {
	head.addAttribute(name, value);
}

void HTMLDoc::addBodyAttribute(const nameOfAttribute::nameOfAttribute name, const string& value) {
	body.addAttribute(name, value);
}

void HTMLDoc::addSubelementInHead(const SubElement& subelement) {
	head.addSubelement(subelement);
}

void HTMLDoc::addSubelementInBody(const SubElement& subelement) {
	body.addSubelement(subelement);
}
