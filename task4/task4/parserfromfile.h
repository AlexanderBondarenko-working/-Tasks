#pragma once
#include "parser.h"
#include "body.h"
#include "head.h"
#include <fstream>

class ParserFromFile : public Parser {
	string filename;
public:
	ParserFromFile(const string& filename) : filename(filename) {}

	virtual void parse(HTMLDoc& targetHTMLDoc, Element& bodyTarget, Element& headTarget) const;
	void parseHTMLTeg(HTMLDoc& targetHTMLDoc, ifstream& inpt, string& target) const;
	void parseHead(Element& headTarget, ifstream& inpt, string& target) const;
	void parseBody(Element& bodyTarget, ifstream& inpt, string& target) const;
	void parseDocType(HTMLDoc& targetHTMLDoc, ifstream& inpt, string& target) const;
};