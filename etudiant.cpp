#include "etudiant.h"

int etudiant::compteur = -1; 

etudiant::etudiant(string s,string s1):personne(s),ne(s1)
{
	niveau=0;
//	average=0;
//	grade=' ';
	algorithm_note=0;
	programation_note=0;
	maths_note=0;
	linux_note=0;
	compteur++;
}
etudiant::~etudiant()
{
	compteur--; 
}

int etudiant::nombreDeEtudiant() 
{ 
    return compteur; 
}

string etudiant::getne()
{
	return ne;
}
int etudiant::getniveau()
{
	return niveau;
}
etudiant::setniveau(int niveau)
{
	this->niveau=niveau;
}


float etudiant::getalgo()
{
	return algorithm_note;
}
float etudiant::getprogramation()
{
	return	programation_note;
}
float etudiant::getmaths()
{
	return	maths_note;
}
float etudiant::getlinux()
{
	return	linux_note;
}



etudiant::setalgo(float algorithm_note)
{
	this->algorithm_note=algorithm_note;
}
etudiant::setprogramation(float programation_note)
{
	this->programation_note=programation_note;
}
etudiant::setmaths(float maths_note)
{
	this->maths_note=maths_note;
}
etudiant::setlinux(float linux_note)
{
	this->linux_note=linux_note;
}

etudiant::setnoteGenerale(float noteGenerale)
{
	this->noteGenerale=noteGenerale;
}

float etudiant::getnoteGenerale()
{
	return noteGenerale;
}





