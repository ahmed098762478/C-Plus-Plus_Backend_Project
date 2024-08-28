#include<iostream>
#include<string.h>
#include<stdbool.h>
#include<conio.h>
#define  nbmax_etu  40  // le nombre maximal d'etudiant dans un module
#define  nbmax_mod  10  // le nombre maximale de modules

using namespace std;
	
	class professeur{
		private:
			int id_prof;
			string nom_p;
			string prenom_p;
			string adresse_p;
			int niveau;
			int salaire;
			string date_aff;
		public:
		professeur();
		professeur(int,string,string,string,int,int,string);
		professeur(professeur&);
		void saisir_p();
		int comparer_p(professeur);
		int getId_p(){
			return id_prof;
		}
		string getNom_p(){
		return nom_p ; }
		string getPrenom_p(){
		return prenom_p; }
		string getAdress_p(){
		return adresse_p; }
		int getNiveau(){
			return niveau; 
		}	
		int getSalaire(){
			return salaire;
		}
		string getDate_aff(){
			return date_aff;
		}
		void setId_p(int id){
			id_prof=id;
		}
		void setNom_p(string nom){
			nom_p=nom;
		}
		void setPrenom_p(string prenom){
			prenom_p=prenom;
		}
		void setAdresse_p(string adr){
			adresse_p=adr;
		}
		void setDate_aff(string date){
			date_aff=date;
		}
		void setNiveau(int nv){
			niveau=nv;
		}
		void setSalaire(int sal){
			salaire=sal;
		}
	}; 

class etudiant{
	private:
		int id_etu;
		string nom_etu;
		string prenom_etu;
		string adresse_etu;
		int age_etu;
		
	public: 
	    etudiant();
	    etudiant(int,string,string,string,int);
	    void saisir_etu();
	    void afficher_etu();
	    int comparer_etu(etudiant);
	    int getId_etu(){
	    	return id_etu;
		}
		string getNom_etu(){
			return nom_etu;
		}
		string getPrenom_etu(){
			return prenom_etu;
		}
		string getAdresse_etu(){
			return adresse_etu;
		}
		int getAge_etu(){
			return age_etu;
		}	
};	


class module{
	private:
		int code_mod;   
		string nom_mod;
		professeur p;       // le professeur qui enseigne ce module
		etudiant TabE[nbmax_etu];
		int nb_etu  ;              // le nombre d'etudiant dans un tableau lors de la saisie
		string date;
	public:
		module();
		module(int,string,professeur&,int,string);
		void saisir_mod();
	
		int exister_etu(etudiant);
		int ajouter_etu(etudiant);
		int modifier_etu(etudiant,string,string);
		void afficher_mod();
	    void modifier_p(professeur,string,string);
	    int comparer_mod(module m);

};

void affiche_menu();


int exister_mod(module m);

int tab_exister_etu(module m,etudiant e,int nb_etu,etudiant TabE[]);

int ajout_mod(module m,module mod[]);
int tab_ajout_etu(etudiant e,module m,int nb_etu,etudiant TabE[],module mod[]);
int supprimer(module m,module mod[]);


professeur::professeur(){
	id_prof=1;
	nom_p=prenom_p=adresse_p=date_aff="";
	niveau=salaire=0;
}

professeur::professeur(int id_prof,string nm,string pr,string adr,int sal,int nv,string date){
	this->id_prof=id_prof=1;
	nom_p=nm;
	prenom_p=pr;
	adresse_p=adr;
	salaire=sal;
	niveau=nv;
	date_aff=date;
}

professeur::professeur(professeur& p){
	id_prof=p.id_prof;
	nom_p=p.nom_p;
    prenom_p=p.prenom_p;
	adresse_p=p.adresse_p;
	niveau=p.niveau;
	 salaire=p.salaire;
	date_aff=p.date_aff;
}

