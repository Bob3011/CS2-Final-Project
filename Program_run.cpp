#ifndef classProgram_run
#define classProgram_run
#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <chrono>
#include"program_run.h"
#include "Document.h"
#include "File_compilation.h"
#include "structPlagerizedSentence.h"

using namespace std;
using namespace std::chrono;

void Program_run::check_match_kmp()
{
	for (int i = 0; i < doc.get_sentenses().size(); i++)
	{
		for (int j = 0; j < c.get_docs().size(); j++)
		{
			if (c.kmpSearch(doc.manip_sentenses(i), c.manip_docs(j).get_txt()))
			{
				plagiarized_sentence S;
				S.content = doc.manip_sentenses(i);
				S.doc_dir = c.manip_docs(j).get_directory();
				KMP_result.push_back(S);
				percentage_KMP.push_back(S.content);
				break;
			}
		}
	}
	KMP_value = (percentage_KMP.size() / doc.get_sentenses().size()) * 100;
}

void Program_run::check_match_rabin()
{
	for (int i = 0; i < doc.get_sentenses().size(); i++)
	{
		for (int j = 0; j < c.get_docs().size(); j++)
		{
			if (c.rabinKarp(doc.manip_sentenses(i), c.manip_docs(j).get_txt()))
			{
				plagiarized_sentence S;
				S.content = doc.manip_sentenses(i);
				S.doc_dir = c.manip_docs(j).get_directory();
				Rabin_result.push_back(S);
				percentage_rabin.push_back(S.content);
				break;
			}
		}
	}
	Rabin_value = (percentage_rabin.size() / doc.get_sentenses().size()) * 100;
}

void Program_run::check_match_Booyer()
{
	for (int i = 0; i < doc.get_sentenses().size(); i++)
	{
		for (int j = 0; j < c.get_docs().size(); j++)
		{
			if (c.boyerMoore(doc.manip_sentenses(i), c.manip_docs(j).get_txt()))
			{
				plagiarized_sentence S;
				S.content = doc.manip_sentenses(i);
				S.doc_dir = c.manip_docs(j).get_directory();
				Booyer_result.push_back(S);
				percentage_Booyer.push_back(S.content);
				break;
			}
		}
	}
	Booyer_value = (percentage_Booyer.size() / doc.get_sentenses().size()) * 100;
}

void Program_run::check_match_hamming()
{
	for (int i = 0; i < doc.get_sentenses().size(); i++)
	{
		for (int j = 0; j < c.get_docs().size(); j++)
		{
			if (c.hammingDistance(doc.manip_sentenses(i), c.manip_docs(j).get_txt()))
			{
				plagiarized_sentence S;
				S.content = doc.manip_sentenses(i);
				S.doc_dir = c.manip_docs(j).get_directory();
				Hamming_result.push_back(S);
				percentage_hamming.push_back(S.content);
				break;
			}
		}
	}
	Hamming_value = (percentage_hamming.size() / doc.get_sentenses().size()) * 100;
}

void Program_run::check_match_brutForce()
{

	for (int i = 0; i < doc.get_sentenses().size(); i++)
	{
		for (int j = 0; j < c.get_docs().size(); j++)
		{
			if (c.bruteForceStringMatch(doc.manip_sentenses(i), c.manip_docs(j).get_txt()))
			{
				plagiarized_sentence S;
				S.content = doc.manip_sentenses(i);
				S.doc_dir = c.manip_docs(j).get_directory();
				BrutForce_result.push_back(S);
				percentage_brutForce.push_back(S.content);
				break;
			}
		}
	}
	BrutForce_value = (percentage_brutForce.size() / doc.get_sentenses().size()) * 100;
}


void Program_run::get_doc(string file_name)
{
	doc.set_directory(file_name);
	doc.populate();
	doc.adjustSentence();
}

plagiarized_sentence Program_run::manip_Hamming_result(int i)
{
	return Hamming_result[i];
}

vector<plagiarized_sentence>Program_run::manip_Hamming()
{
	return Hamming_result;
}

plagiarized_sentence Program_run::manip_Rabin_result(int i)
{
	return Rabin_result[i];
}

vector<plagiarized_sentence>Program_run::manip_Rabin()
{
	return Rabin_result;
}

plagiarized_sentence Program_run::manip_KMP_result(int i)
{
	return KMP_result[i];
}

vector<plagiarized_sentence>Program_run::manip_KMP()
{
	return KMP_result;
}

plagiarized_sentence Program_run::manip_Booyer_result(int i)
{
	return Booyer_result[i];
}

vector<plagiarized_sentence>Program_run::manip_Booyer()
{
	return Booyer_result;
}

plagiarized_sentence Program_run::manip_BrutForce_result(int i)
{
	return BrutForce_result[i];
}

vector<plagiarized_sentence>Program_run::manip_BrutForce()
{
	return BrutForce_result;
}

int Program_run::get_Rabin_value()
{
	return Rabin_value;
}

int Program_run::get_Hamming_value()
{
	return Hamming_value;
}

int Program_run::get_KMP_value()
{
	return KMP_value;
}

int Program_run::get_Booyer_value()
{
	return Booyer_value;
}

int Program_run::get_BrutForce_value()
{
	return BrutForce_value;
}


#endif // !classProgram_run
