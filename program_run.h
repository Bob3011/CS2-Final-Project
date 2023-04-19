#ifndef classProgram_run
#define classProgram_run
#pragma once
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
	vector<string> percentage_KMP;
	vector<string> percentage_hamming;
	vector<string> percentage_Booyer;
	vector<string> percentage_rabin;
	vector<string> percentage_brutForce;
	/*long long time_KMP;
	long long time_Rabin;
	long long time_Booyer;
	long long time_Hamming;
	long long time_BrutForce;*/
	int Rabin_value;
	int Hamming_value;
	int KMP_value;
	int Booyer_value;
	int BrutForce_value;

public:

	void check_match_kmp()
	{
		//auto start = high_resolution_clock::now();

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
		//auto stop = high_resolution_clock::now();
		//auto time_Rabin = duration_cast<microseconds>(stop - start);
	}
	void check_match_rabin()
	{
		//auto start = high_resolution_clock::now();

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
		//auto stop = high_resolution_clock::now();
		//auto time_Booyer = duration_cast<microseconds>(stop - start);
	}
	void check_match_Booyer()
	{
		//auto start = high_resolution_clock::now();

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
		//auto stop = high_resolution_clock::now();
		//auto time_KMP = duration_cast<microseconds>(stop - start);
	}
	void check_match_hamming()
	{
		//auto start = high_resolution_clock::now();

		for (int i = 0; i < doc.get_sentenses().size(); i++)
		{
			for (int j = 0; j < c.get_docs().size(); j++)
			{
				if (c.hammingDistance(doc.manip_sentenses(i),c.manip_docs(j).get_txt()))
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
		//auto stop = high_resolution_clock::now();
		//auto time_Hamming = duration_cast<microseconds>(stop - start);
	}

	void check_match_brutForce()
	{
		//auto start = high_resolution_clock::now();

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
		//auto stop = high_resolution_clock::now();
		//auto time_BrutForce = duration_cast<microseconds>(stop - start);
	}


	void get_doc(string file_name)
	{
		doc.set_direcotry(file_name);
		//c.initialize_docs();//intialize the docs we have in corpurs
		doc.populate();
		doc.adjustSentence();
	}

	plagiarized_sentence manip_Hamming_result(int i)
	{
		return Hamming_result[i];
	}

	vector<plagiarized_sentence> manip_Hamming()
	{
		return Hamming_result;
	}

	plagiarized_sentence manip_Rabin_result(int i)
	{
		return Rabin_result[i];
	}

	vector<plagiarized_sentence> manip_Rabin()
	{
		return Rabin_result;
	}

	plagiarized_sentence manip_KMP_result(int i)
	{
		return KMP_result[i];
	}

	vector<plagiarized_sentence> manip_KMP()
	{
		return KMP_result;
	}

	plagiarized_sentence manip_Booyer_result(int i)
	{
		return Booyer_result[i];
	}

	vector<plagiarized_sentence> manip_Booyer()
	{
		return Booyer_result;
	}

	plagiarized_sentence manip_BrutForce_result(int i)
	{
		return BrutForce_result[i];
	}

	vector<plagiarized_sentence> manip_BrutForce()
	{
		return BrutForce_result;
	}

	/*long long get_hamming_time()
	{
		return time_Hamming;
	}

	long long get_KMP_time()
	{
		return time_KMP;
	}

	long long get_Booyer_time()
	{
		return time_Booyer;
	}

	long long get_Rabin_time()
	{
		return time_Rabin;
	}

	long long get_BrutForce_time()
	{
		return time_BrutForce;
	}*/

	int get_Rabin_value()
	{
		return Rabin_value;
	}

	int get_Hamming_value()
	{
		return Rabin_value;
	}

	int get_KMP_value()
	{
		return Rabin_value;
	}

	int get_Booyer_value()
	{
		return Rabin_value;
	}

	int get_BrutForce_value()
	{
		return Rabin_value;
	}
};
#endif // !classProgram_run
