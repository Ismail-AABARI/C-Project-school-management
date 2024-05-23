#include"personne.h"
#include"etudiant.h"
#include"promo.h"
#include<conio.h>
int menu(int &choix)
{
	cout<<"1-gestion etudiant"<<endl<<"2-Operateur"<<endl<<"3-Nombre d'etudiant"<<endl<<"4-FIN DU PROGRAME "<<endl<<"veuillez saisir votre choix :";
	cin>>choix;
	system("cls");
}

int menu2(int &choix2)
{
	cout<<"1-ajouter etudiant"<<endl<<"2-modifier etudiant "<<endl<<"3-supprimer etudiant "<<endl<<"4-lister etudiant"<<endl<<"5-quitter"<<endl<<"veuillez saisir votre choix :";
	cin>>choix2;
	system("cls");
}

int menu3(int &choix3)
{
	cout<<"1-note inferieur \n 2-note superieur \n 3-different \n 4-egale \n 5-retour \n Veuiller saisir un choix :";
	cin>>choix3;
	system("cls");
}

int menuR(int &choixREGISTRE)
{
	system("color E");
	cout<<"_______________________________________________________________________________________________________________________\n\n\n";
	cout<<"\t                                                                                                             \n\n\n";
	cout<<"\t              CETTE PLATEFORME EST DU MINISTRE DE L'EDUCATION SPECIALEMENT POUR L'ADMINISTRATION SCOLAIRE     \n\n\n";
	cout<<"\t                                           MENU DE L'ECOLE                                                     \n\n\n";
	cout<<" ______________________________________________________________________________________________________________________\n\n\n";
	cout<<"\t|appuyez sur 1 pour vous connecter"<<endl<<"\t|appuyez sur 2 pour vous inscrire"<<endl<<"\t|appuyez sur 3 si vous avez oublie votre mot de passe"<<endl;
	cout<<"\t|appuyez sur 4 pour quitter";
	cout<<"\n\t\t\t Veuillez entrer votre choix :";
	cin>>choixREGISTRE;
	cout<<endl;
}

main()
{
	promo pr;
	int choixREGISTRE,choix,choix2;
	string e1,e2,s,nm,pn;
	float algo,prog,math,lnx;
	int ag,mois,annee,jour,niveau;
	date dn;
	float noteG;
	etudiant* e=new etudiant(e1,e2);
	pr.load();
	do
	{
	    
		system("cls");
		
		menuR(choixREGISTRE);
		switch(choixREGISTRE)
		{
			case 1:
			 pr.login();
			    do
	             {
	            system("cls");
		         menu(choix);
		        switch(choix)
		            {
			           case 1:
			 	           do
				           {
				           	  
				           	  system("cls");
					           menu2(choix2);
					           switch(choix2)
					           {
						        case 1:
							    do
							   {
								cout<<"veuillez saisir le cin de l'etudiant :";
							    cin>>e1;
							   }while(pr.rechercher(e1)!=-1);
							
							do
							{
							    cout<<"veuillez saisir le numero de l'etudiant :";
							    cin>>e2;	
							}while(pr.rechercher(e2)!=-1);
							
							e=new etudiant(e1,e2);
							
							cout<<"veuillez saisir le nom de l'etudiant :";
							cin>>nm;
							e->setnom(nm);
							cout<<"veuillez saisir le prenom de l'etudiant :";
							cin>>pn;
							e->setprenom(pn);
							
							cout<<"veuillez saisir le niveau de l'etudiant :";
							cin>>niveau;
							e->setniveau(niveau);
							cout<<"veuillez saisir l'age de l'etudiant :";
							cin>>ag;
							e->setage(ag);
							cout<<"veuillez saisir la date de naissance "<<endl;
		                    cout<<"veuillez saisir le jour :";
                            cin>>jour;
			   			
	                        cout<<"veuillez saisir le mois :";
		                    cin>>mois;
			   			
		                    cout<<"veuillez saisir l'annee :";
	                        cin>>annee;

		                    dn.j=jour;dn.m=mois;dn.a=annee;
                            e->setdate(dn);	
                            cout<<"veuillez saisir la note generale de l'etudiant :";
                            cin>>noteG;
                            e->setnoteGenerale(noteG);
                            cout<<"veuillez saisir la note de algorithme :";
                            cin>>algo;
                            e->setalgo(algo);
                            cout<<"veuillez saisir la note de programation :";
                            cin>>prog;
                            e->setprogramation(prog);
                            cout<<"veuillez saisir la note de mathematique :";
                            cin>>math;
                            e->setmaths(math);
                            cout<<"veuillez saisir la note de linux :";
                            cin>>lnx;
                            e->setlinux(lnx);
							pr.ajouter(e);
							system("cls");
						break;
						
						case 2:
							cout<<"veuillez saisir le cin a modifier :";
							cin>>s;
							pr.modifier(s);
						break;
						
						case 3:
							cout<<"veuillez saisir le cin a supprimer :";
							cin>>s;
							pr.supprimer(s);
						break;
						
						case 4:
							pr.lister();
						break;
						
						case 5:
							cout<<"fin"<<endl;
						break;
						default : break;
					}
					getch();
				}while(choix2!=5);
				
			break;
			
			case 2:
				////operator;
				do
				{
					menu3(choix);
					switch(choix)
					{
						case 1:
							cout<<"veuillez saisir la note de l'etudiant A pour savoir les notes superieurs :";
							cin>>noteG;
						break;
						
						case 2:
							cout<<"veuillez saisir la note de l'etudiant A pour savoir les notes superieurs:";
							cin>>noteG;
						break;
						
						case 3:

						break;
						
						case 4:
						break;
						
						case 5:
						break;
						default : break;
					}
				}while(choix);
			break;
			
			case 3:
				cout << "Il y a actuellement " << etudiant::nombreDeEtudiant() << " etudiants " << endl;
			break;
			
			case 4:
				cout<<"quitter";
			break;
			
			default : break;
		}
		getch();
	}while(choix!=4);
			break;
			
			case 2:
				pr.registration();
			break;
			
			case 3:
				pr.forgot();
			break;
			
			case 4:
				cout<<"\tEND OF PROGRAM THANKS";
			break;
			default : break;
		}
		getch();
	}while(choixREGISTRE!=4);
	pr.save();
	
}
