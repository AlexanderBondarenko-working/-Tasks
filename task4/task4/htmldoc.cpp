#include "htmldoc.h"
#include <string>
#include <iostream>
#include <fstream>
HTMLDoc::HTMLDoc(Parser* parser) {
	this->parser = parser;
}

void HTMLDoc::parse() {
	//call parser.parse
	parser-> parse(*this, body, head);
}

string HTMLDoc::objectToString() const{
	string temp = doctype;
	temp += "\n<html ";
	//temp += cicle for attributes
	temp += ">\n";
	//body and head
	temp += head.objectTostring();
	temp += body.objectTostring();
	temp += "<\\html>";
    return temp;

}

string HTMLDoc::getDoctype() const{

}
string HTMLDoc::getHead() const{

}
string HTMLDoc::getBody() const{

}