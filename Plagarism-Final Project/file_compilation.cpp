#include "file_compilation.h"
#include <regex>
#include <iostream>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include "document.h"
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QString>
#include <QDebug>
#include <QDir>
using namespace std;

QVector<QString> File_compilation::splitStringIntoWords(QString str) {
    QVector<QChar> unwantedChars = {',', '\n', '.', ';', ':', '!'};
    QVector<QString> words;
    QString currentWord;
    for (int i = 0; i < str.length(); i++) {
        QChar currentChar = str[i];
        if (currentChar.isSpace() || unwantedChars.contains(currentChar)) {
            if (!currentWord.isEmpty()) {
                words.push_back(currentWord);
                currentWord.clear();
            }
        } else {
            currentWord.append(currentChar);
        }
    }
    if (!currentWord.isEmpty()) {
        words.push_back(currentWord);
    }
    return words;
}
    // function to calculate Hamming distance
    int File_compilation::hammingDistance(QString text, QString pattern)
    {
        QVector<QString> patternWords = splitStringIntoWords(pattern);
        QVector<QString> textWords = splitStringIntoWords(text);
        double n = textWords.size();
        double m = patternWords.size();
        UniqueWords.clear();
        int wordMatchCounter = 0;
        for (int i = 0; i < n; i++) {
            int counter = 0;
            for (int j = 0; j < m; j++) {
                if (textWords[i] == patternWords[j]) {
                 counter++;
              UniqueWords.push_back(textWords[i]);
                wordMatchCounter++;
                }
            }
            if (counter == n) {
                for (int j = 0; j < m; j++) {
                }
            }
        }
        percentageMatch = (wordMatchCounter / n) * 100.0;
        return percentageMatch;
    }

    // Fills lps[] for given pattern pat[0..M-1]
    QVector<int> File_compilation::computeLPS(QString pattern) {
        int m = pattern.length();
        QVector<int> lps(m, 0);
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
    int File_compilation::kmpSearch(QString pattern, QString text) {
        QVector<QString> patternWords = splitStringIntoWords(pattern);
        QVector<QString> textWords = splitStringIntoWords(text);
        int n = textWords.size();
        int m = patternWords.size();
     //   int percentageMatch=0;
        UniqueWords.clear();
        int wordMatchCounter = 0;
  //     int i=0, j=0;
       QVector<int> lps = computeLPS(pattern);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
            if (textWords[i] == patternWords[j]) {
                //QString z = text.mid(i, 1);
                UniqueWords.push_back(textWords[i]);
                wordMatchCounter++;
            }
            }
        }
  /*        if (j != 0) {
               j = lps[j - 1];
            }
            else {
                i++;
            }
*/
        percentageMatch = ((double)wordMatchCounter/n) *100.0;
        return percentageMatch;
    }

    // d is the number of characters in the input alphabet
#define d 256

/* pat -> pattern
    txt -> text
    q -> A prime number
*/
#define d 256
int File_compilation::rabinKarp(QString pat, QString txt) {
    int wordMatchCounter = 0;
   // int percentageMatch = 0;
    int q = INT_MAX;
    QVector<QString> patWords = splitStringIntoWords(pat);
    QVector<QString> txtWords = splitStringIntoWords(txt);
    int M = patWords.size();
    int N = txtWords.size();
    int i = 0;// , j = 0;
    int j = 0;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
    QString tempPat = "";
    QString tempTxt = "";

        for (i = 0; i < M - 1; i++) {
            h = (h * d) % q;
        }
    for (i = 0; i < N ; i++)
    {
        p = 0;
        t = 0;
        for (j = 0; j < M; j++)
        {
            tempPat.clear();
            tempTxt.clear();
            p = 0;
            t = 0;
            p = (d * p + hash<QString>{}(patWords[j])) % q;
            tempPat = patWords[j];
            t = (d * t + hash<QString>{}(txtWords[i])) % q;
            tempTxt = txtWords[i];
            if (p == t)
            {
                    wordMatchCounter++;
                    UniqueWords.push_back(txtWords[i]);
            }
        }
    }
    percentageMatch = (wordMatchCounter / (double)N) * 100.0;
    return percentageMatch;
}


#define NO_OF_CHARS 256
void File_compilation::badCharHeuristic(QVector<QString> str, int size,int badchar[NO_OF_CHARS])
{
    int i;

    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    // Fill the actual value of last occurrence
    // of a character
    for (i = 0; i < size; i++)
        badchar[(int)str[i][0].unicode()] = i;
}
/* A pattern searching function that uses Bad
Character Heuristic of Boyer Moore Algorithm */
double File_compilation ::boyerMoore(QString pat, QString text)
{

    QVector<QString> patternWords = splitStringIntoWords(pat);
    QVector<QString> textWords = splitStringIntoWords(text);
    double wordMatchCounter = 0.0;
    int m = textWords.size();
    int n = patternWords.size();
    int badchar[NO_OF_CHARS];
    UniqueWords.clear();
    /* Fill the bad character array by calling
    the preprocessing function badCharHeuristic()
    for given pattern */
    badCharHeuristic(textWords, m, badchar);
    int s = 0; // s is shift of the pattern with
            for (int i = 0; i < m; i++) {
                for (int k = 0; k < n; k++) {
                    if (textWords[i] == patternWords[k])
                        UniqueWords.push_back(textWords[s + i]);
                }
            }
    // respect to text
    while (s <= (n - m))
    {
        int j = m - 1;
        while (j >= 0 && textWords[j] == patternWords[s + j])
            j--;

        if (j < 0)
        {
            s += (s + m < n) ? m - badchar[patternWords[s + m][0].unicode()] : 1;
        }

        else
           s += max(1, j - badchar[patternWords[s + j][0].unicode()]);
          wordMatchCounter++;
    }
    percentageMatch = ((double)wordMatchCounter / m)*100.0;
    return percentageMatch;
}


void File_compilation :: search(QString pat, QString txt, int &percentage) {
    QVector<QString> patWords = splitStringIntoWords(pat);
    QVector<QString> txtWords =splitStringIntoWords(txt);
    UniqueWords.clear();
    int N = txtWords.size();
    int M = patWords.size();

    int count = 0;

    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++) {
            if (txtWords[i + j] != patWords[j]) {
                break;
            }
        }
        if (j == M) {
           // cout << "Plagiarized part: ";
            for (int k = 0; k < M; k++) {
              count++;
                UniqueWords.push_back(txtWords[i + k]);

            }
         //   cout << endl;
        }
    }

    percentage = ((double)count /N)*100.0;

  //  cout << "Plagiarism percentage: " << percentage << "%" << endl;
}
