//
// Created by Jason Ravagli on 05/02/2020.
//

#ifndef PATTERN_RECOGNITION_PATTERNRECOGNIZER_H
#define PATTERN_RECOGNITION_PATTERNRECOGNIZER_H

#include <vector>

using namespace std;

class PatternRecognizer {
public:

	struct Output{
		int patternStartIndex;
		double patternDistance;
	};

	/**
     * @brief Return the starting index and the SAD of the subsequence at the minimum distance from the query sequence
     * @param sequence : main sequence to recognize the pattern in
     * @param query : the pattern to recognize
     */
	Output recognizePattern(vector<int> sequence, vector<int> pattern);

private:

	/**
     * @brief Return the distance (calculated as the Sum of Absolute Distance) between two sequences
     * @param s1 : the first sequence
     * @param s2 : the second sequence
     */
	double getDistanceBetweenSequences(vector<int> s1, vector<int> s2);
};


#endif //PATTERN_RECOGNITION_PATTERNRECOGNIZER_H
