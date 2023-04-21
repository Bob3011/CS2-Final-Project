#pragma once
#define NO_OF_CHARS 256
#include <iostream>
#include <string>
#include <vector>
#include "Document.h"
class file_compilation
{
private:
	vector<Document> docs;
public:
	file_compilation();
	bool hammingDistance(string text, string pattern);
	vector<int> computeLPS(string pattern);
	bool kmpSearch(string pattern, string text);
	bool rabinKarp(string pat, string txt);
	void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS]);
	bool boyerMoore(string pat, string txt);
	bool bruteForceStringMatch(string pattern, string text);
	vector <Document> get_docs();
	Document manip_docs(int n);
};