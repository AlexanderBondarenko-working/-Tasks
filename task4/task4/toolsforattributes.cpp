#pragma once
#include "toolsforattributes.h"
#include <vector>


//"asynck" "charset" "class" "content" "data-template-style" "href" "http-equiv" "id" "media" "name" "property" "rel" "src" "type"


void addAttributeInVector(const string& attributeName, const string& attrubuteValue, vector <pair<string, unique_ptr<Attribute>>>& attributes) {
	if (attributeName == "asynck") {
		attributes.push_back(make_pair(attributeName, (make_unique<Asynck>(attrubuteValue))));
	}

	if (attributeName == "charset") {
		attributes.push_back(make_pair(attributeName, (make_unique<Charset>(attrubuteValue))));
	}

	if (attributeName == "class") {
		attributes.push_back(make_pair(attributeName, (make_unique<Class>(attrubuteValue))));
	}

	if (attributeName == "content") {
		attributes.push_back(make_pair(attributeName, (make_unique<Content>(attrubuteValue))));
	}

	if (attributeName == "data-template-style") {
		attributes.push_back(make_pair(attributeName, (make_unique<DataTemplateStyle>(attrubuteValue))));
	}

	if (attributeName == "href") {
		attributes.push_back(make_pair(attributeName, (make_unique<Href>(attrubuteValue))));
	}

	if (attributeName == "http-equiv") {
		attributes.push_back(make_pair(attributeName, (make_unique<HttpEquiv>(attrubuteValue))));
	}

	if (attributeName == "id") {
		attributes.push_back(make_pair(attributeName, (make_unique<Id>(attrubuteValue))));
	}

	if (attributeName == "media") {
		attributes.push_back(make_pair(attributeName, (make_unique<Media>(attrubuteValue))));
	}

	if (attributeName == "property") {
		attributes.push_back(make_pair(attributeName, (make_unique<Property>(attrubuteValue))));
	}

	if (attributeName == "rel") {
		attributes.push_back(make_pair(attributeName, (make_unique<Rel>(attrubuteValue))));
	}

	if (attributeName == "src") {
		attributes.push_back(make_pair(attributeName, (make_unique<Src>(attrubuteValue))));
	}

	if (attributeName == "type") {
		attributes.push_back(make_pair(attributeName, (make_unique<Type>(attrubuteValue))));
	}
}


void selectAndAddInVectorAttributes(const string& source, vector <pair<string, unique_ptr<Attribute>>>& attributes) {
	string attrName;
	string attrValue;
	int firstPos = 0;
	int lastPos = 0;
	while (source.find("=\"", lastPos) != string::npos) {
		if (firstPos == 0) {
			firstPos = source.find(" ", lastPos) + 1;
		}
		else {
			firstPos = source.find("\" ", lastPos) + 2;
		}
		lastPos = source.find("=\"", lastPos);
		attrName = source.substr(firstPos, lastPos - firstPos);

		firstPos = lastPos;
		lastPos = source.find("\"", lastPos + 2);
		attrValue = source.substr(firstPos + 2, lastPos - firstPos - 2);
		addAttributeInVector(attrName, attrValue, attributes);
	}
}