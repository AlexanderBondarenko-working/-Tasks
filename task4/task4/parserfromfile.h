#pragma once
#include "parser.h"
#include "headersofattributes.h"
#include "headersofsubelements.h"
#include "body.h"
#include "head.h"
#include <fstream>

class ParserFromFile : public Parser {
	string filename;
public:
	ParserFromFile(string filename) : filename(filename) {}

	virtual void parse(HTMLDoc& targetHTMLDoc, Body& bodyTarget, Head& headTarget) const;
	void parseHTMLTeg(HTMLDoc& targetHTMLDoc, ifstream& inpt, string& target) const;
	void parseHead(Head& headTarget, ifstream& inpt, string& target) const;
	void parseBody(Body& bodyTarget, ifstream& inpt, string& target) const;
	void parseDocType(HTMLDoc& targetHTMLDoc, ifstream& inpt, string& target) const;
};