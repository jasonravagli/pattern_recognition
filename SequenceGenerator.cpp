//
// Created by Jason Ravagli on 31/01/2020.
//

#include "SequenceGenerator.h"

SequenceGenerator::SequenceGenerator(int possibleValues){
	srand(time(nullptr));

	_initialProbs = generateRandomProbsMatrix(1, possibleValues);
	_transitionProbs = generateRandomProbsMatrix(possibleValues, possibleValues);

	_markovChain = MarkovChain();
	_markovChain.setModel(_transitionProbs, _initialProbs);
}

vector<int> SequenceGenerator::generateSequence(int length) {
	return _markovChain.generateSequence(length);
}

vector<int> SequenceGenerator::generateQuerySequence(int mainSequenceLength, int queryLength) {
	// Genero una sequenza della stessa lunghezza della sequenza principale e
	// Restituisco una sua sottosequenza casuale di lunghezza queryLength

	vector<int> newSequence = _markovChain.generateSequence(mainSequenceLength);

	if(queryLength > mainSequenceLength){
		cerr << "Error generating query sequence: query sequence cannot be longer than main sequence";
		return vector<int>();
	}

	int startPoint = (int)((((float) rand()) / RAND_MAX) * (mainSequenceLength - queryLength));
	vector<int>::const_iterator first = newSequence.begin() + startPoint;
	vector<int>::const_iterator last = newSequence.begin() + startPoint + queryLength;
	return vector<int>(first, last);
}

MatrixXf SequenceGenerator::generateRandomProbsMatrix(int rows, int cols) {
	MatrixXf matrix = MatrixXf(rows, cols);
	matrix = MatrixXf::Random(rows,cols); // rowsXcols Matrix filled with random numbers between (-1,1)
	matrix = matrix + MatrixXf::Constant(rows,cols,1.);

	for(int i = 0; i < rows; i++){
		float rowSum = matrix.row(i).sum();
		matrix.row(i) = matrix.row(i)/rowSum;

		/*for(int j = 0; j < cols - 1; j++){

			float probability = ((float) rand()) / RAND_MAX * (1 - rowSum);
			matrix(i, j) = probability;
			rowSum += probability;
		}

		matrix(i, cols - 1) = 1 - rowSum;*/
	}

	return matrix;
}

const MatrixXf &SequenceGenerator::getInitialProbs() const {
	return _initialProbs;
}

const MatrixXf &SequenceGenerator::getTransitionProbs() const {
	return _transitionProbs;
}
