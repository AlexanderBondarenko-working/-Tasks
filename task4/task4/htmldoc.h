#pragma once

#include <iostream>
#include <string>
#include "body.h"
#include "head.h"
#include "parser.h"
#include  <map>
#include "attribute.h"

class HTMLDoc {
	std::string doctype;
	Parser parser;
	map<string, Attribute> attributes;
	Head head;
	Body body;
	
public:
	void parse(); //call parser.parse
	string objectToString() const;

	string getDoctype() const;
	string getHead() const;
	string getBody() const;


};