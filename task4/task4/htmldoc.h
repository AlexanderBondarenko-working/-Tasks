#pragma once

#include <iostream>
#include <string>
#include "body.h"
#include "head.h"
#include "parser.h"

class HTMLDoc {
	std::string doctype;
	Parser parser;
	//attributs for teg html
	Head head;
	Body body;
	void parse(); //call parser

};