void professeur::saisir_p(){
	cout<<"donner l'identifiant : "<<endl;
	cin>>id_prof;
	cout<<"donner le nom du prof : "<<endl;
	cin>>nom_p;
	cout<<"donner le prenom du professeur :"<<endl;
	cin>>prenom_p;
	cout<<"donner l'adresse du prof : "<<endl;
	cin>>adresse_p;
	cout<<"donner le salaire du prof : "<<endl;
	cin>>salaire;
	cout<<"donner le niveau du prof : "<<endl;
	cin>>niveau;
	cout<<"donner la date dd'affectation du prof : "<<endl;
	cin>>date_aff;
}

int professeur::comparer_p(professeur p){   // retorune 0 si le code est trouvé sinon elle retourne -1
if(p.id_prof>id_prof) return 1;
if(p.id_prof<id_prof) return-1;
else{
if(p.id_prof==id_prof) return 0; }
}

//les constructeurs et les fonctions membres de la classe etudiants

etudiant::etudiant(){
	id_etu=1;
	age_etu=0;
	nom_etu=prenom_etu=adresse_etu="";
}

etudiant::etudiant( int id,string nom,string prenom,string adr,int age){
	id_etu=id=1;
	nom_etu=nom;
	prenom_etu=prenom;
	adresse_etu=adr;
	age_etu=age;
}

void etudiant::saisir_etu(){
	cout<<"entrer l'identifiant :"<<endl;
	cin>>id_etu;
	cout<<"entrer le nom etudiant :"<<endl;
	cin>>nom_etu;
	cout<<"entrer le prenom etudiant :"<<endl;
	cin>>prenom_etu;
	cout<<"entrer l'adresse de l'etudiant :"<<endl;
	cin>>adresse_etu;
	cout<<"merci d'entrer l'age de letudiant : "<<endl;
	cin>>age_etu;
}

void etudiant::afficher_etu(){
	cout<<"le nom est :"<<nom_etu;
	cout<<"le prenom est :"<<prenom_etu;
	cout<<"l'adresse est :  :"<<adresse_etu;
	cout<<"l age est  :"<<age_etu;
}

int etudiant::comparer_etu(etudiant e){
	if(e.id_etu<id_etu) return -1;
	else {
		if(e.id_etu>id_etu) return 1;
		if(e.id_etu==id_etu) return 0;
	}       
}

// les constructeurs et les fonctions membres de la classe module

module::module(){
	code_mod=1;
	nom_mod="";
	date="";
	nb_etu=0;
	for(int i=0;i<nb_etu;i++){
		TabE[i].getId_etu();
		TabE[i].getPrenom_etu();
		TabE[i].getNom_etu();
		TabE[i].getAdresse_etu();
		TabE[i].getAge_etu();
	}
	p.setId_p(0);
	p.setNom_p("");
	p.setPrenom_p("");
	p.setAdresse_p("");
	p.setNiveau(0);
    p.setDate_aff("");	
}

module::module(int code,string nom,professeur& P,int nbe,string date):p(P){
	code_mod=code=1;
	nom_mod=nom;
	this->date=date;
	nb_etu=nbe;
    for(int i=0;i<nb_etu;i++){
    	TabE[i].getId_etu();
		TabE[i].getPrenom_etu();
		TabE[i].getNom_etu();
		TabE[i].getAdresse_etu();
		TabE[i].getAge_etu();
	}
}

void module::saisir_mod(){
	int i;
	cout<<"donner l'identifiant du module : "<<endl;
	cin>>code_mod;
	cout<<"donner le nom du module : "<<endl;
	cin>>nom_mod;
	cout<<"donner la date du premier lancement du module : "<<endl;
	cin>>date;
	cout<<"donner le nom du professeur qui enseigne ce module : "<<endl;
	// nom de prof !!!
	cout<<"donner le nombre d'etudiant de ce module : "<<endl;
	for( i=0;i<nb_etu;i++){
		TabE[i].saisir_etu();
	}
}


int module::exister_etu(etudiant e){
	bool trouve=false;
	int i;
	while(i<nb_etu && trouve==false){
		if(e.comparer_etu(TabE[i])==0)
		trouve=true;
		else i++;
	}
	if(trouve==true) return i ;     //etudiant existe dans la case i;
	else return -1;                 //etudiant introuvable
}

