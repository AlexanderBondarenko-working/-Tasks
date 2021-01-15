#pragma once

#include <iostream>
#include <string>
#include "body.h"
#include "head.h"
#include "parser.h"
#include  <vector>
#include "attribute.h"

class HTMLDoc {
	std::string doctype;
	Parser* parser;
	vector <pair<string, Attribute>> attributes;
	Head head;
	Body body;
	
public:
	HTMLDoc();
	HTMLDoc(Parser* parser);
	void parse(); //call parser.parse
	string objectToString() const;

	string getDoctype() const;
	string getHead() const;
	string getBody() const;


};