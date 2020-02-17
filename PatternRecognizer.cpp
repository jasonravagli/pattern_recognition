//
// Created by Jason Ravagli on 05/02/2020.
//

#include "PatternRecognizer.h"

#include <iostream>
#include <omp.h>

PatternRecognizer::Output PatternRecognizer::recognizePatternSequential(vector<int> sequence, vector<int> pattern) {

	int sequenceLength = sequence.size();
	int patternLength = pattern.size();

	int bestIndex = 0;
	double minDistance = numeric_limits<double>::infinity();

	for(int i = 0; i < sequenceLength - patternLength; i++){
		vector<int>::const_iterator first = sequence.begin() + i;
		vector<int>::const_iterator last = sequence.begin() + i + patternLength;
		vector<int> subsequence = vector<int>(first, last);
		double distance = getDistanceBetweenSequences(subsequence, pattern);

		if(distance < minDistance){
			minDistance = distance;
			bestIndex = i;
		}
	}

	Output output = Output();
	output.patternStartIndex = bestIndex;
	output.patternDistance = minDistance;

	return output;
}

PatternRecognizer::Output PatternRecognizer::recognizePatternOpenMP(vector<int> sequence, vector<int> pattern) {
	Output output = Output();
	output.patternStartIndex = 0;
	output.patternDistance = numeric_limits<double>::infinity();

	#pragma omp parallel default(shared)
	{
		#pragma omp master
		{
			cout << "Number of threads: " << omp_get_num_threads() << endl;
		}

		int sequenceLength = sequence.size();
		int patternLength = pattern.size();

		int bestIndex = 0;
		double minDistance = numeric_limits<double>::infinity();

		#pragma omp for schedule(static)
		for (int i = 0; i < sequenceLength - patternLength; i++) {
			vector<int>::const_iterator first = sequence.begin() + i;
			vector<int>::const_iterator last = sequence.begin() + i + patternLength;
			vector<int> subsequence = vector<int>(first, last);
			double distance = getDistanceBetweenSequences(subsequence, pattern);

			if (distance < minDistance) {
				minDistance = distance;
				bestIndex = i;
			}
		}

		#pragma omp critical
		{
			if(output.patternDistance > minDistance){
				output.patternStartIndex = bestIndex;
				output.patternDistance = minDistance;
			}
		}
	}

	return output;
}

double PatternRecognizer::getDistanceBetweenSequences(vector<int> s1, vector<int> s2) {
	assert(s1.size() == s2.size());

	double sadDistance = 0;
	vector<int>::const_iterator s1Iterator = s1.begin();
	vector<int>::const_iterator s2Iterator = s2.begin();

	for(int i = 0; i < s1.size(); i++){
		sadDistance += abs((*s1Iterator)-(*s2Iterator));
		s1Iterator++;
		s2Iterator++;
	}

	return sadDistance;
}
