#pragma once

#include "subelement.h"
#include "namesofsubelements.h"

namespace toolsForSubelements {
	void addSubelementInVector(const string& nameOfElement, const string& attributes, const string& valueOfElement, vector <pair<nameOfSubelement::nameOfSubelement, unique_ptr<SubElement>>>& subelements);
	void convertSubelementsToVector(const string& source, vector <pair<nameOfSubelement::nameOfSubelement, unique_ptr<SubElement>>>& elements);
	void selectNameAndValueOfSubelement(string& nameOfElement, string& valueOfElement, const string& source, int& firstPos, int& lastPos);
}