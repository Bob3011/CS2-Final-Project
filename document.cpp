#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Document.h"
using namespace std;

void Document::populate() {
	ifstream instream;
	instream.open(directory);
	string temp, line, sentence;
	string last_sentence;
	while (getline(instream, temp))
	{
		stringstream S(temp);
		bool dot = false;
		int counter = 0; //counter 0 we started a new line, so we cehck if the last char in the last sentence is "." or not

		while (getline(S, sentence, '.')) //get sentences until it finds "."
		{
			if (counter == 0 && dot)
			{
				sentences.push_back(last_sentence + " " + sentence); // push back the whole sentence 
				last_sentence = sentence;
			}
			else
			{
				sentences.push_back(sentence);
				last_sentence = sentence;
				counter++;
			}
		}
		if (temp.size() > 0)
		{
			if (temp[temp.size() - 1] != '.') //check if the last char in the the word = . 
			{
				dot = true;
				sentences.pop_back(); //to remove the sentence if it is not full and put the whole sentence
			}

		}

	}
}
void Document::fillInText() {
	populate();
	adjustSentence();
	text = "";
	for (int i = 0; i < sentences.size(); i++)
	{
		text += sentences[i] + " ";
	}
}
void Document::adjustSentence(){
	for (int i = 0; i < sentences.size(); i++)
	{
		string temp = "";
		bool flag = false;
		for (int j = 0; j < sentences[i].size(); j++)
		{
			if (sentences[i][j] != ' ' && !flag)
			{
				flag = true;
			}
			if (flag)
			{
				temp += sentences[i][j]; //put adjusted sentences in a tepm an then push it back to sentences
			}
		}
		sentences[i] = temp;
	}
}