#include <stdio.h>

//Définition de la structure Friandise
struct Friandise{
	//3 attributs
	int prix;
	char* libelle;
	int quantite;
};


//Définition de la structure Compartiment 
struct Compartiment{
	//3 attributs
	int numero; //numéro du compartiment
	int valeur; // valeur de la piéce de monnaie
	int nombre; // nombre de piéces de monnaie
};


//Fonction pour vérifier si un type de friandise est toujours disponible
int estEnstock(struct Friandise f){
if (f.quantite>0)
	return 1;
	return 0;}

//Fonction pour mettre à jour le stock de friandises (dimunier le nombre de friandises
void MiseAjourStock(struct Friandise f){
	f.quantite-=1;}


//Fonction pour vérifier si on peut rendre une piéce de monnaie à partir d'un compartiment
int AutoriserRendrePiece(struct Compartiment c){
        if(c.nombre>0)
		return 1;
		return 0;}

//Fonction pour vérifier si on peut ajouter une piéce de monnaie à un compartiment
int AutoriserAjouterPiece(struct Compartiment c){
        if(c.nombre<50)
		return 1;
		return 0;}

//Fonction pour ajouter une piéce à un compartiment 
 void AjouterPiece(struct  Compartiment c){
            c.nombre+=1;}

//Méthode pour rendre une piéce de monnaie à partir d'un compartiment
void RendrePiece(struct  Compartiment c){
            c.nombre-=1;}


int main(){
return 0;
}
