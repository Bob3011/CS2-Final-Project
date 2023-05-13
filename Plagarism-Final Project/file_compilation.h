#ifndef FILE_COMPILATION_H
#define FILE_COMPILATION_H
#pragma once
#define NO_OF_CHARS 256
#include <iostream>
#include <QString>
#include <QVector>
#include<QStringList>
#include "document.h"
class File_compilation
{
private:
    int percentageMatch = 0;
    QVector<Document> docs; //vector of type Document to contain all the required functions and attrbiutes from the class Document
public:
    //File_compilation();//constructor to automatically open the file Dir.txt which contains list of all the files that will be used to check for plagarism and it is adjusted
    int hammingDistance(QString text, QString pattern); //function to calculate hamming distance, used for plagarism, adjusted to be a bool function where if the text and pattern size are the same it will return true else return false
    QVector<int> computeLPS(QString pattern); // Fills lps[] for given pattern pat[0..M-1]
    int kmpSearch(QString pattern, QString text); //searches for occurances of words in a QString of text
    int rabinKarp(QString pat, QString txt); //compares hash value for txt with hash value of pattern, if hash value match then it will check for characters only, if p == t and pat[0...M-1] = txt[i, i+1,...i+M-1] it will return true, else it will return false
void badCharHeuristic(QVector<QString> str, int size,int badchar[NO_OF_CHARS]);//The preprocessing function for Boyer Moore's
    double boyerMoore(QString pat, QString txt); //A pattern searching function that uses Bad Character Heuristic of Boyer Moore Algorithm, if the pattern was not found it will return false
void search(QString pat, QString txt, int &percentage); //algorthim that compares length,, if match is found it will return true else returns false.
    QStringList UniqueWords;
  //  int countWordsInString(QString str);
    QVector<QString> splitStringIntoWords(QString str);

};

#endif // FILE_COMPILATION_H
