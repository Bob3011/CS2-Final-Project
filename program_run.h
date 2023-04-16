#ifndef classProgram_run
#define classProgram_run

#include <iostream>
#include <map>
#include <fstream>
#include "Document.h"
#include "File_compilation.h"


using namespace std;
struct plagiarized_sentence {
	string content;
	string doc_dir;
};

class Program_run : public Document, public file_compialtion
{
private:
	file_compialtion c;
	Document doc;
	vector<plagiarized_sentence> KMP_result;
	vector<plagiarized_sentence> Rabin_result;
	vector<plagiarized_sentence> Hamming_result;
	vector<plagiarized_sentence> Booyer_result;

public:
	map<string, int> results_KMP;
	map<string, int> results_Rabin;
	map<string, int> results_Booyer;
	map<string, int> results_Hamming;
	/*long long time_KMP;
	long long time_Rabin;
	long long time_Booyer;
	long long time_Hamming;*/
	void check_match_kmp();
	void check_match_rabin();
	void check_match_Booyer();
	void check_match_hamming();


	void get_doc(string file_name)
	{
		doc.set_direcotry(file_name);
		c.initialize_docs();//intialize the docs we have in corpurs
		doc.populate();
		doc.adjustSentence();
	}
};
#endif // !classProgram_run
