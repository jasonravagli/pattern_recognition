#include <iostream>
#include <chrono>

#include "PatternRecognizer.h"
#include "SequenceGenerator.h"

using namespace std::chrono;

int main() {
	int possibleValues = 10;
	int mainSequenceLength = 1000000;
	int querySequenceLength = 100;

	SequenceGenerator sequenceGenerator = SequenceGenerator(possibleValues);
	vector<int> mainSequence = sequenceGenerator.generateSequence(mainSequenceLength);
	vector<int> querySequence = sequenceGenerator.generateQuerySequence(mainSequenceLength, querySequenceLength);

	PatternRecognizer patternRecognizer = PatternRecognizer();

	auto start = high_resolution_clock::now();
	PatternRecognizer::Output output = patternRecognizer.recognizePattern(mainSequence, querySequence);
	auto stop = high_resolution_clock::now();

	auto ms = duration_cast<milliseconds>(stop - start);
	auto s = duration_cast<seconds>(stop - start);
	cout << "Took " << s.count() << "s " << (ms.count() - s.count()*1000) << "ms" << endl;

	vector<int> subsequence = vector<int>(mainSequence.begin() + output.patternStartIndex,
	            mainSequence.begin() + output.patternStartIndex + querySequence.size());

	cout << "Found subsequence at index " << output.patternStartIndex << " with distance " << output.patternDistance << " from the pattern";
	cout << "Subsequence found:" << endl;
	auto itSubSequence = mainSequence.begin() + output.patternStartIndex;
	for (int i = 0; i < querySequenceLength; i++) {
		std::cout << *itSubSequence << ',';
		itSubSequence++;
	}

	cout << "Pattern sequence:" << endl;
	auto itQuery = querySequence.begin();
	for (int i = 0; i < querySequenceLength; i++) {
		std::cout << *itQuery << ',';
		itQuery++;
	}

	/*cout << "Initial prob: " << sequenceGenerator.getInitialProbs() << endl;
	cout << "Transition prob: " << sequenceGenerator.getTransitionProbs() << endl;

	for(int i = 0; i < mainSequenceLength; i++){
		cout << mainSequence[i] << ",";
	}*/

    return 0;
}
