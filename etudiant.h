#ifndef ETUDIANT_H
#define ETUDIANT_H
#include<iostream>
#include"personne.h"
using namespace std;
class etudiant : public personne
{
	private:
		const string ne;
		int niveau;
		static int compteur; 
		float algorithm_note;
		float programation_note;
		float maths_note;
		float linux_note;
		float noteGenerale;
	public:
		etudiant(string,string);
		~etudiant();
		static int nombreDeEtudiant(); 
		string getne();
		int getniveau();
		setniveau(int);
		float getnoteGenerale();
		float getalgo();
		float getprogramation();
		float getmaths();
		float getlinux();
		setnoteGenerale(float);
		setalgo(float);
		setprogramation(float);
		setmaths(float);
		setlinux(float);

};

#endif