int module::ajouter_etu(etudiant e){
	int i;
	if(nb_etu==nbmax_etu) return -1;     //tableau d'etudiant saturé
	if(exister_etu(e)!=-1)  return -1;    // etudiant existe deja
	else{
		TabE[nb_etu]=e;
		nb_etu++;
	}
	return 1;
}

int module::modifier_etu(etudiant e,string new_nom,string new_prenom){
	int r=exister_etu(e);
	if(r==-1)  return -1;
	else{
		TabE[r].getNom_etu()=new_nom;
		TabE[r].getPrenom_etu()=new_prenom;
	}
	return 1;
}

void module::modifier_p(professeur p,string new_n,string new_p){
	p.getNom_p()=new_n;
	p.getPrenom_p()=new_p;
}
  
 int module::comparer_mod(module m){
	if(m.code_mod<code_mod)  return -1;
	if(m.code_mod>code_mod)   return 1;
	else if(m.code_mod==code_mod)   return 0;
}


void module::afficher_mod(){
	cout<<"le code est : "<<code_mod; 
	cout<<"le nom du module est :"<<nom_mod;
	cout<<"la date du lancement du module est :"<<date;
	cout<<"le nombre d'etudiant de ce module sont :"<<nb_etu;
	cout<<"le professeur qui enseigne est : "<<p.getNom_p()<<p.getPrenom_p();
} 



int exister_mod(module m){
	int size;
	int i;
	module mod[size];
	for(i=0;i<size;i++){
		if(m.comparer_mod(mod[i])==0)
		return i;
		else return -1;        //module n'existe pas
	}
}

int tab_exister_etu(module m,etudiant e,int nb_etu,etudiant TabE[]){
	int i;
	int j;
	int size;
	for(i=0;i<size;i++){
		if(exister_mod(m)==i) 
		for(j=0;j<nb_etu;j++){
			if(m.exister_etu(e)==j)
			return j;
				else return -1;
		} 
	}

}

int ajout_mod(module m,module mod[]){
	int size;
	if(size==nbmax_mod)  return -1;
	int r=exister_mod(m); 
	if(r!=-1) return -1;
	else{
		mod[size]=m;
		size++;
	}
	return 1;
}

int tab_ajout_etu(etudiant e,module m,int nb_etu,etudiant TabE[],module mod[]){
	int size;
	int r=tab_exister_etu(m,e,nb_etu,TabE);
	if(r!=-1) return -1;
	else{
		
		mod[size]=m;
		
		nb_etu++;
	}
	return 1;
}

int supprimer(module m,module mod[]){
	int size;
	int r=exister_mod(m);
	if(r==-1)  return -1 ; //module introuvable
	else{
		for(int i=0;i<size;i++){
			mod[i]=mod[i+1];
			size--;
			return 1;
		}
	}
}


void affiche_menu(){
	cout<<"********************************MENU"<<endl;
	cout<<"1       ************tester si un etudiant appartient a un module  : "<<endl;
	cout<<"2       *************ajouter un etudiant a un programme de module : "<<endl;
	cout<<"3       **************modifier un etudiant au programme d'un module : "<<endl;
	cout<<"4       **************modifier le nom du professeur d'un module : "<<endl;
	cout<<"5       **************tester si un module appartient a un tableau : "<<endl;
	cout<<"6       ***************tester si un etudiant appartient a un tableau :"<<endl;
	cout<<"7       ****************ajouter un module a un tableau : "<<endl;
	cout<<"8       ****************ajouter un etudiant a un tableau de module: "<<endl;
	cout<<"9       *****************supprimer un module d'un tableau : "<<endl;
}

module mod[nbmax_mod];
int size;
etudiant tabE[nbmax_etu];

