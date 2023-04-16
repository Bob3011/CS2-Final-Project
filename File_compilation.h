#ifndef classFile_compilation
#define classFile_compilation
#include <iostream>
#include <string>
#include <vector>
#include "Document.h"
using namespace std;

class file_compialtion
{
private:
	vector<Document> docs;

public:
	// function to calculate Hamming distance
	int hammingDistance(string str1, string str2)
	{
		int i = 0, count = 0;
		while (str1[i] != '\0') {
			if (str1[i] != str2[i])
				count++;
			i++;
		}
		return count;
	}

	// Fills lps[] for given pattern pat[0..M-1]
	vector<int> computeLPS(string pattern) {
		int m = pattern.length();
		vector<int> lps(m, 0);
		int len = 0;
		int i = 1;
		while (i < m) {
			if (pattern[i] == pattern[len]) {
				len++;
				lps[i] = len;
				i++;
			}
			else {
				if (len != 0) {
					len = lps[len - 1];
				}
				else {
					lps[i] = 0;
					i++;
				}
			}
		}
		return lps;
	}
	void kmpSearch(string text, string pattern) {
		int n = text.length();
		int m = pattern.length();
		vector<int> lps = computeLPS(pattern);
		int i = 0, j = 0;
		while (i < n) {
			if (text[i] == pattern[j]) {
				i++;
				j++;
			}
			if (j == m) {
				cout << "Pattern found at index " << i - j << endl;
				j = lps[j - 1];
			}
			else if (i < n && text[i] != pattern[j]) {
				if (j != 0) {
					j = lps[j - 1];
				}
				else {
					i++;
				}
			}
		}
	}
	// Prints occurrences of txt[] in pat[]
	// d is the number of characters in the input alphabet
#define d 256

/* pat -> pattern
	txt -> text
	q -> A prime number
*/
	void rabinKarp(char pat[], char txt[], int q)
	{
		int M = strlen(pat);
		int N = strlen(txt);
		int i, j;
		int p = 0; // hash value for pattern
		int t = 0; // hash value for txt
		int h = 1;

		// The value of h would be "pow(d, M-1)%q"
		for (i = 0; i < M - 1; i++)
			h = (h * d) % q;

		// Calculate the hash value of pattern and first
		// window of text
		for (i = 0; i < M; i++) {
			p = (d * p + pat[i]) % q;
			t = (d * t + txt[i]) % q;
		}

		// Slide the pattern over text one by one
		for (i = 0; i <= N - M; i++) {

			// Check the hash values of current window of text
			// and pattern. If the hash values match then only
			// check for characters one by one
			if (p == t) {
				/* Check for characters one by one */
				for (j = 0; j < M; j++) {
					if (txt[i + j] != pat[j]) {
						break;
					}
				}

				// if p == t and pat[0...M-1] = txt[i, i+1,
				// ...i+M-1]

				if (j == M)
					cout << "Pattern found at index " << i
					<< endl;
			}

			// Calculate hash value for next window of text:
			// Remove leading digit, add trailing digit
			if (i < N - M) {
				t = (d * (t - txt[i] * h) + txt[i + M]) % q;

				// We might get negative value of t, converting
				// it to positive
				if (t < 0)
					t = (t + q);
			}
		}
	}


#define NO_OF_CHARS 256
	// The preprocessing function for Boyer Moore's
	// bad character heuristic
	void badCharHeuristic(string str, int size,
		int badchar[NO_OF_CHARS])
	{
		int i;

		// Initialize all occurrences as -1
		for (i = 0; i < NO_OF_CHARS; i++)
			badchar[i] = -1;

		// Fill the actual value of last occurrence
		// of a character
		for (i = 0; i < size; i++)
			badchar[(int)str[i]] = i;
	}
	/* A pattern searching function that uses Bad
	Character Heuristic of Boyer Moore Algorithm */
	void boyerMoore(string txt, string pat)
	{
		int m = pat.size();
		int n = txt.size();

		int badchar[NO_OF_CHARS];

		/* Fill the bad character array by calling
		the preprocessing function badCharHeuristic()
		for given pattern */
		badCharHeuristic(pat, m, badchar);

		int s = 0; // s is shift of the pattern with
		// respect to text
		while (s <= (n - m))
		{
			int j = m - 1;

			/* Keep reducing index j of pattern while
			characters of pattern and text are
			matching at this shift s */
			while (j >= 0 && pat[j] == txt[s + j])
				j--;

			/* If the pattern is present at current
			shift, then index j will become -1 after
			the above loop */
			if (j < 0)
			{
				cout << "pattern occurs at shift = " << s << endl;

				/* Shift the pattern so that the next
				character in text aligns with the last
				occurrence of it in pattern.
				The condition s+m < n is necessary for
				the case when pattern occurs at the end
				of text */
				s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

			}

			else
				/* Shift the pattern so that the bad character
				in text aligns with the last occurrence of
				it in pattern. The max function is used to
				make sure that we get a positive shift.
				We may get a negative shift if the last
				occurrence of bad character in pattern
				is on the right side of the current
				character. */
				s += max(1, j - badchar[txt[s + j]]);
		}
	}


	int bruteForceStringMatch(string text, string pattern) {
		int textLen = text.length();
		int patternLen = pattern.length();
		for (int i = 0; i <= textLen - patternLen; i++) {
			bool matchFound = true;
			for (int j = 0; j < patternLen; j++) {
				if (text[i + j] != pattern[j]) {
					matchFound = false;
					break;
				}
			}
			if (matchFound) {
				return i;
			}
		}
		return -1;
	}

	void initialize_docs() {
		Document temp_doc;
		for (int i = 0; i < 6; i++) {
			temp_doc.set_direcotry("Corpus/file" + to_string(i + 1) + ".txt");
			docs.push_back(temp_doc);
			docs[i].fillInText();
		}
	}
};
#endif // !classFile_compialtion
