#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
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
void Document::adjustSentence() {
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
void Document::set_directory(string d)
{
	directory = d;
}

string Document::get_directory()
{
	return directory;
}

void Document::set_txt(string t)
{
	text = t;
}

string Document::get_txt()
{
	return text;
}

vector <string> Document::get_sentenses()
{
	return sentences;
}

string Document::manip_sentenses(int n)
{
	return sentences[n];
}

bool Document::check_name(string name)
{
	bool ans = false;
	ifstream dataBase;
	vector<string> file_names;

	dataBase.open("dataBase.txt");
	if (dataBase.fail())
	{
		cout << "an internal error has occured try again later or contact us for help" << endl;
		exit(1);
	}
	else
	{
		string files;
		while (getline(dataBase, files))
		{
			file_names.push_back(files);
		}

		for (int i = 0; i < file_names.size(); i++)
		{
			if (name == file_names[i])
			{
				ans = true;
				break;
			}
		}

		dataBase.close();
	}
	return ans;
}

void Document :: addToDir(double percentage, string name)
{
	if (percentage < 5)
	{
		ofstream dir;
		dir.open("Dir.txt", ios::app);
		dir << name;
	}
}