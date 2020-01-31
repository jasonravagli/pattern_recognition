#include <iostream>

#include "SequenceGenerator.h"

int main() {
	int possibleValues = 20;
	int mainSequenceLength = 1000;
	int querySequenceLength = 50;

	SequenceGenerator sequenceGenerator = SequenceGenerator(possibleValues);
	vector<int> mainSequence = sequenceGenerator.generateSequence(mainSequenceLength);
	vector<int> querySequence = sequenceGenerator.generateQuerySequence(mainSequenceLength, querySequenceLength);

	cout << "Initial prob: " << sequenceGenerator.getInitialProbs() << endl;
	cout << "Transition prob: " << sequenceGenerator.getTransitionProbs() << endl;

	for(int i = 0; i < mainSequenceLength; i++){
		cout << mainSequence[i] << ",";
	}

    return 0;
}
