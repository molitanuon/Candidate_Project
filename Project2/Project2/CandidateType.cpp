/*
	EMV

	Garza, Erika
	Ky, Vy
	Nuon, Molita

	CS A250: Project 2
*/

#include "PersonType.h"
#include "CandidateType.h"

CandidateType::CandidateType()
{
	numOfVote = 0;
	for (int i = 0; i < NUM_OF_DIVISIONS; i++)
	{
		a[i] = 0;
	}
}

void CandidateType::updateVotesByDivision(int divisionNum,
	int voteForDivision)
{
	a[divisionNum] = voteForDivision;
	numOfVote += voteForDivision;
}

int CandidateType::getTotalVotes() const
{
	return numOfVote;
}

int CandidateType::getVotesByDivision(int divisionNum) const
{
	return a[divisionNum - 1];
}

void CandidateType::printCandidateInfo() const
{
	if (getSocSec() == 0)
		cout << "No information available "
		<< "for this candidate.";
	else
	{
		printSocSec();
		cout << " - ";
		printName();
	}
}

void CandidateType::printCandidateTotalVotes() const
{
	printName();
	cout << "=> Total Votes (all divisions): "
		<< numOfVote;
}

void CandidateType::printCandidateDivisionVotes(int divisionNum) const
{
	printName();
	cout << "    => Division "
		<< divisionNum << " total votes: "
		<< getVotesByDivision(divisionNum);
}

CandidateType::~CandidateType() {}