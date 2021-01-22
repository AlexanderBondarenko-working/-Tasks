#include "toolsforsubelements.h"

void toolsForSubelements::addSubelementInVector(const string& nameOfElement, const string& attributes, const string& valueOfElement, vector <pair<nameOfSubelement::nameOfSubelement, unique_ptr<SubElement>>>& subelements) {
	if (nameOfElement == "comment") {
		subelements.push_back(make_pair(nameOfSubelement::COMMENT, (make_unique<SubElement>(valueOfElement, nameOfSubelement::COMMENT))));
		((subelements.end() - 1)->second)->parseAttributesFromString(attributes);
	}

	if (nameOfElement == "link") {
		subelements.push_back(make_pair(nameOfSubelement::LINK, (make_unique<SubElement>(valueOfElement, nameOfSubelement::LINK))));
		((subelements.end() - 1)->second)->parseAttributesFromString(attributes);
	}

	if (nameOfElement == "meta") {
		subelements.push_back(make_pair(nameOfSubelement::META, (make_unique<SubElement>(valueOfElement, nameOfSubelement::META))));
		((subelements.end() - 1)->second)->parseAttributesFromString(attributes);
	}

	if (nameOfElement == "script") {
		subelements.push_back(make_pair(nameOfSubelement::SCRIPT, (make_unique<SubElement>(valueOfElement, nameOfSubelement::SCRIPT))));
		((subelements.end() - 1)->second)->parseAttributesFromString(attributes);
	}

	if (nameOfElement == "title") {
		subelements.push_back(make_pair(nameOfSubelement::TITLE, (make_unique<SubElement>(valueOfElement, nameOfSubelement::TITLE))));
		((subelements.end() - 1)->second)->parseAttributesFromString(attributes);
	}

}

void toolsForSubelements::convertSubelementsToVector(const string& source, vector <pair<nameOfSubelement::nameOfSubelement, unique_ptr<SubElement>>>& elements) {
	int firstPos = 0;
	int lastPos = 0;
	string tempString;
	string nameOfElement;
	string valueOfElement;
	string attributes;

	while (source.find("<", lastPos) != string::npos) {
		firstPos = source.find("<", lastPos);
		if ((source.find(">", firstPos) != string::npos) && (firstPos != source.find("<\/", lastPos)))
		{
			lastPos = source.find(">", firstPos);
			selectNameAndValueOfSubelement(nameOfElement, valueOfElement, source, firstPos, lastPos);
			if (nameOfElement.find("=\"") != string::npos)
			{
				attributes = nameOfElement.substr(nameOfElement.find(" ") + 1);
				nameOfElement = nameOfElement.substr(0, nameOfElement.find(" "));
			}
			addSubelementInVector(nameOfElement, attributes, valueOfElement, elements);
			attributes.erase();
		}
		else if ((source.find(">", firstPos) != string::npos) && (firstPos == source.find("<\/", lastPos))) {
			firstPos = source.find("<\/", lastPos);
			lastPos = source.find(">", firstPos);
			firstPos = lastPos;
		}

		
	}


}


void toolsForSubelements::selectNameAndValueOfSubelement(string& nameOfElement, string& valueOfElement, const string& source, int& firstPos, int& lastPos) {
	if (source.find("<!--", firstPos) == firstPos) {
		lastPos = source.find("-->", firstPos);
		nameOfElement = "comment";
		valueOfElement = source.substr(firstPos + 4, lastPos - firstPos - 4);
	}
	else {
		nameOfElement = source.substr(firstPos + 1, lastPos - firstPos - 1);
		valueOfElement = source.substr(lastPos + 1, source.find("<", lastPos) - lastPos - 1);
	}
	firstPos = lastPos;
}