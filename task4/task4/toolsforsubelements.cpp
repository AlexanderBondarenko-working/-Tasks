#include "toolsforsubelements.h"

void addSubelementInVector(const string& nameOfElement, const string& attributes, const string& valueOfElement, vector <pair<string, SubElement*>>& subelements) {
	if (nameOfElement == "comment") {
		subelements.push_back(make_pair(nameOfElement, (new Comment(valueOfElement))));
		((subelements.end() - 1)->second)->parseAttributesFromString(attributes);
	}

	if (nameOfElement == "link") {
		subelements.push_back(make_pair(nameOfElement, (new Link(valueOfElement))));
		((subelements.end() - 1)->second)->parseAttributesFromString(attributes);
	}

	if (nameOfElement == "meta") {
		subelements.push_back(make_pair(nameOfElement, (new Meta(valueOfElement))));
		((subelements.end() - 1)->second)->parseAttributesFromString(attributes);
	}

	if (nameOfElement == "script") {
		subelements.push_back(make_pair(nameOfElement, (new Script(valueOfElement))));
		((subelements.end() - 1)->second)->parseAttributesFromString(attributes);
	}

	if (nameOfElement == "title") {
		subelements.push_back(make_pair(nameOfElement, (new Title(valueOfElement))));
		((subelements.end() - 1)->second)->parseAttributesFromString(attributes);
	}

}

void selectAndAddInVectorSubelements(const string& source, vector <pair<string, SubElement*>>& elements) {
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


void selectNameAndValueOfSubelement(string& nameOfElement, string& valueOfElement, const string& source, int& firstPos, int& lastPos) {
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