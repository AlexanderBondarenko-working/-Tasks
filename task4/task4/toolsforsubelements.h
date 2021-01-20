#pragma once

#include "headersofsubelements.h"

void addSubelementInVector(const string& nameOfElement, const string& attributes, const string& valueOfElement, vector <pair<string, SubElement*>>& subelements);
void selectAndAddInVectorSubelements(const string& source, vector <pair<string, SubElement*>>& elements);
void selectNameAndValueOfSubelement(string& nameOfElement, string& valueOfElement, const string& source, int& firstPos, int& lastPos);
