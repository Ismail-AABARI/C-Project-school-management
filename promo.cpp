#include "promo.h"
#include"fstream"
#include<conio.h>
promo::promo()
{
	te.clear();
}
promo::~promo()
{
	te.clear();
}
promo::ajouter(etudiant* e)
{
	te.push_back(e);
}

promo::modifier(string s)
{
	int pos=rechercher(s);
	if(pos==-1)
	{
		cout<<"introuvable"<<endl;
	}
	else
	{
		string n,p;
		int a,mois,jour,annee;
		date dn;
		cout<<"veuillez saisir le nouvelle nom :";
		cin>>n;
		te[pos]->setnom(n);
		cout<<"veuillez saisir le nouvelle prenom :";
		cin>>p;
		te[pos]->setnom(p);
		cout<<"veuillez saisir le nouvelle age :";
		cin>>a;
		te[pos]->setage(a);
		cout<<"veuillez saisir la date de naissance :"<<endl;
		cout<<"veuillez saisir le nouvel jour :";
        cin>>jour;
			   			
		cout<<"veuillez saisir le nouvel mois :";
		cin>>mois;
			   			
		cout<<"veuillez saisir la nouvelle annee :";
		cin>>annee;

		dn.j=jour;dn.m=mois;dn.a=annee;
        te[pos]->setdate(dn);
	    system("cls");	
	}
	
}
promo::supprimer(string s)
{
	int pos=rechercher(s);
	if(pos==-1)
	{
		cout<<"introuvable"<<endl;
	}
	else
	{
		te.erase(te.begin()+pos);
	}
}
int promo::rechercher(string s)
{
	for(int i=0;i<te.size();i++)
	{
		if(s==te[i]->getcin())
		{
			return i;
		}
	}
	return -1;
}


promo::lister()
{
	for(int i=0;i<te.size();i++)
	{
		system("color E");
		cout<<"\t______________________________________________________\n\n\n";
		cout<<"\t              VOICI L'ETUDIANT NUMERO"   <<i+1<<endl<<"\n\n\n";
		cout<<"voici le cin "<<te[i]->getcin()<<endl;
		cout<<"voici l'age "<<te[i]->getage()<<endl;
		cout<<"voici le nom "<<te[i]->getnom()<<endl;
		cout<<"voici le prenom "<<te[i]->getprenom()<<endl;
		cout<<"voici le niveau "<<te[i]->getniveau()<<endl;
		cout<<"le jour de naissance est :"<<te[i]->getdate().j<<endl;	
		cout<<"le mois de naissance est :"<<te[i]->getdate().m<<endl;	
		cout<<"l'annee de naissance est :"<<te[i]->getdate().a<<endl;
		cout<<"voici la note generale de l'etudiant:"<<te[i]->getnoteGenerale()<<endl;
		cout<<"\t->voici la note de l'algorithme :"<<te[i]->getalgo()<<endl;
		cout<<"\t->voici la note de la programation :"<<te[i]->getprogramation()<<endl;
		cout<<"\t->voici la note de maths :"<<te[i]->getmaths()<<endl;
		cout<<"\t->voici la note de linux :"<<te[i]->getlinux()<<endl;
		cout<<"\t________________________________________________________\n\n\n";
	}
}

promo::load()
{
    ifstream fpromo("promo.txt", ios::in);
    if (fpromo.is_open())
    {
        te.clear();
        string cin, nom, prenom;
        int age, niveau;
        float noteGenerale, algorithm_note, programation_note, maths_note, linux_note;
        date dn;
        while (fpromo >> cin >> nom)
        {
            etudiant *e = new etudiant(cin, nom);
            if (fpromo >> prenom >> age >> niveau >> dn.a >> dn.m >> dn.j >> noteGenerale >> algorithm_note >> programation_note >> maths_note >> linux_note)
            {
                e->setprenom(prenom);
                e->setage(age);
                e->setniveau(niveau);
                e->setdate(dn);
                e->setnoteGenerale(noteGenerale);
                e->setalgo(algorithm_note);
                e->setprogramation(programation_note);
                e->setmaths(maths_note);
                e->setlinux(linux_note);
                te.push_back(e);
            }
            else
            {
                cout << "Erreur lors de la lecture des informations de l'étudiant dans le fichier" << endl;
                delete e;
            }
        }
        fpromo.close();
    }
    else
    {
        cout << "Impossible d'ouvrir le fichier promo.txt" << endl;
    }
}

