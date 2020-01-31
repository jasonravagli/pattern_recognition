//
// Created by Jason Ravagli on 31/01/2020.
//

#ifndef PATTERN_RECOGNITION_SEQUENCEGENERATOR_H
#define PATTERN_RECOGNITION_SEQUENCEGENERATOR_H

#include <vector>
#include <Eigen/Dense>
#include "MarkovChain.h"

using namespace std;
using namespace Eigen;

class SequenceGenerator {

public:
	/**
	 * @brief Initialize a SequenceGenerator with a MarkovChain having the initial
	 * probability matrix and the transition probability matrix specified
	 * @param possibleValues : number of possible values each sequence element can assume
	 * @return
	 */
	SequenceGenerator(int possibleValues);

	/**
	 * @brief generateSequence : function to generate a random sequence using a Markov Chain Model
	 * @param length : sequence length
	 * @return
	 */
	vector<int> generateSequence(int length);

	/**
	 * @brief  generateQuerySequence : generate a query sequence to search for in a main sequence
	 * using a Markov Chain Model
	 * @param mainSequenceLength : main sequence length
	 * @param queryLength : query sequence length. It should be lesser than the main sequence length
	 */
	vector<int> generateQuerySequence(int mainSequenceLength, int queryLength);

	const MatrixXf &getInitialProbs() const;

	const MatrixXf &getTransitionProbs() const;

private:
	MarkovChain _markovChain;

	MatrixXf _initialProbs;
	MatrixXf _transitionProbs;

	/**
	 * @brief  generate a matrix containing random probabilities so that the sum of each row elements is equal to 1
	 * @param rows : matrix rows
	 * @param cols : matrix columns
	 */
	MatrixXf generateRandomProbsMatrix(int rows, int cols);

};


#endif //PATTERN_RECOGNITION_SEQUENCEGENERATOR_H
