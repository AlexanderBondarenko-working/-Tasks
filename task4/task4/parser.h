#pragma once
#include <iostream>
#include <string>
#include "htmldoc.h"
#include "element.h"

class HTMLDoc;

class Parser {
public:
	virtual void parse(HTMLDoc& targetHTMLDoc, Element& bodyTarget, Element& headTarget) const = 0;
};