//promo::load()
//{
//	
//	ifstream fpromo("promo.txt",ios::in);
//	{
//	
//	     if(fpromo)
//	      {
//		      te.clear();
//		      while(!fpromo.eof())
//		      {
//		        string ne,prenom,cin,nom;
//	            int age,niveau;
//				float noteGenerale,algorithm_note,programation_note,maths_note,linux_note;
//	            int taille;
//	            date dn;
//		        fpromo>>cin;
//	            fpromo>>ne;
//				etudiant *e=new etudiant(cin,ne);
//		        fpromo>>nom;
//	            fpromo>>prenom;
//		        fpromo>>age;
//		        fpromo>>niveau;
//		        fpromo>>dn.a;
//		        fpromo>>dn.m;
//		        fpromo>>dn.j;
//		        fpromo>>noteGenerale;
//		        fpromo>>algorithm_note;
//		        fpromo>>programation_note;
//				fpromo>>maths_note;
//				fpromo>>linux_note;
//		        e->setnom(nom);
//		        e->setprenom(prenom);
//				e->setage(age);
//		        e->setniveau(niveau);
//		        e->setdate(dn);
//		        e->setnoteGenerale(noteGenerale);
//				e->setalgo(algorithm_note);
//				e->setprogramation(programation_note);
//				e->setmaths(maths_note);
//				e->setlinux(linux_note);
//		        te.push_back(e);
//		   }
//	 }
//	}
//	
//	fpromo.close();
//}

promo::save()
{
	ofstream fpromo("promo.txt", ios::out | ios::trunc);
	if(fpromo)
	{
	  fpromo<<te.size();
	  for(int i=0;i<te.size();i++)
	  {
		fpromo<<"voici le cin "<<te[i]->getcin()<<" ";
		fpromo<<"voici le cin "<<te[i]->getne()<<" ";
		fpromo<<"voici l'age "<<te[i]->getage()<<" ";
		fpromo<<"voici le nom "<<te[i]->getnom()<<" ";
		fpromo<<"voici le prenom "<<te[i]->getprenom()<<" ";
		fpromo<<"voici le niveau "<<te[i]->getniveau()<<endl;
		fpromo<<"le jour de naissance est :"<<te[i]->getdate().j<<endl;	
		fpromo<<"le mois de naissance est :"<<te[i]->getdate().m<<endl;	
		fpromo<<"l'annee de naissance est :"<<te[i]->getdate().a<<endl;
		fpromo<<"voici la note generale de l'etudiant:"<<te[i]->getnoteGenerale()<<endl;
		fpromo<<"voici la note de l'algorithme :"<<te[i]->getalgo()<<endl;
		fpromo<<"voici la note de la programation :"<<te[i]->getprogramation()<<endl;
		fpromo<<"voici la note de maths :"<<te[i]->getmaths()<<endl;
		fpromo<<"voici la note de linux :"<<te[i]->getlinux()<<endl;
	  }
	  fpromo.close();
	}
	else
	{
		cout<<"fichier n'ouvre pas";
	}
	
	
}


void promo::login()
{
	int cp=0;
	string userID,password,id,pass;
	system("cls");
	cout<<"please entre the username and password"<<endl;
	cout<<"username :";
	cin>>userID;
	cout<<"password :";
	cin>>password;
	
	ifstream ListeMP("motpasse.txt");
	while(!ListeMP.eof())
	{
		ListeMP>>id>>pass;
		if((id == userID) && (pass == password))
		{
			cp=1;
			system("cls");
		}
	}
	
	if(cp==1)
	{
		cout<<userID<<" your login is succesfully"<<endl;
		getch();
	}
	else
	{
		cout<<"login error";
				getch();
	}
	ListeMP.close();
}

void promo::registration()
{
	string ruserID,rpassword,rid,rpasse;
	system("cls");
	cout<<"enter the username :";
	cin>>ruserID;
	cout<<"entre the password :";
	cin>>rpassword;
	
	ofstream f1("motpasse.txt",ios::app);
	f1<<ruserID<<" "<<rpassword<<endl;
	system("cls");
	cout<<"registration is successfull ";
	getch();
}

void promo::forgot()
{
	int option;
	system("cls");
	cout<<"\t\t\t you forgot the password ? no worries \n "<<endl;
	cout<<"press 1 to search your id by username "<<endl;
	cout<<"press 2 to back to main menu "<<endl;
	cout<<"entre your choice :";
	cin>>option;
	switch(option)
	{
		case 1:
			{
			int cp=0;
			string suserID,sid,spass;
			cout<<"\n\t\t enter the username which your remebered :";
			cin>>suserID;
			
			ifstream f2("motpasse.txt");
			while(f2>>sid>>spass)
			{
				if(sid == suserID)
				{
					cp=1;
				}
			}
			f2.close();
			if(cp==1)
			{
				cout<<"your account is found "<<endl;
				cout<<"your password is "<<spass;
			}
			else
			{
				cout<<"sorry your account is not found";
			}
		  }
		break;
		
		case 2:
			{
			}
		break;
		default : cout<<"wrong choice , please try again "<<endl;
		forgot();
	}
}
    
    
    

      
     
    

