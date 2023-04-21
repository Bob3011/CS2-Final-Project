#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <chrono>
#include "Document.h"
#include "File_compilation.h"
#include "structPlagerizedSentence.h"
class Program_run : public Document, public file_compilation {
private:
	file_compilation c;
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
	void check_match_kmp();
	void check_match_rabin();
	void check_match_Booyer();
	void check_match_hamming();
	void check_match_brutForce();
	void get_doc(string file_name);
	plagiarized_sentence manip_Hamming_result(int i);
	vector<plagiarized_sentence> manip_Hamming();
	plagiarized_sentence manip_Rabin_result(int i);
	vector<plagiarized_sentence> manip_Rabin();
	plagiarized_sentence manip_KMP_result(int i);
	vector<plagiarized_sentence> manip_KMP();
	plagiarized_sentence manip_Booyer_result(int i);
	vector<plagiarized_sentence> manip_Booyer();
	plagiarized_sentence manip_BrutForce_result(int i);
	vector<plagiarized_sentence> manip_BrutForce();
	int get_Rabin_value();
	int get_Hamming_value();
	int get_KMP_value();
	int get_Booyer_value();
	int get_BrutForce_value();
};