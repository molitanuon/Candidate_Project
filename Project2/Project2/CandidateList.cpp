/*
	EMV

	Garza, Erika
	Ky, Vy
	Nuon, Molita

	CS A250: Project 2
*/

#include "CandidateList.h"

CandidateList::CandidateList()
{
	candidates = new vector<CandidateType>;
}

CandidateList::CandidateList(const CandidateList& myList)
{
	candidates = new vector <CandidateType>;

	candidates->assign(myList.candidates->cbegin(),
	myList.candidates->cend());
}

CandidateList& CandidateList::operator=(const CandidateList& myList)
{
	if (&myList != this)
	{
		int candidateSize = static_cast<int>(candidates->size());
		int otherSize = static_cast<int>(myList.candidates->size());

		if (candidateSize != otherSize)
		{
			delete candidates;
			candidates = new vector<CandidateType>;
		}

		candidates->assign(myList.candidates->cbegin(), 
			myList.candidates->cend());
	}
	else
		cerr << "Attempting to self-assignment.";

	return *this;
}

void CandidateList::addCandidate(const CandidateType& myCandidate) const
{
	candidates->push_back(myCandidate);
}

int CandidateList::getWinner() const
{
	vector<CandidateType>::const_iterator iter 
		= candidates->cbegin();

	int largest = iter->getTotalVotes();
	int winnerSocSec = iter->getSocSec(); 
	++iter;

	while (iter != candidates->cend())
	{
		if (iter->getTotalVotes() > largest)
		{
			winnerSocSec = iter->getSocSec();
			largest = iter->getTotalVotes();
			iter++;
		}
		else
			iter++;
	}
	return winnerSocSec;
	
}

bool CandidateList::searchCandidate(int ssn) const
{
	vector<CandidateType>::const_iterator iter 
		= candidates->cbegin();

	return searchCandidate(ssn, iter);
}

bool CandidateList::isEmpty()
{
	return (candidates->empty());
}

void CandidateList::printCandidateName(int ssn) const
{
	vector<CandidateType>::const_iterator iter 
		= candidates->cbegin();

	if (searchCandidate(ssn, iter))
		iter->printName();

}

void CandidateList::printAllCandidates() const
{
	vector<CandidateType>::const_iterator iter
		= candidates->cbegin();

	while (iter != candidates->cend())
	{
		iter->printCandidateInfo();
		cout << endl;
		iter++;
	}
}

void CandidateList::printCandidateDivisionVotes(int ssn, int division) const
{
	vector<CandidateType>::const_iterator iter
		= candidates->cbegin();

	if (searchCandidate(ssn, iter))
	{
		cout << "    => Division " << division << ": "
			<< iter->getVotesByDivision(division)
			<< endl;
	}

}
void CandidateList::printCandidateTotalVotes(int ssn) const
{
	vector<CandidateType>::const_iterator iter 
		= candidates->cbegin();
	
	if (searchCandidate(ssn, iter))
	{
		cout << "    => Total votes: "
			<< iter->getTotalVotes() << endl;
	}
	
}

CandidateList::~CandidateList()
{
	delete candidates;
	candidates = nullptr;
}

bool CandidateList::searchCandidate(int ssn, 
	vector<CandidateType>::const_iterator &iter) const
{
	while (iter != candidates->cend())
	{
		if (iter->getSocSec() == ssn)  
			return true;
		else 
			++iter;
	}

	return false;
}

