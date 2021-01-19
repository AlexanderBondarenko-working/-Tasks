#pragma once
#include <iostream>
#include <string>
#include "htmldoc.h"

class HTMLDoc;

class Parser {
public:
	virtual void parse(HTMLDoc& targetHTMLDoc, Body& bodyTarget, Head& headTarget) const = 0;
};
