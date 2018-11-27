// Megan Yu
// ID# 2263079
// yu204@mail.chapman.edu
// CPSC 350-01
// Assignment 01 

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <ctype.h>
using namespace std;

class DNAreader{
public:
	DNAreader();
	~DNAreader();
	int lineCount, sum, bigramSum;
	int countA, countT, countG, countC;
	int countAA, countAC, countAT, countAG;
	int countCA, countCC, countCT, countCG; 
	int countTA, countTT, countTG, countTC;
	int countGA, countGT, countGG, countGC;
	double mean, variance, stdev;
	float probA, probT, probG, probC;
	float probAA, probAT, probAG, probAC;
	float probTA, probTT, probTG, probTC;
	float probCA, probCT, probCG, probCC;
	float probGA, probGT, probGG, probGC;
	string bigram;

	void readDNAFile(string fileName);
	void stdevMethod();
	void generateNewDNA();
	double meanGetter();
	double varianceGetter();
	double stdevGetter ();
	int sumGetter();
	void probNucleotide();
	void probBigram();
};
