// Megan Yu
// ID# 2263079
// yu204@mail.chapman.edu
// CPSC 350-01
// Assignment 01 

#include "DNAreader.h"


DNAreader::DNAreader(){
}

DNAreader::~DNAreader() {
	
}

void DNAreader::readDNAFile(string fileName){
	
	countA = 0;
	countT = 0;
	countG = 0;
	countC = 0;
	countAA = 0;
	countAC = 0;
	countAT = 0;
	countAG = 0;
	countCA = 0;
	countCC = 0;
	countCT = 0;
	countCG = 0;
	countTA = 0;
	countTT = 0;
	countTG = 0;
	countTC = 0;
	countGA = 0;
	countGT = 0;
	countGG = 0;
	countGC = 0;

	sum = 0;
	bigramSum = sum-1;
	lineCount = 0;
	variance = 0;

	string bigram;

	ifstream fileReader;
	fileReader.open(fileName);

	for (string line; getline (fileReader, line);)
	{
		ofstream outputFile("MeganYu.out", ios_base::app);

		lineCount++;
		//SUM
		sum += line.length();

		//MEAN 
		mean = sum / lineCount;

		for (int i=0; i<line.length(); i++)
		{
			line[i]=toupper(line[i]); 
			if (line[i]== 'A'){
				countA++;
			}
			else if (line[i]== 'T'){
				countT++;
			}
			else if (line[i]== 'G'){
				countG++;
			}
			else if (line[i]== 'C'){
				countC++;
			}
			else {
				//default
			}

			if (i == 0){
				bigram = line[i];
			}
			else if (i==1){
				bigram += line[i];
			}
			else {
				bigram.erase(bigram.begin());
				bigram += line[i];
			}

			if (bigram== "AA"){
				countAA++;
			}
			else if (bigram== "AC"){
				countAC++;
			}
			else if (bigram== "AT"){
				countAT++;
			}
			else if (bigram== "AG"){
				countAG++;
			}
			else if (bigram== "CA"){
				countCA++;
			}
			else if (bigram== "CT"){
				countCT++;
			}
			else if (bigram== "CC"){
				countCC++;
			}
			else if (bigram== "CG"){
				countCG++;
			}
			else if (bigram== "GA"){
				countGA++;
			}
			else if (bigram== "GT"){
				countGT++;
			}
			else if (bigram== "GC"){
				countGC++;
			}
			else if (bigram== "GG"){
				countGG++;
			}
			else if (bigram== "TA"){
				countTA++;
			}
			else if (bigram== "TG"){
				countTG++;
			}
			else if (bigram== "TT"){
				countTT++;
			}
			else if (bigram== "TC"){
				countTC++;
			}
			else{
				//default
			}
		}
	}
	fileReader.close();
	fileReader.open(fileName);
	for (string line; getline (fileReader, line);)
	{
		// VARIANCE
		variance += (pow(line.length()-mean, 2))/lineCount;
	}
	fileReader.close();
}
void DNAreader::stdevMethod(){
	stdev = (pow(variance, 0.5));
}

double DNAreader::meanGetter(){
	return mean;
}

double DNAreader::varianceGetter(){
	return variance;
}

double DNAreader::stdevGetter(){
	return stdev;
}

int DNAreader::sumGetter(){
	return sum;
}

void DNAreader::probNucleotide() {
	ofstream outputFile("MeganYu.out", ios_base::app);//outputs the probability of each nucleotide occuring given the total number of nucleotides in the file
	probA = (countA*1.0)/sum;
	probC = (countC*1.0)/sum;
	probT = (countT*1.0)/sum;
	probG = (countG*1.0)/sum;
	outputFile<<"Probability of each nucleotide:"<<endl;
	outputFile<< "Probability of A: "<<probA<<endl;
	outputFile<< "Probability of C: "<<probC<<endl;
	outputFile<< "Probability of G: "<<probC<<endl;
	outputFile<< "Probability of T: "<<probC<<endl;
}
void DNAreader::probBigram() {
	ofstream outputFile("MeganYu.out", ios_base::app); //outputting the probability of each bigram occuring given the total bigrams in the file
	probAA = (countAA*1.0)/bigramSum;
	probAC = (countAC*1.0)/bigramSum;
	probAT = (countAT*1.0)/bigramSum;
	probAG = (countAG*1.0)/bigramSum;

	probCA = (countCA*1.0)/bigramSum;
	probCC = (countCC*1.0)/bigramSum;
	probCT = (countCT*1.0)/bigramSum;
	probCG = (countCG*1.0)/bigramSum;

	probTA = (countTA*1.0)/bigramSum;
	probTC = (countTC*1.0)/bigramSum;
	probTT = (countTT*1.0)/bigramSum;
	probTG = (countTG*1.0)/bigramSum;

	probGA = (countGA*1.0)/bigramSum;
	probGC = (countGC*1.0)/bigramSum;
	probGT = (countGT*1.0)/bigramSum;
	probGG = (countGG*1.0)/bigramSum;

	outputFile<<"Probability of each bigram: "<<endl;
	outputFile<< "Probability of AA: "<<probA<<endl;
	outputFile<< "Probability of AC: "<<probC<<endl;
	outputFile<< "Probability of AG: "<<probC<<endl;
	outputFile<< "Probability of AT: "<<probC<<endl;

	outputFile<< "Probability of CA: "<<probA<<endl;
	outputFile<< "Probability of CC: "<<probC<<endl;
	outputFile<< "Probability of CG: "<<probC<<endl;
	outputFile<< "Probability of CT: "<<probC<<endl;

	outputFile<< "Probability of GA: "<<probA<<endl;
	outputFile<< "Probability of GC: "<<probC<<endl;
	outputFile<< "Probability of GG: "<<probC<<endl;
	outputFile<< "Probability of GT: "<<probC<<endl;

	outputFile<< "Probability of TA: "<<probA<<endl;
	outputFile<< "Probability of TC: "<<probC<<endl;
	outputFile<< "Probability of TG: "<<probC<<endl;
	outputFile<< "Probability of TT: "<<probC<<endl;
	outputFile<<endl;
}

void DNAreader::generateNewDNA(){ //creates 1000 new lines using gaussian distribution using data gathered from statistic methods
	ofstream outputFile("MeganYu.out", ios_base::app);
	int newLineCount = 0;
	int newLetterCount = 0;
	string nextLetter = "ACTG";
	outputFile<<"New DNA generation: "<<endl;
	while (newLineCount <= 1000){
		double a = rand()*1.0/RAND_MAX;
		double b = rand()*1.0/RAND_MAX;
		double c = sqrt((-2) * log (a))* cos (2*M_PI* b);
		int d = stdev*c + mean; //how many nucleotides each line will have
		
		while (newLetterCount <= d) { 
			int e = rand()%4;
			outputFile<< nextLetter[e]; 
			newLetterCount++;
		}
		outputFile<<endl;
		newLetterCount = 0;
		newLineCount++;
	}
} 
