// Megan Yu
// ID# 2263079
// yu204@mail.chapman.edu
// CPSC 350-01
// Assignment 01
/*This assignment computes the sum, mean, variance, and stdev of a string of DNA nucleotides, 
then determines the probability of each nucleotide, single and bigram. The program then generates 
strings that follow the bell curve of the original set of nucleotides. */

#include "DNAreader.h"

int main(int argc, char *argv[])
{
	string fileName;
	int answer;
	int loopCount = 0;
	DNAreader fileReader;
	fileName = argv[1];

	ofstream outputFile("MeganYu.out");
	if (loopCount == 0){
			outputFile<<"Megan Yu" << endl<< "ID# 2263079"<<endl<<"yu204@mail.chapman.edu"<<endl<<"CPSC 350-01"<<endl<< "Assignment 01"<<endl;
			loopCount++;
		}
		else{
		//default
		} 
	while (true){
	
		ofstream outputFile("MeganYu.out", ios_base::app);
		fileReader.readDNAFile(fileName);
		fileReader.stdevMethod();
		outputFile<< "File name: "<<fileName<<endl;
		outputFile<< "Sum: " << fileReader.sumGetter()<< endl;
		outputFile<< "Mean: "<< fileReader.meanGetter()<< endl;
		outputFile<< "Variance: "<<fileReader.varianceGetter()<< endl;
		outputFile<< "Standard Deviation: "<< fileReader.stdevGetter()<<endl;
		outputFile<<endl;

		fileReader.probNucleotide();
		fileReader.probBigram(); 
		fileReader.generateNewDNA();
		cout << "Do you want to run this program again? '1' for yes or '2' for no: ";
		cin >> answer;
		if (answer == 2){
			break;
		}
		else{
			cout<< "Enter the name of the file: ";
			cin>>fileName;
		}

	}

	return 0;
}
