#ifndef PERSONNE_H
#define PERSONNE_H
#include<iostream>
using namespace std;

struct date
{
	int a,m,j;
};
class personne
{
	private:
	    const string cin;
	    int age;
	    string nom;
	    string prenom;
	    date dn;
	public:
		personne(string);
		~personne();
		string getcin();
		int getage();
		string getnom();
		string getprenom();
		date getdate();
		
		void setage(int);
		setnom(string);
		setprenom(string);
		setdate(date);
};

#endif
