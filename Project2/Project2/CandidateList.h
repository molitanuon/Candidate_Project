/*
	EMV

	Garza, Erika
	Ky, Vy
	Nuon, Molita

	CS A250: Project 2
*/

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;


class CandidateList
{
public:
	// Function declarations
	CandidateList();
	CandidateList(const CandidateList& myList);

	void addCandidate(const CandidateType& myCandidate) const;

	int getWinner() const;

	bool searchCandidate(int ssn) const;

	bool isEmpty();

	void printCandidateName(int ssn) const;
	void printAllCandidates() const;
	void printCandidateDivisionVotes(int ssn, int division) const;
	void printCandidateTotalVotes(int ssn) const;

	CandidateList& operator=(const CandidateList& myList);

	~CandidateList();

private:

	bool searchCandidate(int ssn, 
		vector<CandidateType>::const_iterator &iter) const;

	vector<CandidateType> *candidates;
};
#endif