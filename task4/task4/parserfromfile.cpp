#include "parserfromfile.h"

void ParserFromFile::parse(HTMLDoc& targetHTMLDoc, Body& bodyTarget, Head& headTarget) const {
	ifstream inpt(filename);
	if (inpt.is_open()) {

		string stringForOperations;
		//parse doctype
		int lastPos = 0;
		if (!inpt.eof()) {
			parseDocType(targetHTMLDoc, inpt, stringForOperations);
		}

		//parse html-teg with attributes
		if (!inpt.eof()) {
			parseHTMLTeg(targetHTMLDoc, inpt, stringForOperations);
		}

		//parse head-teg with attributes and elements
		if (!inpt.eof()) {
			parseHead(headTarget, inpt, stringForOperations);
		}
		
		//parse body-teg with attributes and elements
		if (!inpt.eof()) {
			parseBody(bodyTarget, inpt, stringForOperations);
		}
		
	}
	inpt.close();
}

void ParserFromFile::parseDocType(HTMLDoc& targetHTMLDoc, ifstream& inpt, string& target) const {
	string tempString;
	int lastPos;
	getline(inpt, tempString);
	target += tempString;
	while (!inpt.eof() && (target.find("<html") == string::npos)) {
		getline(inpt, tempString);
		target += tempString;
	}
	if (target.find("<html") != string::npos) {
		lastPos = target.find("<html");
		tempString = target.substr(0, lastPos);
		targetHTMLDoc.setDocType(tempString);
		target = target.erase(0, lastPos);
	}
}


void ParserFromFile::parseHead(Head& headTarget, ifstream& inpt, string& target) const {
	string tempString;
	int firstPos;
	int lastPos;
	getline(inpt, tempString);
	target += tempString;
	if (target.find("<head") != string::npos)
	{
		firstPos = tempString.find("<head") + 5;
		//attributes
		while (!inpt.eof() && (target.find(">", firstPos) == string::npos)) {
			getline(inpt, tempString);
			target += tempString;
		}
		if (target.find(">", firstPos) != string::npos) {
			lastPos = target.find(">", firstPos);
			tempString = target.substr(0, lastPos + 1);
			headTarget.parseAttributesFromString(tempString);
			target = target.erase(0, lastPos + 1);
		}
		//elements
		while (!inpt.eof() && (target.find("<\/htad>") == string::npos)) {
			getline(inpt, tempString);	
			target += tempString;
		}
		if (target.find("<\/head>", firstPos) != string::npos) {
			lastPos = target.find("<\/head>", firstPos);
			tempString = target.substr(0, lastPos);
			headTarget.parseElementsFromString(tempString);
			target = target.erase(0, lastPos + 7);
		}
	}
}

void ParserFromFile::parseBody(Body& bodyTarget, ifstream& inpt, string& target) const {
	string tempString;
	int firstPos;
	int lastPos;
	getline(inpt, tempString);
	target += tempString;
	if (target.find("<body") != string::npos)
	{
		firstPos = tempString.find("<body") + 5;
		//attributes
		while (!inpt.eof() && (target.find(">", firstPos) == string::npos)) {
			getline(inpt, tempString);
			target += tempString;
		}
		if (target.find(">", firstPos) != string::npos) {
			lastPos = target.find(">", firstPos);
			tempString = target.substr(0, lastPos + 1);
			bodyTarget.parseAttributesFromString(tempString);
			target = target.erase(0, lastPos + 1);
		}
		//elements
		while (!inpt.eof() && (target.find("<\/body>") == string::npos)) {
			getline(inpt, tempString);
			target += tempString;
		}
		if (target.find("<\/body>", firstPos) != string::npos) {
			lastPos = target.find("<\/body>", firstPos);
			tempString = target.substr(0, lastPos);
			bodyTarget.parseElementsFromString(tempString);
			target = target.erase(0, lastPos + 7);
		}
	}
}

void ParserFromFile::parseHTMLTeg(HTMLDoc& targetHTMLDoc, ifstream& inpt, string& target) const{
	string tempString;
	int firstPos;
	int lastPos;
	getline(inpt, tempString);
	target += tempString;
	if (target.find("<html") != string::npos)
	{
		firstPos = target.find("<html") + 5;
		while (!inpt.eof() && (target.find(">", firstPos) == string::npos)) {
			getline(inpt, tempString);
			target += tempString;
		}
		//string & erase(size_type index=0, size_type num = npos); start and quantity
		//
		if (target.find(">", firstPos) != string::npos) {
			lastPos = target.find(">", firstPos);
			tempString = target.substr(0, lastPos + 1);
			targetHTMLDoc.parseFromString(tempString);
			target = target.erase(0, lastPos + 1);
		}
	}

}