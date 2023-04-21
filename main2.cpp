#include <iostream>
#include <fstream>
#include <string>
#include "Document.h"
#include "File_compilation.h"
#include "program_run.h"

using namespace std;

int main()
{
	Program_run run;
	string num = "1";

	cout << " // welcome // " << endl;

	while (num == "1")
	{
		string choice;

		cout << "how would u lke to use our program?" << endl;
		cout << "if u want to input a file please neter 1" << endl;
		cout << "if u want to type please type 2" << endl;
		getline(cin,choice);

		if (choice == "1")
		{
			string dir_name;
			cout << "please enter the directory name" << endl;
			getline(cin,dir_name);

			ifstream instream;
			instream.open(dir_name);
			if (instream.fail()) {
				cout << "Failed to open file " << endl;
			}


			run.get_doc(dir_name);

			cout << "Please wait while the program detects the persentage of plagerisum plagiarism" << endl;

			//-----------------------------------------------------------------------------------------------------------------------
			/*HAMMING DISTNACE*/

			run.check_match_hamming();
			cout << "Below are the plagiarized sentences after using the first algorithm" << endl;
			for (int i = 0; i < run.manip_Hamming().size(); i++)
			{
				cout << "Sentence: " << run.manip_Hamming_result(i).content << endl << "Plagiatized from:" << run.manip_Hamming_result(i).doc_dir << endl;
			}
			//cout << "Time used to detect plagiarism = " << run.get_hamming_time() << " ms" << endl;
			cout << "The persentage of plagerisum is " << run.get_Hamming_value() << "%" << endl;

			//------------------------------------------------------------------------------------------------------------------------
			/*RABIN KARP*/

			cout << endl;
			cout << "----------------------------------" << endl;

			run.check_match_rabin();
			cout << "Below are the plagiarized sentences after using the second algorithm" << endl;
			for (int i = 0; i < run.manip_Rabin().size(); i++)
			{
				cout << "Sentence: " << run.manip_Rabin_result(i).content << endl << "Plagiatized from:" << run.manip_Rabin_result(i).doc_dir << endl;
			}
			//cout << "Time used to detect plagiarism = " << run.get_Rabin_time() << " ms" << endl;
			cout << "The persentage of plagerisum is " << run.get_Rabin_value() << "%" << endl;

			//------------------------------------------------------------------------------------------------------------------------
			/*BOOYER MOORE*/

			cout << endl;
			cout << "----------------------------------" << endl;

			run.check_match_Booyer();
			cout << "Below are the plagiarized sentences after using the third algorithm" << endl;
			for (int i = 0; i < run.manip_Booyer().size(); i++)
			{
				cout << "Sentence: " << run.manip_Booyer_result(i).content << endl << "Plagiatized from:" << run.manip_Booyer_result(i).doc_dir << endl;
			}
			//cout << "Time used to detect plagiarism = " << run.get_Booyer_time() << " ms" << endl;
			cout << "The persentage of plagerisum is " << run.get_Booyer_value() << "%" << endl;

			//------------------------------------------------------------------------------------------------------------------------
			/*KMP SEARCH*/

			cout << endl;
			cout << "----------------------------------" << endl;

			run.check_match_kmp();
			cout << "Below are the plagiarized sentences after using the fourth algorithm" << endl;
			for (int i = 0; i < run.manip_KMP().size(); i++)
			{
				cout << "Sentence: " << run.manip_KMP_result(i).content << endl << "Plagiatized from:" << run.manip_KMP_result(i).doc_dir << endl;
			}
			//cout << "Time used to detect plagiarism = " << run.get_KMP_time() << " ms" << endl;
			cout << "The persentage of plagerisum is " << run.get_KMP_value() << "%" << endl;

			//------------------------------------------------------------------------------------------------------------------------
			/*Brut Force*/

			cout << endl;
			cout << "----------------------------------" << endl;

			run.check_match_brutForce();
			cout << "Below are the plagiarized sentences after using the fifth algorithm" << endl;
			for (int i = 0; i < run.manip_BrutForce().size(); i++)
			{
				cout << "Sentence: " << run.manip_BrutForce_result(i).content << endl << "Plagiatized from:" << run.manip_BrutForce_result(i).doc_dir << endl;
			}
			//cout << "Time used to detect plagiarism = " << run.get_BrutForce_time() << " ms" << endl;
			cout << "The persentage of plagerisum is " << run.get_BrutForce_value() << "%" << endl;
			instream.close();
			double AveragePercentage = (run.get_Hamming_value() + run.get_Rabin_value() + run.get_Booyer_value() + run.get_KMP_value() + run.get_BrutForce_value()) / 5;
			cout << "The average Percentage is " << AveragePercentage << "%" << endl;
			cout << endl;

			run.addToDir(AveragePercentage, dir_name);

			cout << "If you want to try again please enter 1" << endl;
			cout << "If you want to quit please eneter 2" << endl;
			getline(cin, num);
			cout << endl;
		}
		else if (choice == "2")
		{
			string user_input;
			string input_name;

			cout << "the text u will input will be placed inside a text file what would you like its name to be" << endl;
			getline(cin,input_name);

			input_name += ".txt";

			//if condiditon to check if file name is already taken;
			if (run.check_name(input_name) == true)
			{
				cout << "the file name that ypu have enterd is already in our data base can you please neter another name" << endl;
				getline(cin, input_name);
			}
			else
			{
				ofstream data_base;
				data_base.open("database.txt", ios::app);
				data_base << input_name;
			}

			ofstream new_file;
			new_file.open(input_name);
			if (new_file.fail())
			{
				cout << "a error has occured" << endl;
				exit(1);
				break;
			}
			else
			{
				cout << "please enter your text" << endl;
				getline(cin, user_input);
				new_file << user_input;
				new_file.close();
			}

			ifstream instream;
			instream.open(input_name);
			if (instream.fail()) {
				cout << "Failed to open file " << endl;
			}
			else
			{
				run.get_doc(input_name);
			}

			cout << "Please wait while the program detects the persentage of plagerisum plagiarism" << endl;

			//-----------------------------------------------------------------------------------------------------------------------
			/*HAMMING DISTNACE*/

			run.check_match_hamming();
			cout << "Below are the plagiarized sentences after using the first algorithm" << endl;
			for (int i = 0; i < run.manip_Hamming().size(); i++)
			{
				cout << "Sentence: " << run.manip_Hamming_result(i).content << endl << "Plagiatized from:" << run.manip_Hamming_result(i).doc_dir << endl;
			}
			//cout << "Time used to detect plagiarism = " << run.get_hamming_time() << " ms" << endl;
			cout << "The persentage of plagerisum is " << run.get_Hamming_value() << "%" << endl;

			//------------------------------------------------------------------------------------------------------------------------
			/*RABIN KARP*/

			cout << endl;
			cout << "----------------------------------" << endl;

			run.check_match_rabin();
			cout << "Below are the plagiarized sentences after using the second algorithm" << endl;
			for (int i = 0; i < run.manip_Rabin().size(); i++)
			{
				cout << "Sentence: " << run.manip_Rabin_result(i).content << endl << "Plagiatized from:" << run.manip_Rabin_result(i).doc_dir << endl;
			}
			//cout << "Time used to detect plagiarism = " << run.get_Rabin_time() << " ms" << endl;
			cout << "The persentage of plagerisum is " << run.get_Rabin_value() << "%" << endl;

			//------------------------------------------------------------------------------------------------------------------------
			/*BOOYER MOORE*/

			cout << endl;
			cout << "----------------------------------" << endl;

			run.check_match_Booyer();
			cout << "Below are the plagiarized sentences after using the third algorithm" << endl;
			for (int i = 0; i < run.manip_Booyer().size(); i++)
			{
				cout << "Sentence: " << run.manip_Booyer_result(i).content << endl << "Plagiatized from:" << run.manip_Booyer_result(i).doc_dir << endl;
			}
			//cout << "Time used to detect plagiarism = " << run.get_Booyer_time() << " ms" << endl;
			cout << "The persentage of plagerisum is " << run.get_Booyer_value() << "%" << endl;

			//------------------------------------------------------------------------------------------------------------------------
			/*KMP SEARCH*/

			cout << endl;
			cout << "----------------------------------" << endl;

			run.check_match_kmp();
			cout << "Below are the plagiarized sentences after using the fourth algorithm" << endl;
			for (int i = 0; i < run.manip_KMP().size(); i++)
			{
				cout << "Sentence: " << run.manip_KMP_result(i).content << endl << "Plagiatized from:" << run.manip_KMP_result(i).doc_dir << endl;
			}
			//cout << "Time used to detect plagiarism = " << run.get_KMP_time() << " ms" << endl;
			cout << "The persentage of plagerisum is " << run.get_KMP_value() << "%" << endl;

			//------------------------------------------------------------------------------------------------------------------------
			/*Brut Force*/

			cout << endl;
			cout << "----------------------------------" << endl;

			run.check_match_brutForce();
			cout << "Below are the plagiarized sentences after using the fifth algorithm" << endl;
			for (int i = 0; i < run.manip_BrutForce().size(); i++)
			{
				cout << "Sentence: " << run.manip_BrutForce_result(i).content << endl << "Plagiatized from:" << run.manip_BrutForce_result(i).doc_dir << endl;
			}
			//cout << "Time used to detect plagiarism = " << run.get_BrutForce_time() << " ms" << endl;
			cout << "The persentage of plagerisum is " << run.get_BrutForce_value() << "%" << endl;
			instream.close();
			double AveragePercentage = (run.get_Hamming_value() + run.get_Rabin_value() + run.get_Booyer_value() + run.get_KMP_value() + run.get_BrutForce_value()) / 5;
			cout << "The average Percentage is " << AveragePercentage << endl;
			cout << endl;

			cout << "If you want to try again please enter 1" << endl;
			cout << "If you want to quit please eneter 2" << endl;
			getline(cin, num);
			cout << endl;
		}
		else
		{
			cout << endl;
			cout << "your input is incorrect please try again and input 1 or 2" << endl;
			cout << endl;
			num = "1";
		}
	}
	return 0;
}