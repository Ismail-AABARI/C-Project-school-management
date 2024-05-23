#include "personne.h"

personne::personne(string s):cin(s)
{
	age=0;
	nom="";
	prenom="";
	dn.a=1900;
	dn.m=12;
	dn.j=31;
}
personne::~personne()
{
	
}
string personne::getcin()
{
	return cin;
}
int personne::getage()
{
	return age;
}

string personne::getnom()
{
	return nom;
}
string personne::getprenom()
{
	return prenom;
}
date personne::getdate()
{
	return dn;
}
		
void personne::setage(int age)
{
	this->age=age;
}
personne::setnom(string nom)
{
	this->nom=nom;
}
personne::setprenom(string prenom)
{
	this->prenom=prenom;
}
personne::setdate(date dn)
{
	this->dn=dn;
}
