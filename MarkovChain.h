//
// Created by Jason Ravagli on 31/01/2020.
//

#ifndef PATTERN_RECOGNITION_MARKOVCHAIN_H
#define PATTERN_RECOGNITION_MARKOVCHAIN_H


#ifndef MARKOVCHAIN_HPP
#define MARKOVCHAIN_HPP

#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

/**
 * @brief The markovChain class : markovChain is a class
 * which encapsulates the representation of a discrete markov
 * chain.A markov chain is composed of transition matrix
 * and initial probability matrix
 */
class MarkovChain
{
public:
    MarkovChain();

    /* _transition holds the transition probability matrix
     * _initial holds the initial probability matrix
     */
    MatrixXf _transition;
    MatrixXf _initial;

    /**
     * @brief setModel : function to set the parameters of the model
     * @param transition : NXN transition matrix
     * @param initial : 1XN initial probability matrix
     */
    void setModel(MatrixXf transition,MatrixXf initial);


    /**
     * @brief computeProbability : compute the probability that the sequence
     *        is generate from the markov chain
     * @param sequence : is a vector of integral sequence starting from 0
     * @return         : is probability
     */
    float computeProbability(vector<int> sequence);

    /**
     * @brief initialRand : function to generate a radom state
     * @param matrix      : input matrix
     * @param index       ; row of matrix to consider
     * @return
     */
    int initialRand(MatrixXf matrix,int index);

    /**
     * @brief generateSequence is a function that generates a sequence of specified length
     * @param n : is the length of the sequence
     * @return : is a vector of integers representing generated sequence
     */
    vector<int> generateSequence(int n);

};

class MarkovSequenceClassifier
{
    vector<MarkovChain> models;
};


#endif // MARKOVCHAIN_HPP


#endif //PATTERN_RECOGNITION_MARKOVCHAIN_H
