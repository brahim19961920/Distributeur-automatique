#include <stdio.h>

//Définition de la structure Friandise
struct Friandise{
	//3 attributs
	int prix;
	char* libelle;
	int quantite;
};

//Fonction pour vérifier si un type de friandise est toujours disponible
int estEnstock(struct Friandise f){
if (f.quantite>0)
	return 1;
	return 0;}

//Fonction pour mettre à jour le stock de friandises (dimunier le nombre de friandises
void MiseAjourStock(struct Friandise f){
	f.quantite-=1;}



int main(){
return 0;
}
