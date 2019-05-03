/*
	EMV

	Garza, Erika
	Ky, Vy
	Nuon, Molita

	CS A250: Project 2
*/

#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <string>
#include <iostream>

using namespace std;

class PersonType
{
public:
	PersonType();
	PersonType(const string& newFirstName,
		const string& newLastName, int newSocSec);

	void setPersonInfo(const string& newFirstName,
		const string& newLastName, int newSocSec);

	string getFirstName() const;
	string getLastName() const;
	int getSocSec() const;

	void printName() const;
	void printPersonInfo() const;
	void printSocSec() const;

	~PersonType();

private:
	string firstName;
	string lastName;
	int ssn;
};
#endif