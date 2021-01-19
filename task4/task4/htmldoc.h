#ifndef TASK4_HTMLDOC_H_ 
#define TASK4_HTMLDOC_H_

#include <iostream>
#include <string>
#include "body.h"
#include "head.h"
#include "parser.h"
#include  <vector>
#include "attribute.h"

class Parser;

class HTMLDoc {
	std::string docType;
	Parser* parser;
	vector <pair<string, Attribute *>> attributes;
	Head head;
	Body body;
	
public:
	HTMLDoc();
	HTMLDoc(Parser* parser);
	void parse();
	string objectToString() const;
	virtual ~HTMLDoc();
	void addAttribute(Attribute* atr);
	void parseFromString(string& source);
	void setDocType(string& source);
};

#endif //TASK4_HTMLDOC_H