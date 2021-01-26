#include <iostream>
#include "htmldoc.h"
#include "parserfromfile.h"

using namespace std;
int main() {
	ParserFromFile* parser = new ParserFromFile("Source.txt");
	HTMLDoc htmldoc(parser);
	htmldoc.parse();
	htmldoc.addHeadAttribute(nameOfAttribute::CLASS, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	htmldoc.addBodyAttribute(nameOfAttribute::CLASS, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	htmldoc.addHTMLAttribute(nameOfAttribute::CLASS, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	
	//ofstream out("out.txt");
	cout << htmldoc.objectToString() << endl;
	//out.close();
	return 0;
}