/*
	EMV

	Garza, Erika
	Ky, Vy
	Nuon, Molita

	CS A250: Project 2
*/

#ifndef CANDIDATETYPE_H
#define CANDIDATETYPE_H

#include "PersonType.h"

#include <string>
#include <iostream>

using namespace std;

const int NUM_OF_DIVISIONS = 4;

class CandidateType : public PersonType
{
public:
	CandidateType();

	void updateVotesByDivision(int divisionNum,
		int voteForDivision);

	int getTotalVotes() const;
	int getVotesByDivision(int divisionNum) const;

	void printCandidateInfo() const;
	void printCandidateTotalVotes() const;
	void printCandidateDivisionVotes(int divisionNum) const;

	~CandidateType();

private:
	int numOfVote;
	int a[NUM_OF_DIVISIONS];
};

#endif

