#pragma once
#include <string>
#include <vector>
using namespace std;
class Document {
private:
	string directory;
	string text;
	vector <string> sentences;
public:
	void populate();
	void fillInText();
	void adjustSentence();

	void set_directory(string d);
	string get_directory();
	void set_txt(string t);
	string get_txt();
	vector <string> get_sentenses();
	string manip_sentenses(int n);
	bool check_name(string name);
	void addToDir(double num, string n);
};