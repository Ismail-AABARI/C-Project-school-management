#ifndef PROMO_H
#define PROMO_H
#include<iostream>
#include<vector>
#include"etudiant.h"
using namespace std;

class promo
{
	private:
		vector<etudiant*> te;
	public:
		promo();
		~promo();
		ajouter(etudiant*);
		modifier(string);
		supprimer(string);
		int rechercher(string);
		lister();
		save();
		load();
		void login();
        void registration();
    	void forgot();
    	
};

#endif
