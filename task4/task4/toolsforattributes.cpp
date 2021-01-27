#pragma once
#include "toolsforattributes.h"
#include <vector>


//"asynck" "charset" "class" "content" "data-template-style" "href" "http-equiv" "id" "media" "name" "property" "rel" "src" "type"


void toolsForAttributes::addAttributeInVector(const string& attributeName, const string& attrubuteValue, vector <pair<nameOfAttribute::nameOfAttribute, unique_ptr<Attribute>>>& attributes) {
	if (attributeName == "asynck") {
		attributes.push_back(make_pair(nameOfAttribute::ASYNCK, (make_unique<Attribute>(attrubuteValue, nameOfAttribute::ASYNCK))));
	}

	if (attributeName == "charset") {
		attributes.push_back(make_pair(nameOfAttribute::CHARSET, (make_unique<Attribute>(attrubuteValue, nameOfAttribute::CHARSET))));
	}

	if (attributeName == "class") {
		attributes.push_back(make_pair(nameOfAttribute::CLASS, (make_unique<Attribute>(attrubuteValue, nameOfAttribute::CLASS))));
	}

	if (attributeName == "content") {
		attributes.push_back(make_pair(nameOfAttribute::CONTENT, (make_unique<Attribute>(attrubuteValue, nameOfAttribute::CONTENT))));
	}

	if (attributeName == "data-template-style") {
		attributes.push_back(make_pair(nameOfAttribute::DATA_TEMPLATE_STYLE, (make_unique<Attribute>(attrubuteValue, nameOfAttribute::DATA_TEMPLATE_STYLE))));
	}

	if (attributeName == "href") {
		attributes.push_back(make_pair(nameOfAttribute::HREF, (make_unique<Attribute>(attrubuteValue, nameOfAttribute::HREF))));
	}

	if (attributeName == "http-equiv") {
		attributes.push_back(make_pair(nameOfAttribute::HTTP_EQUIV, (make_unique<Attribute>(attrubuteValue, nameOfAttribute::HTTP_EQUIV))));
	}

	if (attributeName == "id") {
		attributes.push_back(make_pair(nameOfAttribute::ID, (make_unique<Attribute>(attrubuteValue, nameOfAttribute::ID))));
	}

	if (attributeName == "media") {
		attributes.push_back(make_pair(nameOfAttribute::MEDIA, (make_unique<Attribute>(attrubuteValue, nameOfAttribute::MEDIA))));
	}

	if (attributeName == "property") {
		attributes.push_back(make_pair(nameOfAttribute::PROPERTY, (make_unique<Attribute>(attrubuteValue, nameOfAttribute::PROPERTY))));
	}

	if (attributeName == "rel") {
		attributes.push_back(make_pair(nameOfAttribute::REL, (make_unique<Attribute>(attrubuteValue, nameOfAttribute::REL))));
	}

	if (attributeName == "src") {
		attributes.push_back(make_pair(nameOfAttribute::SRC, (make_unique<Attribute>(attrubuteValue, nameOfAttribute::SRC))));
	}

	if (attributeName == "type") {
		attributes.push_back(make_pair(nameOfAttribute::TYPE, (make_unique<Attribute>(attrubuteValue, nameOfAttribute::TYPE))));
	}
}


void toolsForAttributes::convertAttributesToVector(const string& source, vector <pair<nameOfAttribute::nameOfAttribute, unique_ptr<Attribute>>>& attributes) {
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