main(){
	int r;
	int id_etu,id_mod,id_p;
	size=0;
	 int nb_etu=0;
    string etu_newn,etu_newp;
    string  p_newn,p_newp;
    int choix;
    professeur p;
    cout<<"entrer les donnees du professeur"<<endl;
    p.saisir_p();
    cout<<"verification du prof : "<<endl;
    cout<<"entrer le code du prof : "<<endl;
    cin>>id_p;
    r=p.comparer_p(p);
    if(r==1 || r==-1) cout<<"professeur inexistant"<<endl;  
    else if(r==0)  cout<<"professeur existe"<<endl;
    cout<<"entrer les infos du premier etudiant :"<<endl;
	etudiant e;
	e.saisir_etu();
	e.comparer_etu(e);
	cout<<"entrer les infos du premier module : "<<endl;
	module m;
	cout<<"entrer les element du premier module :"<<endl;
	m.saisir_mod();
    m.ajouter_etu(e);
	affiche_menu();
	cout<<"entrer votre choix : "<<endl;
	cin>>choix;
	while(choix!=0){
		switch(choix){
	 
			case 1:  //tester si un etudiant appartient a un module
			cout<<"entrer l'identifiant d etudiant : "<<endl; cin>>id_etu;
			 r=m.exister_etu(e);
			if(r==-1) cout<<"l'etudiant est introuvable"<<endl;
			else       cout<<"l'etudiant existe  "<<endl;
			break;
		
		case 2:  // ajouter un etudiant a un module
		    
		         e.saisir_etu();
		         r=m.ajouter_etu(e);
		         if(r==-1)  cout<<"l'etudiant est ajouté avec succes"<<endl;
		         else       cout<<"erreur d'ajout";
		
		
		
		break;
		
		case 3: //modifier un etudiant au programme d'un module
			
			cout<<"entrer l'identifiant de l'etudiant a modifier : "<<endl;
			cin>>id_etu;
			r=m.modifier_etu(e,etu_newn,etu_newp);
			if(r==-1) cout<<"erreur de modification"<<endl;
			else      cout<<"etudiant est modifié avec succes "<<endl;
			break;
		
		case 4:  // modifer le nom d'un professeur d'un module
			cout<<"entrer l'identifiant du professeur : "<<endl;
			cin>>id_p;
			m.modifier_p(p,p_newn,p_newp);		
	         cout<<"professeur est modifié avec succes ";
			break;
			
			
			case 5: //tester si un module appartient a un tableau de module 
				cout<<"entrer l'identifiant du module concerne : "<<endl;
				cin>>id_mod;
				r=exister_mod(m);
				if(r==1)     cout<<"le module existe dans le tableau de module "<<endl;
				else          cout<<"le module est introuvable"<<endl;
				break;
				
				
				
				case 6: //tester si un etudiant appartient a un tableau de module
					cout<<"veuiller entrer l'identifiant de l'etudiant : "<<endl;
					cin>>id_etu;
					r=tab_exister_etu(m,e,nb_etu,tabE);
					if(r==-1) cout<<"etudiant ne se trouve pas dans le tableau de module"<<endl;
					else      cout<<"etudiant trouvé "<<endl;
					break;
					
					case 7: // ajouter un module a un tableau de module
					    m.saisir_mod();
						r=ajout_mod(m,mod);   
						if(r==1)  cout<<"module ajouté avec succes"<<endl;
						else     cout<<"erreur d'ajout"<<endl;	
						break;
					
					case 8: // ajouter un etudiant a un tableau de module
						e.saisir_etu();
						r=tab_ajout_etu(e,m,nb_etu,tabE,mod);
						if(r==1)  cout<<"etudiant ajouté avec succes dans le tabelau de module"<<endl;
						else       cout<<"erreur d'ajout"<<endl;
						break;
						
						
						case 9: //supprimer un module d'un tableau de module
							cout<<"entrer l'identifiant du module a supprimer : "<<endl;
							cin>>id_mod;
							r=supprimer(m,mod);
							if(r==1)  cout<<"module supprimer avec succes"<<endl;
							else  cout<<"erreur de supression "<<endl;
							break;
				
		} //switch		
							
				if(choix!= 0)	affiche_menu();
			
				cout<<"entrer votre choix de nouveau : "<<endl;			
				cin>>choix;				
		
		 
 	} //while
                            
} 

