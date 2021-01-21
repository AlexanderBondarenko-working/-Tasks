#include <iostream>
#include "htmldoc.h"
#include "parserfromfile.h"

using namespace std;
int main() {
	ParserFromFile* parser = new ParserFromFile("Source.txt");
	HTMLDoc htmldoc(parser);
	htmldoc.parse();
	
	/*ofstream out("out.txt");
	out << htmldoc.objectToString() << endl;
	out.close();*/
	return 0;
}