//============================================================================
// Name        : Spongebob.cpp
// Author      : T. Peters
// Version     :
// Description : Spongebob text in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctype.h>

using namespace std;

void meme(string text);
int main() {
	meme("Test");
	return 0;
}

void meme(string text){
	string newText;

	for(int i = 0; i < text.length(); ++i){
		if(i % 2 == 0){
			newText += tolower(text.at(i));
		}else
		{
			newText += toupper(text.at(i));
		}
	}

	cout<<newText;
}
