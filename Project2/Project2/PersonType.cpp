/*
	EMV

	Garza, Erika
	Ky, Vy
	Nuon, Molita

	CS A250: Project 2
*/

#include "PersonType.h"

PersonType::PersonType()
{
	ssn = 0;
}

PersonType::PersonType(const string& newFirstName,
	const string& newLastName, int newSocSec)
{
	firstName = newFirstName;
	lastName = newLastName;
	ssn = newSocSec;
}

void PersonType::setPersonInfo(const string& newFirstName,
	const string& newLastName, int newSocSec)
{
	firstName = newFirstName;
	lastName = newLastName;
	ssn = newSocSec;
}

string PersonType::getFirstName() const
{
	return firstName;
}

string PersonType::getLastName() const
{
	return lastName;
}

int PersonType::getSocSec() const
{
	return ssn;
}

void PersonType::printName() const
{
	cout << lastName << ", " << firstName;
}

void PersonType::printPersonInfo() const
{
	printSocSec();
	cout << " " << firstName
		<< " " << lastName << endl;
}

void PersonType::printSocSec() const
{
	cout << ssn / 1000000 << "-"
		<< (ssn / 10000) % 100 << "-"
		<< ssn % 10000;
}

PersonType::~PersonType() {}