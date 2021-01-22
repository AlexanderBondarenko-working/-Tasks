#ifndef TASK4_HTMLDOC_H_ 
#define TASK4_HTMLDOC_H_

#include <iostream>
#include <string>
#include "parser.h"
#include  <vector>
#include "attribute.h"
#include "toolsforattributes.h"
#include "namesofattributes.h"
#include "element.h"

class Parser;

class HTMLDoc {
	std::string docType;
	Parser* parser;
	vector <pair<nameOfAttribute::nameOfAttribute, unique_ptr<Attribute>>> attributes;
	Element head;
	Element body;
	
public:
	HTMLDoc();
	HTMLDoc(Parser* parser);
	void parse();
	string objectToString() const;
	~HTMLDoc();
	//void addAttribute(const string& attributeName, const string& attrubuteValue);
	void parseFromString(const string& source);
	void setDocType(const string& source);
};

#endif //TASK4_HTMLDOC_H