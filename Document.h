#ifndef classDocument
#define classDocument

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

	void set_direcotry(string d)
	{
		directory = d;
	}

	string get_directory()
	{
		return directory;
	}

	void set_txt(string t)
	{
		text = t;
	}

	string get_txt()
	{
		return text;
	}
};

#endif // !classDocument