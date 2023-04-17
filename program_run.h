#ifndef classProgram_run
#define classProgram_run

#include <iostream>
#include <map>
#include <fstream>
#include <chrono>
#include "Document.h"
#include "File_compilation.h"
#include "structPlagerizedSentence.h"

using namespace std;
using namespace std::chrono;


class Program_run : public Document, public file_compialtion
{
private:
	file_compialtion c;
	Document doc;
	vector<plagiarized_sentence> KMP_result;
	vector<plagiarized_sentence> Rabin_result;
	vector<plagiarized_sentence> Hamming_result;
	vector<plagiarized_sentence> Booyer_result;
	vector<plagiarized_sentence> BrutForce_result;
	long long time_KMP;
	long long time_Rabin;
	long long time_Booyer;
	long long time_Hamming;
	long long time_BrutForce;

public:
	map<string, int> results_KMP;
	map<string, int> results_Rabin;
	map<string, int> results_Booyer;
	map<string, int> results_Hamming;

	void check_match_kmp()
	{
		auto start = high_resolution_clock::now();

		for (int i = 0; i < doc.get_sentenses().size(); i++) 
		{
			for (int j = 0; j < c.get_docs().size(); j++) 
			{
				if (c.kmpSearch(doc.manip_sentenses(i), c.manip_docs(j).get_txt())) 
				{
					plagiarized_sentence S;
					S.content = doc.manip_sentenses(i);
					S.doc_dir = c.manip_docs(j).get_directory();
					//results_KMP[S.doc_dir]++;
					KMP_result.push_back(S);
					break;
				}
			}
		}

		auto stop = high_resolution_clock::now();
		auto time_Rabin = duration_cast<microseconds>(stop - start);
	}
	void check_match_rabin()
	{
		auto start = high_resolution_clock::now();

		for (int i = 0; i < doc.get_sentenses().size(); i++)
		{
			for (int j = 0; j < c.get_docs().size(); j++)
			{
				if (c.rabinKarp(doc.manip_sentenses(i), c.manip_docs(j).get_txt()))
				{
					plagiarized_sentence S;
					S.content = doc.manip_sentenses(i);
					S.doc_dir = c.manip_docs(j).get_directory();
					//results_KMP[S.doc_dir]++;
					Rabin_result.push_back(S);
					break;
				}
			}
		}

		auto stop = high_resolution_clock::now();
		auto time_Booyer = duration_cast<microseconds>(stop - start);
	}
	void check_match_Booyer()
	{
		auto start = high_resolution_clock::now();

		for (int i = 0; i < doc.get_sentenses().size(); i++)
		{
			for (int j = 0; j < c.get_docs().size(); j++)
			{
				if (c.boyerMoore(doc.manip_sentenses(i), c.manip_docs(j).get_txt()))
				{
					plagiarized_sentence S;
					S.content = doc.manip_sentenses(i);
					S.doc_dir = c.manip_docs(j).get_directory();
					//results_KMP[S.doc_dir]++;
					Booyer_result.push_back(S);
					break;
				}
			}
		}

		auto stop = high_resolution_clock::now();
		auto time_KMP = duration_cast<microseconds>(stop - start);
	}
	void check_match_hamming()
	{
		auto start = high_resolution_clock::now();

		for (int i = 0; i < doc.get_sentenses().size(); i++)
		{
			for (int j = 0; j < c.get_docs().size(); j++)
			{
				if (c.hammingDistance(doc.manip_sentenses(i), c.manip_docs(j).get_txt()))
				{
					plagiarized_sentence S;
					S.content = doc.manip_sentenses(i);
					S.doc_dir = c.manip_docs(j).get_directory();
					//results_KMP[S.doc_dir]++;
					Hamming_result.push_back(S);
					break;
				}
			}
		}

		auto stop = high_resolution_clock::now();
		auto time_Hamming = duration_cast<microseconds>(stop - start);
	}

	void check_match_brutForce()
	{
		auto start = high_resolution_clock::now();

		for (int i = 0; i < doc.get_sentenses().size(); i++)
		{
			for (int j = 0; j < c.get_docs().size(); j++)
			{
				if (c.bruteForceStringMatch(doc.manip_sentenses(i), c.manip_docs(j).get_txt()))
				{
					plagiarized_sentence S;
					S.content = doc.manip_sentenses(i);
					S.doc_dir = c.manip_docs(j).get_directory();
					//results_KMP[S.doc_dir]++;
					BrutForce_result.push_back(S);
					break;
				}
			}
		}

		auto stop = high_resolution_clock::now();
		auto time_BrutForce = duration_cast<microseconds>(stop - start);
	}


	void get_doc(string file_name)
	{
		doc.set_direcotry(file_name);
		c.initialize_docs();//intialize the docs we have in corpurs
		doc.populate();
		doc.adjustSentence();
	}
};
#endif // !classProgram_run
